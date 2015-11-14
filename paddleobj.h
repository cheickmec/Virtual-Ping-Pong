#ifndef PADDLEOBJ_H
#define PADDLEOBJ_H
#include <QPainter>

class PaddleObj
{
public:
    PaddleObj(int xPos);
    ~PaddleObj();
    void setDir(int yDir);
    int getYdir();
    QRect* getRect();
    void draw(QPainter*);
    unsigned int score;
private:
    int xDir;
    int yDir;
    QRect* rect;
    qreal angle;
};

#endif // PADDLEOBJ_H
