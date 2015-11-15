#ifndef MODEL_H
#define MODEL_H
#include "ballobj.h"
#include "paddleobj.h"

class GameEngine;

class Model : public QObject
{    
friend class GameEngine;
Q_OBJECT
public:
    Model(QObject* parent = 0);
    void draw(QPainter*);
public slots:
    void move(const char which, int Dir);
private:
    BallObj* m_Ball;
    PaddleObj* m_LeftPaddle;
    PaddleObj* m_RightPaddle;
};

#endif // MODEL_H
