import QtQuick 2.15
import QtQuick.Controls 2.15
import QtWebEngine 1.7
import QtWebChannel 1.0
import ChartExample 1.0

ApplicationWindow {
    width: 800
    height: 600
    visible: true
    title: "Qt + TradingView"

    Bridge {
        id: bridge
        objectName: "bridgeObject"
        WebChannel.id: "bridge"
        onSendData: (data) => console.log("Send data signal from C++:", data)
    }

    WebEngineView {
        id: webview
        anchors.fill: parent
        url: Qt.resolvedUrl("chart.html")
        settings.localContentCanAccessRemoteUrls: true

        onLoadingChanged: function(loadingInfo) {
            if (loadingInfo.status === WebEngineView.LoadSucceededStatus) {
                loadCompleteTimer.start()
            }
        }

        Timer {
            id: loadCompleteTimer
            interval: 500
            repeat: false
            onTriggered: bridge.sendData("Hello from QML after load!")
        }

        WebChannel {
            id: channel
            registeredObjects: [bridge]
        }

        webChannel: channel
    }

}
