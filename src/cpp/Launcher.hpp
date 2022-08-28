// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QStringList>
#include <qobjectdefs.h>

#include "Process.hpp"

class Launcher final : public QObject {
	Q_OBJECT

private:
	Process *process;

	QStringList generateLaunchArguments();

public:
	using QObject::QObject;

	/// Represents success or failure on launch.
	enum Code {
		OK,
		/// Waiting for the process to start timed out (30 seconds).
		START_TIMEOUT
	};

	Q_ENUM(Code)

public slots:
	Code launch();

};
