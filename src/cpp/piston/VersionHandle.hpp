// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "MetaHandle.hpp"
#include "Version.hpp"
#include <QJsonObject>

class VersionHandle final : public MetaHandle<Version> {
public:
	VersionHandle(const QJsonObject &object);

	inline const QString &getId() const { return id; }

private:
	QString id;
};