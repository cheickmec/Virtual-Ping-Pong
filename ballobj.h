#ifndef BALLOBJ_H
#define BALLOBJ_H
#include <QPainter>


class BallObj
{

public:
    BallObj();
    ~BallObj();
    void setDir(int xDir, int yDir);
    int getXdir();
    int getYdir();
    QRect* getRect();
    void draw(QPainter*);
private:
    int xDir;
    int yDir;
    QRect* rect;
    qreal angle;
};

#endif // BALLOBJ_H
