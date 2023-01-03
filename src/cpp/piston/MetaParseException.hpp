// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QException>

class MetaParseException final : QException {
public:
	MetaParseException(const QString &detail);

	const QString &detail();

private:
	const QString detailMsg;
};