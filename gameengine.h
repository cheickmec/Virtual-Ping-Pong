#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "model.h"

class GameEngine
{
public:
    GameEngine(Model* model);
    ~GameEngine();
    void updateModel();
    void checkCollision();
private:
    Model* m_Model;
};

#endif // GAMEENGINE_H
