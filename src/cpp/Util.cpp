// SPDX-License-Identifier: GPL-3.0-or-later

#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "Util.hpp"

static QNetworkAccessManager manager;

QByteArray Util::readUrl(const QUrl &url) {
	QEventLoop loop;

	const QNetworkRequest request(url);
	QNetworkReply *reply = manager.get(request);

	if (reply->waitForBytesWritten(30000))
		return QByteArray();

	QObject::connect(reply, &QNetworkReply::finished, [&] { loop.quit(); });
	loop.exec();
	reply->deleteLater();

	return reply->readAll();
}

bool Util::downloadUrlToFile(const QUrl &url, QFile &file) {
	QEventLoop loop;

	if (!file.open(QFile::WriteOnly))
		return false;

	const QNetworkRequest request(url);
	const std::unique_ptr<QNetworkReply> reply(manager.get(request));

	if (reply->waitForBytesWritten(30000))
		return false;

	bool error = false;

	QObject::connect(reply.get(), &QNetworkReply::finished, [&] {
		if (loop.isRunning())
			loop.quit();
	});
	QObject::connect(reply.get(), &QNetworkReply::downloadProgress, [&] {
		if (reply->isOpen())
			file.write(reply->readAll());
	});
	QObject::connect(reply.get(), &QNetworkReply::errorOccurred, [&] {
		loop.quit();
		reply->close();
		file.remove();
		error = true;
	});
	loop.exec();

	return !error;
}
