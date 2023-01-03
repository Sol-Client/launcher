// SPDX-License-Identifier: GPL-3.0-or-later

#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "Util.hpp"

QString Util::readUrlToString(const QUrl &url) {
	static QEventLoop loop;
	static QNetworkAccessManager manager;

	const QNetworkRequest request(url);
	const std::unique_ptr<QNetworkReply> response(manager.get(request));

	response->waitForBytesWritten(30000);
	QObject::connect(response.get(), &QNetworkReply::finished,
					 [] { loop.quit(); });

	loop.exec();
	return response->readAll();
}
