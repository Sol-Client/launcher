// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "File.hpp"
#include "Library.hpp"
#include <QJsonDocument>

class Version final {
public:
	Version();
	Version(const QJsonDocument &doc);

	inline const File &getClient() const { return client; }
	inline const File &getServer() const { return server; }

	inline const QList<Library> getLibraries() const { return libraries; }

private:
	File client, server;

	QList<Library> libraries;
};