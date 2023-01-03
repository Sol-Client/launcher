// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QJsonObject>
#include <QJsonArray>

namespace Util {

QJsonObject castToObj(const QJsonValue &value);
QJsonArray castToArray(const QJsonValue &value);

} // namespace Util