// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "Instance.hpp"
#include <QDir>
#include <QList>
#include <QProcess>
#include <QQmlEngine>
#include <memory>

class Launcher final : public QObject {
	Q_OBJECT

public:
	explicit Launcher(QObject *parent, QQmlEngine *engine);

	Q_INVOKABLE void launch();

private:
	QQmlEngine *engine;
	const QDir data;
	const QDir versions;
	const QDir libraries;
	QList<Instance *> instances;

	QStringList generateLaunchArguments(const QString &versionId);
};
