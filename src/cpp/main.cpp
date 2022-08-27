// SPDX-License-Identifier: GPL-3.0-or-later

#include <QtQuick>

#include "Launcher.hpp"
#include "config.hpp"

int main(int argc, char **argv) {
	QGuiApplication app(argc, argv);
	app.setApplicationName(APP_NAME);
	app.setApplicationDisplayName(APP_NAME);
	app.setApplicationVersion(APP_VERSION);

	QQuickView view;
	view.setSource(QUrl("qrc:/main.qml"));

	Launcher launcher(&view);
	view.rootContext()->setContextProperty("launcher", &launcher);

	view.show();

	return app.exec();
}
