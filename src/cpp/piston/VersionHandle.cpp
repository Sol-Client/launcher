// SPDX-License-Identifier: GPL-3.0-or-later

#include "VersionHandle.hpp"

VersionHandle::VersionHandle(const QJsonObject &object)
	: MetaHandle<Version>(object["url"].toString()),
	  id(object["id"].toString()) {}