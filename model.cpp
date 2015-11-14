#include "model.h"
/*Constructor*/
Model::Model()
{
    m_Ball = new BallObj;
    m_LeftPaddle = new PaddleObj(0);
    m_RightPaddle = new PaddleObj(780);
}
/*Destrcutor*/
Model::~Model(){
    delete m_Ball;
    delete m_LeftPaddle;
    delete m_RightPaddle;
}
/*Drawing function, will pass pointer to member attributes*/
void Model::draw(QPainter *painter){
    m_Ball->draw(painter);
    m_LeftPaddle->draw(painter);
    m_RightPaddle->draw(painter);
}
/*Move Left or Right paddle */
void Model::move(const char which, int Dir){
    if(which == 'L'){
        this->m_LeftPaddle->setDir(Dir);
    }
    else if(which == 'R'){
        this->m_RightPaddle->setDir(Dir);
    }
}
