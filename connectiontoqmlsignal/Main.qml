import QtQuick 2.0
import Ubuntu.Components 1.1

/*!
    \brief MainView with a Label and Button elements.
*/

MainView {
    id: main

    // objectName for functional testing purposes (autopilot-qt5)
    objectName: "mainView"

    // Note! applicationName needs to match the "name" field of the click manifest
    applicationName: "connectiontoqmlsignal.liu-xiao-guo"

    /*
     This property enables the application to change orientation
     when the device is rotated. The default is false.
    */
    //automaticOrientation: true

    // Removes the old toolbar and enables new features of the new header.
    useDeprecatedToolbar: false

    signal qmlSignal(string msg)
    signal qmlSignalGeneric(var anObject)

    width: units.gu(60)
    height: units.gu(85)

    Page {
        id: page
        title: i18n.tr("connectiontoqmlsignal")

        Column {
            anchors.fill: parent
            spacing: units.gu(2)

            Button {
                width: parent.width
                text: i18n.tr("Send signal to C++!")

                onClicked: {
                    main.qmlSignal("Hello from QML!")
                }
            }

            Button {
                width: parent.width
                text: "Send a generic data to C++"

                onClicked: {
                    main.qmlSignalGeneric(main)
                }
            }
        }
    }
}

