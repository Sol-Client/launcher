// SPDX-License-Identifier: GPL-3.0-or-later

#include "VersionManifest.hpp"
#include "Constants.hpp"
#include "Util.hpp"
#include "VersionManifest.hpp"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

VersionManifest VersionManifest::fetch() {
	const QByteArray &result = Util::readUrl(VERSION_MANIFEST_URL);

	if (result.isNull())
		return VersionManifest();

	return VersionManifest(QJsonDocument::fromJson(result));
}

VersionManifest::VersionManifest() {}

VersionManifest::VersionManifest(const QJsonDocument &doc) {
	const QJsonArray versions = doc["versions"].toArray();

	for (const QJsonValue &version : versions)
		this->versions.append(VersionHandle(version.toObject()));
}

const VersionHandle &VersionManifest::getVersion(const QString &id) const {
	return *std::find_if(
		versions.begin(), versions.end(),
		[id](const VersionHandle &version) { return version.getId() == id; });
}