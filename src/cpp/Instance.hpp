// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QProcess>

/// Represents an instance of a running game.
class Instance final : public QProcess {
	Q_OBJECT

public:
	explicit Instance(QObject *parent = nullptr);

	virtual ~Instance() override;

	/**
	 * Detaches the process, allowing it to continue running after the death of the launcher.
	 * Called by the destructor.
	 */
	void detach();

private:
	enum class OutputType { STDOUT, STDERR };

	void onOutput(QByteArray data, OutputType type);
};