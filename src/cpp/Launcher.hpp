// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "Instance.hpp"
#include <QDir>
#include <QList>
#include <QProcess>
#include <memory>

class Launcher final : public QObject {
	Q_OBJECT

public:
	explicit Launcher(QObject *parent = nullptr);

	Q_INVOKABLE void launch();

private:
	const QDir data;
	const QDir versions;
	QList<Instance *> instances;

	QStringList generateLaunchArguments(const QString &versionId);
};
