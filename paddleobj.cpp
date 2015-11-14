#include "paddleobj.h"


/*Constructor: sets the x position*/
PaddleObj::PaddleObj(int xPos)
{
    this->xDir = 0;
    this->yDir = 0;
    this->rect = new QRect(xPos,130,20,100);
    this->score = 0;
}
/*Destrcutor*/
PaddleObj::~PaddleObj(){
    delete this->rect;
}
/*Sets the y direction only*/
void PaddleObj::setDir(int yDir){
    this->yDir = yDir;
}

/*get y direction*/
int PaddleObj::getYdir(){
    return this->yDir;
}
/*return rectangle shape associated with paddles*/
QRect* PaddleObj::getRect(){
    return this->rect;
}
/*drawing function*/
void PaddleObj::draw(QPainter* p){
    p->save();
    p->setPen(QColor("#d4d4d4"));
    p->setBrush(QBrush(Qt::white));
    p->drawRect(*rect);
    p->restore();
}
