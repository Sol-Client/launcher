// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QJsonObject>
#include <QString>
#include <QUrl>

class File final {
public:
	File();
	File(const QJsonObject &object);

	inline const QString &getSha1() const { return sha1; }
	inline const QUrl &getUrl() const { return url; }

	inline bool isNull() const { return sha1.isNull(); }

	bool download(const QString &path) const;

private:
	QString sha1;
	QUrl url;
	QString path;
};