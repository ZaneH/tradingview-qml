#include "Bridge.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QWebChannel>
#include <QtWebEngineCore/QtWebEngineCore>
#include <QtWebEngineQuick/QtWebEngineQuick>

#ifdef QT_DEBUG
bool ret = qputenv("QTWEBENGINE_CHROMIUM_FLAGS",
                   " --remote-debugging-port=91 --no-sandbox");
#endif

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    QtWebEngineQuick::initialize();
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<Bridge>("ChartExample", 1, 0, "Bridge");

    engine.load(QUrl(QStringLiteral("../Main.qml")));

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    QObject *root = engine.rootObjects().first();
    QObject *bridgeObj = root->findChild<QObject *>("bridgeObject");

    if (!bridgeObj) {
        qWarning() << "Could not find QML bridge object!";
        return -1;
    }

    Bridge *bridge = qobject_cast<Bridge *>(bridgeObj);
    if (!bridge) {
        qWarning() << "Bridge object found, but cast failed!";
        return -1;
    }

    return app.exec();
}
