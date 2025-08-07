#pragma once

#include <QObject>
#include <QtQml/qqmlregistration.h>

class Bridge : public QObject {
  Q_OBJECT
public:
  explicit Bridge(QObject *parent = nullptr) : QObject(parent) {}

signals:
  void sendData(QString data);

public slots:
  void receiveFromJS(const QString &msg);
};
