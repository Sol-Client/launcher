// SPDX-License-Identifier: GPL-3.0-or-later

#include "Version.hpp"

Version::Version() {}

Version::Version(const QJsonDocument &doc)
	: client(doc["downloads"]["client"].toObject()),
	  server(doc["downloads"]["server"].toObject()) {}