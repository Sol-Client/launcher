// SPDX-License-Identifier: GPL-3.0-or-later

#include <QDebug>

#include "Launcher.hpp"

QStringList Launcher::generateLaunchArguments() {
	return {"java", "-jar", "my_jar.jar"};
}

Launcher::Code Launcher::launch() {
	const QStringList args = generateLaunchArguments();

	process = new Process(this);
	process->start(args[0], args.sliced(1, args.length() - 1));

	if(!process->waitForStarted()) {
		return START_TIMEOUT;
	}

	connect(process, &QProcess::readyReadStandardOutput, [this]() {
		qDebug() << process->readAllStandardOutput() << '\n';
	});

	connect(process, &QProcess::readyReadStandardError, [this]() {
		qDebug() << process->readAllStandardError() << '\n';
	});

	qDebug() << "Process exited with code " << process->exitCode() << '\n';

	return OK;
}