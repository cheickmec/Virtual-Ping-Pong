#include "gameview.h"
#include <QPainter>
#include <QKeyEvent>

/*Constructor*/
GameView::GameView(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(parent->size());
    m_Model = new Model;
    m_Engine = new GameEngine(m_Model);
    startTimer(10);
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
    switch (event->key()) {
    case Qt::Key_A:
        this->m_Model->move('L',1);
        break;
    case Qt::Key_S:
        this->m_Model->move('L',-1);
        break;
    case Qt::Key_K:
        this->m_Model->move('R',1);
        break;
    case Qt::Key_L:
        this->m_Model->move('R',-1);
        break;
    case Qt::Key_Q:
        qApp->exit();
        break;
        default:
            QWidget::keyPressEvent(event);
        }
}
/*key release event*/
void GameView::keyReleaseEvent(QKeyEvent*event){
    Q_UNUSED(event);
    switch (event->key()) {
    case Qt::Key_A:
        this->m_Model->move('L',0);
        break;
    case Qt::Key_S:
        this->m_Model->move('L',0);
        break;
    case Qt::Key_K:
        this->m_Model->move('R',0);
        break;
    case Qt::Key_L:
        this->m_Model->move('R',0);
        break;
    case Qt::Key_Q:
        qApp->exit();
        break;
        default:
            QWidget::keyPressEvent(event);
        }
}
/*timer event*/
void GameView::timerEvent(QTimerEvent * event){
    Q_UNUSED(event);
    this->m_Engine->updateModel();
    repaint();
}
/*Returns model */
Model* GameView::getModel(){
    return m_Model;
}
