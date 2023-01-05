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
	if (expected.isEmpty())
		return true;

	QCryptographicHash hash(QCryptographicHash::Algorithm::Sha1);

	if (!file.open(QFile::ReadOnly))
		return false;

	if (!hash.addData(&file))
		return false;

	return QString::compare(hash.result().toHex(), expected,
							Qt::CaseInsensitive) == 0;
}

QString File::download(const QString &path) const {
	// try to prevent path traversal
	const QString fullPath =
		QDir::cleanPath(path + QDir::separator() + this->path);
	if (!fullPath.startsWith(QDir::cleanPath(path)))
		return QString();

	const QFileInfo info(fullPath);

	if (info.exists()) {
		if (!info.isFile())
			return QString();

		QFile existingFile(path);

		if (!checkHash(existingFile, sha1))
			existingFile.remove();
		else
			return fullPath;
	}

	if (!info.dir().exists() && !info.dir().mkpath("."))
		return QString();

	QFile file(fullPath);

	const bool result = Util::downloadUrlToFile(url, file);

	if (file.isOpen())
		file.close();

	if (!result)
		return QString();

	if (!checkHash(file, sha1))
		return QString();

	return fullPath;
}