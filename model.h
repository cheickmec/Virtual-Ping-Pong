#ifndef MODEL_H
#define MODEL_H
#include "ballobj.h"
#include "paddleobj.h"
class GameEngine;

class Model
{

friend class GameEngine;
public:
    Model();
    ~Model();
    void draw(QPainter*);
    void move(const char which, int Dir);
private:
    BallObj* m_Ball;
    PaddleObj* m_LeftPaddle;
    PaddleObj* m_RightPaddle;
};

#endif // MODEL_H
