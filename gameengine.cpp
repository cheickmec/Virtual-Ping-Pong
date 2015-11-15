#include "gameengine.h"
#include <time.h>


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
    if(rightPaddle->getRect()->y() < 0) rightPaddle->getRect()->moveTo(QPoint(rightPaddle->getRect()->x(),0));
    else if(rightPaddle->getRect()->y() + rightPaddle->getRect()->height() > 500){
        rightPaddle->getRect()->moveTo(QPoint(rightPaddle->getRect()->x(),500-rightPaddle->getRect()->height()));
    }
    if(leftPaddle->getRect()->y() < 0) leftPaddle->getRect()->moveTo(QPoint(leftPaddle->getRect()->x(),0));
    else if(leftPaddle->getRect()->y() + leftPaddle->getRect()->height() > 500){
        leftPaddle->getRect()->moveTo(QPoint(leftPaddle->getRect()->x(),500-leftPaddle->getRect()->height()));
    }
    if(((ballPos->x() + ballPos->width() > rightPaddle->getRect()->x())&&
            (ballPos->y() - rightPaddle->getRect()->y() < rightPaddle->getRect()->height()) &&
            (ballPos->y() - rightPaddle->getRect()->y() > 0)) ||
            ((ballPos->x() < leftPaddle->getRect()->x() + leftPaddle->getRect()->width()) &&
            (ballPos->y() - leftPaddle->getRect()->y() < rightPaddle->getRect()->height()) &&
            (ballPos->y() - leftPaddle->getRect()->y() > 0 )))
    {
        ball->setDir(-ball->getXdir(),ball->getYdir());
    }
    checkCollision();
}
void GameEngine::checkCollision(){
    QRect* ball = m_Model->m_Ball->getRect();
    if(ball->x() > 800){
        std::srand(time(NULL));
        m_Model->m_LeftPaddle->score++;

        ball->moveTo(rand()%100+400,rand()%50+200);
        m_Model->m_Ball->setDir(5,-3);
    }
    else if(ball->x() < 0){
        std::srand(time(NULL));
        m_Model->m_RightPaddle->score++;
        ball->moveTo(rand()%100+400,rand()%50+200);
        m_Model->m_Ball->setDir(-3,5);
    }
    if(ball->y() < 0 || ball->y() + ball->height() > 500){

        m_Model->m_Ball->setDir(m_Model->m_Ball->getXdir(),-m_Model->m_Ball->getYdir());

    }
}
