// SPDX-License-Identifier: GPL-3.0-or-later

#include "Launcher.hpp"

Launcher::Launcher(QObject *parent) : QObject(parent) {
	instances = new QList<Instance *>;
}

Launcher::~Launcher() {
	delete instances;
}

QStringList Launcher::generateLaunchArguments() {
	return {"java", "-jar", "my_jar.jar"};
}

void Launcher::launch() {
	const QStringList args = generateLaunchArguments();

	Instance *instance = new Instance(this);
	instance->start(args.at(0), QList(args.begin() + 1, args.begin() + args.length()));
	instances->append(instance);
}