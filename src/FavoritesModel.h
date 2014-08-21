#ifndef FAVORITESMODEL_H
#define FAVORITESMODEL_H

#include <QObject>
#include <QStandardItemModel>
#include "qqmlhelpers.h"
#include <QQmlApplicationEngine>
#include "CalaosConnection.h"
#include "Common.h"

class HomeModel;

class FavoritesModel: public QStandardItemModel
{
    Q_OBJECT
public:
    explicit FavoritesModel(QQmlApplicationEngine *eng, CalaosConnection *con, QObject *parent = 0);

    enum
    {
        RoleType = Qt::UserRole + 1,
        RoleName,
        RoleId,
    };

    Q_INVOKABLE QObject *getItemModel(int idx);

    void load(HomeModel *homeModel, QVariantMap favList);

private:
    QString name, type;

    QQmlApplicationEngine *engine;
    CalaosConnection *connection;
};

#endif // FAVORITESMODEL_H