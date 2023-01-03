// SPDX-License-Identifier: GPL-3.0-or-later

#include <QDebug>

#include "LaunchError.hpp"
#include "Launcher.hpp"
#include "piston/VersionManifest.hpp"

Launcher::Launcher(QObject *parent)
	: QObject(parent), data("."), versions(data.filePath("versions")) {
	if (!data.exists() && !data.mkpath("."))
		throw tr("Could not make the data directory.");
}

void Launcher::launch() {
	const QStringList args = generateLaunchArguments("1.8.9");

	const auto instance = new Instance(this);
	instance->start(args.at(0),
					QList(args.begin() + 1, args.begin() + args.length()));
	instances.append(instance);
}

QStringList Launcher::generateLaunchArguments(const QString &versionId) {
	// version folder

	if (versionId.contains('/') || versionId.contains(QDir::separator()))
		throw LaunchError{
			tr("Version identifier may not contain path separator.")};

	const QDir versionDir(versions.filePath(versionId));
	if (!versionDir.exists() && !versionDir.mkpath("."))
		throw LaunchError{tr("Could not make version directory.")};

	// version.json

	const QFileInfo versionJson(versionDir, versionId + ".json");

	if (versionJson.exists() && !versionJson.isFile())
		throw LaunchError{tr("%1 is not a file.").arg(versionJson.path())};

	QFile versionJsonFile(versionJson.filePath());

	VersionManifest manifest = VersionManifest::fetch();
	bool online = !manifest.isNull();
	Version version;

	if (online)
		version = manifest.getVersion(versionId).fetchAndSave(versionJsonFile);
	else if (versionJson.exists()) {
		// try to reuse previously downloaded version
		versionJsonFile.open(QFile::ReadOnly);
		version = Version(QJsonDocument::fromJson(versionJsonFile.readAll()));
		versionJsonFile.close();
	}

	// version.jar

	const QFileInfo versionJar(versionDir, versionId + ".jar");

	if (versionJar.exists() && !versionJar.isFile())
		throw LaunchError{tr("%1 is not a file.").arg(versionJar.path())};

	if (!version.getClient().download(versionJar.absoluteFilePath()))
		throw LaunchError{tr("Failed to download client jar.")};

	return QStringList{"java", "-jar", "my_jar.jar"};
}