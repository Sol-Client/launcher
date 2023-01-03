// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "Util.hpp"
#include <QJsonDocument>
#include <QUrl>

template <typename T> class MetaHandle {
public:
	T fetch() const { return T(fetchDoc()); }

	T fetchAndSave(QFile &file) const {
		const QByteArray &bytes = fetchBytes();

		if (file.open(QFile::WriteOnly)) {
			file.write(bytes);
			file.close();
		}

		return T(QJsonDocument::fromJson(bytes));
	};

	MetaHandle(const QUrl &url) : url(url) {}

	virtual ~MetaHandle() {}

	inline const QUrl &getUrl() { return url; }

protected:
	QUrl url;

	virtual QByteArray fetchBytes() const { return Util::readUrl(url); }

	QJsonDocument fetchDoc() const { return QJsonDocument::fromJson(fetchBytes()); }
};