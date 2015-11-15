#include "ballobj.h"
/*Constructor*/
BallObj::BallObj()
{
    this->rect = new QRect(200,200,20,20);
    this->angle = 0;
    this->xDir = 3;
    this->yDir = 3;
}
/*Destructor*/
BallObj::~BallObj(){
    delete rect;
}
/*Returns rectangle used for drawing*/
QRect* BallObj::getRect(){
    return rect;
}
/*returns x component of velocity*/
int BallObj::getXdir(){
    return this->xDir;
}
/*returns y component of velocity*/
int BallObj::getYdir(){
    return this->yDir;
}
/*sets x and y components of velocity*/
void BallObj::setDir(int xDir, int yDir){
    this->xDir = xDir;
    this->yDir = yDir;
}
/*Drawing function: can be changed for different drawings*/
void BallObj::draw(QPainter *p){
    p->save();
    p->setPen(QColor("#d4d4d4"));
    p->setBrush(QBrush(Qt::black));
    p->drawRect(*rect);
    p->restore();
}
