// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "../Util.hpp"
#include <QJsonDocument>
#include <QUrl>

template <typename T> class MetaHandle {
public:
	virtual T fetch() const { return T(fetchDoc()); }

	MetaHandle(const QUrl &url) : url(url) {}

	virtual ~MetaHandle() {}

	inline const QUrl &getUrl() { return url; }

protected:
	QUrl url;

	QJsonDocument fetchDoc() const {
		return QJsonDocument::fromJson(Util::readUrlToString(url).toUtf8());
	}
};