/*
 * Sol Client Launcher - recode of Sol Client's custom launcher.
 * Copyright (C) 2022  TheKodeToad and contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "Launcher.hpp"

#include <QProcess>

QStringList Launcher::generateLaunchArguments() {
	QStringList result;

	result.emplace_back("java");
	result.emplace_back("-jar");
	result.emplace_back("my_jar.jar");

	return result;
}

Launcher::Code Launcher::launch() {
	const QStringList args = generateLaunchArguments();

	QProcess process;
	process.start(args[0], args.sliced(1, args.length() - 1));

	if(!process.waitForStarted()) {
		return START_TIMEOUT;
	}

	return OK;
}