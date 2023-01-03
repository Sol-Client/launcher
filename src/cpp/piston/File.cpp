// SPDX-License-Identifier: GPL-3.0-or-later

#include "File.hpp"
#include "Util.hpp"
#include <QCryptographicHash>
#include <QDir>
#include <QFile>

File::File() {}

File::File(const QJsonObject &object)
	: sha1(object["sha1"].toString()), url(object["url"].toString()),
	  path(object["path"].toString()) {}

static bool checkHash(QFile &file, const QString &expected) {
	QCryptographicHash hash(QCryptographicHash::Algorithm::Sha1);

	if (!file.open(QFile::ReadOnly))
		return false;

	if (!hash.addData(&file))
		return false;

	return QString::compare(hash.result().toHex(), expected,
							Qt::CaseInsensitive) == 0;
}

bool File::download(const QString &path) const {
	// try to prevent path traversal
	if (const QString cleaned =
			QDir::cleanPath(path + QDir::separator() + this->path);
		!cleaned.startsWith(path))
		return false;

	const QFileInfo info(path);

	if (info.exists()) {
		if (!info.isFile())
			return false;

		QFile existingFile(path);

		if (!checkHash(existingFile, sha1))
			existingFile.remove();
		else
			return true;
	}

	QFile file(path);
	bool result = Util::downloadUrlToFile(url, file);
	if (file.isOpen())
		file.close();

	if (!result)
		return false;

	if (!checkHash(file, sha1))
		return false;

	return true;
}