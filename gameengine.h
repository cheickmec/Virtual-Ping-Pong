#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "model.h"
#include <QObject>

class GameEngine : public QObject
{
    Q_OBJECT
public:
    GameEngine(QObject* parent = 0);
    void setModel(Model* model);
    void checkCollision();
public slots:
    void updateModel();
signals:
    void finished();
private:
    Model* m_Model;
};

#endif // GAMEENGINE_H
