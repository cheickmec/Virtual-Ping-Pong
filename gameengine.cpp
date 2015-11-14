#include "gameengine.h"
/*Construction take as argument model pointer*/
GameEngine::GameEngine(Model* model)
{
    this->m_Model = model;
}

/*Destructor*/
GameEngine::~GameEngine(){
    //Leave model destruction to gameview
}

/*Update Model objects: collision check,
score and position update  */
void GameEngine::updateModel(){
    BallObj* ball = m_Model->m_Ball;
    QRect* ballPos = ball->getRect();
    ballPos->moveTo(ballPos->x()+ball->getXdir(),ballPos->y()+ball->getYdir());

    PaddleObj* rightPaddle = m_Model->m_RightPaddle;
    PaddleObj* leftPaddle = m_Model->m_LeftPaddle;

    rightPaddle->getRect()->moveTo(rightPaddle->getRect()->x(),rightPaddle->getRect()->y()+rightPaddle->getYdir());
    leftPaddle->getRect()->moveTo(leftPaddle->getRect()->x(),leftPaddle->getRect()->y()+leftPaddle->getYdir());

    if(((ballPos->x() + ballPos->width() > rightPaddle->getRect()->x())&&
            (ballPos->y() - rightPaddle->getRect()->y() < rightPaddle->getRect()->height())&&
            (ballPos->y() - rightPaddle->getRect()->y() >0))||
            ((ballPos->x() < leftPaddle->getRect()->x() + leftPaddle->getRect()->width())&&
            (ballPos->y() - leftPaddle->getRect()->y() < rightPaddle->getRect()->height())&&
            (ballPos->y() - leftPaddle->getRect()->y() > 0 )))
    {
        ball->setDir(-ball->getXdir(),ball->getYdir());
    }
}
void GameEngine::checkCollision(){

}
