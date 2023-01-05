// SPDX-License-Identifier: GPL-3.0-or-later

#include "Library.hpp"

Library::Library(const QJsonObject &object) {
	name = object["name"].toString();

	const QJsonObject downloads = object["downloads"].toObject();

	for (QJsonObject::ConstIterator item = downloads.begin();
		 item != downloads.end(); item++)
		files[item.key()] = File(item.value().toObject());

	computeRules();
}

void Library::computeRules() {
	// TODO
	matchesRules = true;
}