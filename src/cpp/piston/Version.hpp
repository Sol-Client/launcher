// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QJsonDocument>

class Version final {
public:
	inline Version(const QJsonDocument &doc) { doc.isObject(); }
};