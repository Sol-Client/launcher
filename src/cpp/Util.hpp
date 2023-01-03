// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QFile>
#include <QString>
#include <QUrl>

namespace Util {

QByteArray readUrl(const QUrl &url);

bool downloadUrlToFile(const QUrl &url, QFile &file);

}; // namespace Util