// SPDX-License-Identifier: GPL-3.0-or-later

#include <QDebug>

#include "Instance.hpp"

Instance::Instance(QObject *parent) : QProcess(parent) {
	connect(this, &QProcess::readyReadStandardOutput, [this]() {
		onOutput(readAllStandardOutput(), OutputType::STDOUT);
	});

	connect(this, &QProcess::readyReadStandardError,
			[this]() { onOutput(readAllStandardError(), OutputType::STDERR); });
}

Instance::~Instance() { detach(); }

void Instance::detach() { setProcessState(NotRunning); }

void Instance::onOutput(QByteArray data, OutputType type) {
	const char *typeStr;

	switch (type) {
	case OutputType::STDOUT:
		typeStr = "STDOUT";
		break;
	case OutputType::STDERR:
		typeStr = "STDERR";
		break;
	default:
		qWarning() << "Unknown output type";
		typeStr = "UNKNOWN";
		break;
	}

	// accumulated output is unlikely to be used in Minecraft due to log4j
	if (data.endsWith('\n'))
		data.truncate(data.size() - 1);

	if (data.isEmpty())
		return;

	qInfo().nospace().noquote() << "[" << typeStr << "]"
								<< " " << data;
}
