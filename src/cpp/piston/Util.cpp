// SPDX-License-Identifier: GPL-3.0-or-later

#include "Util.hpp"
#include "MetaParseException.hpp"

QJsonObject Util::castToObj(const QJsonValue &value) {
	if (!value.isObject())
		throw MetaParseException("expected json object");

	return value.toObject();
}


QJsonArray Util::castToArray(const QJsonValue &value) {
	if (!value.isArray())
		throw MetaParseException("expected json array");

	return value.toArray();
}