// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "File.hpp"
#include <QJsonDocument>

class Version final {
public:
	Version();
	Version(const QJsonDocument &doc);

	inline const File &getClient() const { return client; }
	inline const File &getServer() const { return server; }

private:
	File client, server;
};