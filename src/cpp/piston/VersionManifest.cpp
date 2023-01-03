// SPDX-License-Identifier: GPL-3.0-or-later

#include "VersionManifest.hpp"
#include "../Util.hpp"
#include "Constants.hpp"
#include "MetaParseException.hpp"
#include "Util.hpp"
#include "VersionManifest.hpp"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

VersionManifest VersionManifest::fetch() {
	return VersionManifest(QJsonDocument::fromJson(
		Util::readUrlToString(VERSION_MANIFEST_URL).toUtf8()));
}

VersionManifest::VersionManifest(const QJsonDocument &doc)
	: versions(std::make_unique<QList<VersionHandle>>()) {
	if (!doc.isObject())
		throw MetaParseException("expected version manifest to be an object");

	const QJsonObject obj = doc.object();
	const QJsonArray versions = Util::castToArray(obj["versions"]);

	for (const QJsonValue &version : versions)
		this->versions->append(VersionHandle(Util::castToObj(version)));
}

const VersionHandle &VersionManifest::getVersion(const QString &id) const {
	return *std::find_if(
		versions->begin(), versions->end(),
		[id](VersionHandle &version) { return version.getId() == id; });
}