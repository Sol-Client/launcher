// SPDX-License-Identifier: GPL-3.0-or-later

#include "Process.hpp"

Process::~Process() {
	detach();
}

void Process::detach() {
	setProcessState(ProcessState::NotRunning);
}