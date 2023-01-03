// SPDX-License-Identifier: GPL-3.0-or-later

#include <QDebug>

#include "Launcher.hpp"
#include "piston/VersionManifest.hpp"

Launcher::Launcher(QObject *parent) : QObject(parent) {}

void Launcher::launch() {
	const QStringList args = generateLaunchArguments();

	Instance *instance = new Instance(this);
	instance->start(args.at(0),
					QList(args.begin() + 1, args.begin() + args.length()));
	instances.append(instance);
}

QStringList Launcher::generateLaunchArguments() {

	return QStringList{"java", "-jar", "my_jar.jar"};
}