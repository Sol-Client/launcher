// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QList>
#include <QProcess>

#include "Instance.hpp"

class Launcher final : public QObject {
	Q_OBJECT

public:
	explicit Launcher(QObject *parent = nullptr);

	Q_INVOKABLE void launch();

private:
	QList<Instance *> instances;

	QStringList generateLaunchArguments();
};
