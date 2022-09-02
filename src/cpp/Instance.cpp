// SPDX-License-Identifier: GPL-3.0-or-later

#include <QDebug>

#include "Instance.hpp"

void Instance::onOutput(QByteArray data, OutputType type) {
	const char *typeStr;

	switch(type) {
		case STDOUT:
			typeStr = "STDOUT";
			break;
		case STDERR:
			typeStr = "STDERR";
			break;
		default:
			qWarning() << "Unknown output type" << type;
			break;
	};

	if(data.endsWith('\n')) {
		data.truncate(data.size() - 1);
	}

	qInfo().nospace().noquote() << "[" << typeStr << "]" << " " << data;
}

Instance::Instance(QObject *parent) : QProcess(parent) {
	connect(this, &QProcess::readyReadStandardOutput, [this]() {
		onOutput(readAllStandardOutput(), STDOUT);
	});

	connect(this, &QProcess::readyReadStandardError, [this]() {
		onOutput(readAllStandardError(), STDERR);
	});
}

Instance::~Instance() {
	detach();
}

void Instance::detach() {
	setProcessState(NotRunning);
}