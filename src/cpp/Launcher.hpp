// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QList>
#include <QProcess>

#include "Instance.hpp"

class Launcher final : public QObject {
	Q_OBJECT

private:
	QList<Instance *> *instances;

	QStringList generateLaunchArguments();

public:
	explicit Launcher(QObject *parent = nullptr);

	~Launcher();

	Q_INVOKABLE void launch();

};
