// SPDX-License-Identifier: GPL-3.0-or-later

#include "Version.hpp"
#include <QJsonArray>

Version::Version() {}

Version::Version(const QJsonDocument &doc)
	: client(doc["downloads"]["client"].toObject()),
	  server(doc["downloads"]["server"].toObject()) {
	for (const QJsonValue &library : doc["libraries"].toArray())
		libraries.append(Library(library.toObject()));
}