// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QProcess>

/// Reprents an instance of a running game.
class Instance : public QProcess {
	Q_OBJECT

private:
	enum OutputType {
		STDOUT,
		STDERR
	};

	void onOutput(QByteArray data, OutputType type);

public:
	explicit Instance(QObject *parent = nullptr);

	virtual ~Instance() override;

	void detach();

};