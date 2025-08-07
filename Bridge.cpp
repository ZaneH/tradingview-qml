#include "Bridge.h"
#include <QDebug>

void Bridge::receiveFromJS(const QString &msg) {
    qInfo() << "Received from JS:" << msg;
}
