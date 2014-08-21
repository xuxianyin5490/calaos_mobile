import QtQuick 2.0
import QtQuick.Controls 1.2

Item {

    signal favoriteAddClicked()
    signal favoriteEditClicked()

    Image {
        source: calaosApp.getPictureSized(isLandscape?
                                              "background_landscape":
                                              "background")
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
    }

    Flickable {
        id: listFlick

        Column {
            id: content
            spacing: 6

            ListGroupHeader { width: listFlick.width; title: qsTr("Connection:") }
            Item {
                width: listFlick.width;
                height: 40 * calaosApp.density
                Button {
                    text: qsTr("Logout")
                    width: 200 * calaosApp.density
                    height: parent.height
                    style: StyleButtonDefault { }
                    onClicked: calaosApp.logout()
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
            Item {
                width: listFlick.width;
                height: 40 * calaosApp.density
                Button {
                    text: qsTr("Reset all data")
                    width: 200 * calaosApp.density
                    height: parent.height
                    style: StyleButtonDefault { }
                    onClicked: calaosApp.resetAllData()
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            ListGroupHeader { width: listFlick.width; title: qsTr("Favorites:") }

            Item {
                width: listFlick.width;
                height: 40 * calaosApp.density
                Button {
                    text: qsTr("Add a favorite")
                    width: 200 * calaosApp.density
                    height: parent.height
                    style: StyleButtonDefault { }
                    onClicked: favoriteAddClicked()
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            Item {
                width: listFlick.width;
                height: 40 * calaosApp.density
                Button {
                    text: qsTr("Edit favorites list")
                    width: 200 * calaosApp.density
                    height: parent.height
                    style: StyleButtonDefault { }
                    onClicked: favoriteEditClicked()
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

        }

        contentHeight: content.height
        contentWidth: parent.width
        width: parent.width
        height: parent.height - header.height
        y: header.height
        flickableDirection: Flickable.VerticalFlick
    }

    ScrollBar { listObject: listFlick }

    ViewHeader {
        id: header
        headerLabel: qsTr("Settings")
        iconSource: calaosApp.getPictureSized("icon_config")
    }
}
