// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QProcess>

class Process : public QProcess {

public:
	using QProcess::QProcess;

	virtual ~Process() override;

	void detach();

};