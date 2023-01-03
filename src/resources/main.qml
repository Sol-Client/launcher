// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
	text: "Play"
	onClicked: () => {
		try {
			launcher.launch();
		} catch (error) {
			console.error(error);
			// TODO: display it
		}
	}
}
