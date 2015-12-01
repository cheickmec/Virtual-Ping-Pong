#include "gameview.h"
#include <QPainter>
#include <QKeyEvent>
#include <QtGui>
#include <QThread>

/*Constructor*/
GameView::GameView(QWidget *parent) :
    QWidget(parent)
{
    QThread* thread = new QThread;
    this->setFixedSize(parent->size());
    m_Model = new Model;
    m_Engine = new GameEngine();
    m_Engine->setModel(m_Model);
    m_Engine->moveToThread(thread);
    QObject::connect(m_Engine, SIGNAL(started()),m_Engine,SLOT(updateModel()));
    QObject::connect(m_Engine, SIGNAL(finished()), m_Engine, SLOT(deleteLater()));
    QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    QObject::connect(this, SIGNAL(updateEngine()), m_Engine, SLOT(updateModel()));

    startTimer(17);
    increment = 8;
    QObject::connect(this, SIGNAL(movePaddle(char,int)),m_Model,SLOT(move(char,int)));
    thread->start();

}
/*Destructor*/
GameView::~GameView(){

}
/*paint event*/
void GameView::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter* painter = new QPainter(this);
    drawBackground(painter);
    m_Model->draw(painter);
}
/*Draw background*/
void GameView::drawBackground(QPainter * painter){
    painter->save();
    QLinearGradient grad1(0, 0, this->width(), this->height());
    grad1.setColorAt(0.1, Qt::green);
    grad1.setColorAt(0.5, Qt::yellow);
    grad1.setColorAt(0.9, Qt::red);
    painter->fillRect(0, 0, this->width(), this->height(), grad1);
    QVector<qreal> dashes;
    qreal space = 4;
    dashes << 5 << space;
    QPen pen(Qt::black, 2, Qt::SolidLine);
    pen.setStyle(Qt::CustomDashLine);
    pen.setDashPattern(dashes);
    painter->setPen(pen);
    painter->drawLine(this->width()/2,0,this->width()/2,this->height());
    painter->restore();
}
/*key press event*/
void GameView::keyPressEvent(QKeyEvent *event){
    Q_UNUSED(event);
    if(event->key() == Qt::Key_A)
        emit movePaddle('L',increment);

    if( event->key() == Qt::Key_S)
        emit movePaddle('L',-increment);

    if(event->key() == Qt::Key_K)
        emit movePaddle('R',increment);

    if( event->key() == Qt::Key_L)
        emit movePaddle('R',-increment);

    if(event->key() == Qt::Key_Q)
        qApp->exit();
}
/*key release event*/
void GameView::keyReleaseEvent(QKeyEvent*event){
    Q_UNUSED(event);
    if(event->key() == Qt::Key_A)
        this->m_Model->move('L',0);

    if( event->key() == Qt::Key_S)
        this->m_Model->move('L',0);

    if(event->key() == Qt::Key_K)
        this->m_Model->move('R',0);

    if( event->key() == Qt::Key_L)
        this->m_Model->move('R',0);
}
/*timer event*/
void GameView::timerEvent(QTimerEvent * event){
    Q_UNUSED(event);
    emit updateEngine();
    repaint();
}
/*Returns model */
Model* GameView::getModel(){
    return m_Model;
}
