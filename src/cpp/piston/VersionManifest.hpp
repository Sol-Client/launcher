// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "VersionHandle.hpp"
#include <QList>
#include <memory>

class VersionManifest final {
public:
	static VersionManifest fetch();

	VersionManifest(const QJsonDocument &doc);

	inline const QList<VersionHandle> &getVersions() const { return versions; }

	const VersionHandle &getVersion(const QString &id) const;

private:
	QList<VersionHandle> versions;
};