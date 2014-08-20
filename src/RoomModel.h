#ifndef ROOMMODEL_H
#define ROOMMODEL_H

#include <QObject>
#include <QStandardItemModel>
#include "qqmlhelpers.h"
#include <QQmlApplicationEngine>
#include "Common.h"
#include "CalaosConnection.h"

class ScenarioModel: public QStandardItemModel
{
    Q_OBJECT
public:
    explicit ScenarioModel(QQmlApplicationEngine *eng, CalaosConnection *con, QObject *parent = 0);

    enum
    {
        RoleType = Qt::UserRole + 1,
        RoleName,
        RoleId,
    };

    Q_INVOKABLE QObject *getItemModel(int idx);

private:
    QString name, type;

    QQmlApplicationEngine *engine;
    CalaosConnection *connection;
};

class RoomModel: public QStandardItemModel
{
    Q_OBJECT
public:
    explicit RoomModel(QQmlApplicationEngine *eng, CalaosConnection *con, QObject *parent = 0);

    enum
    {
        RoleType = Qt::UserRole + 1,
        RoleHits,
        RoleName,
        RoleId,
        RoleUnit,
        RoleRW
    };

    void load(QVariantMap &roomData, ScenarioModel *scenarioModel);

    Q_INVOKABLE QObject *getItemModel(int idx);

private:
    QString name, type, hits;

    QQmlApplicationEngine *engine;
    CalaosConnection *connection;
};

class IOBase: public QObject, public QStandardItem
{
    Q_OBJECT

    QML_READONLY_PROPERTY_MODEL(Common::IOType, ioType, RoomModel::RoleType)
    QML_READONLY_PROPERTY_MODEL(int, ioHits, RoomModel::RoleHits)
    QML_READONLY_PROPERTY_MODEL(QString, ioName, RoomModel::RoleName)
    QML_READONLY_PROPERTY_MODEL(QString, ioId, RoomModel::RoleId)

    QML_READONLY_PROPERTY_MODEL(QString, unit, RoomModel::RoleUnit)
    QML_READONLY_PROPERTY_MODEL(bool, rw, RoomModel::RoleRW)

    Q_PROPERTY(bool stateBool READ getStateBool NOTIFY stateChange)
    Q_PROPERTY(double stateInt READ getStateInt NOTIFY stateChange)
    Q_PROPERTY(QString stateString READ getStateString NOTIFY stateChange)

public:
    IOBase(CalaosConnection *con, int t);

    enum {
        IOInput, IOOutput
    };

    void load(QVariantMap &io);

    Q_INVOKABLE void sendTrue();
    Q_INVOKABLE void sendFalse();
    Q_INVOKABLE void sendInc();
    Q_INVOKABLE void sendDec();
    Q_INVOKABLE void sendDown();
    Q_INVOKABLE void sendUp();
    Q_INVOKABLE void sendStop();

    Q_INVOKABLE bool getStateBool();
    Q_INVOKABLE double getStateInt();
    Q_INVOKABLE QString getStateString();

private:
    QVariantMap ioData;
    CalaosConnection *connection;
    int ioType;

private slots:
    void inputChanged(QString id, QString key, QString value);
    void outputChanged(QString id, QString key, QString value);

signals:
    void stateChange();
};

#endif // ROOMMODEL_H
