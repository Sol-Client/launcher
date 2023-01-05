// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "File.hpp"
#include <QJsonObject>
#include <QString>

class Library {
public:
	Library(const QJsonObject &object);

	inline const File getFile(const QString &id) const { return files[id]; }
	inline bool hasFile(const QString &id) const { return files.contains(id); }
	inline const QString &getName() const { return name; };
	inline bool isApplicable() const { return matchesRules; }

private:
	void computeRules();

private:
	QMap<QString, File> files;
	QString name;
	bool matchesRules;
};