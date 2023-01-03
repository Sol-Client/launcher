// SPDX-License-Identifier: GPL-3.0-or-later

#include "MetaParseException.hpp"

MetaParseException::MetaParseException(const QString &detail)
	: detailMsg(detail) {}

const QString &MetaParseException::detail() {
	return detailMsg;
}