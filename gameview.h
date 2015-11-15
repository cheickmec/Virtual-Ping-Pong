#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include "model.h"
#include <QWidget>
#include "gameengine.h"

#include<QApplication>
class GameView : public QWidget
{
    Q_OBJECT
public:
    //constructor
    GameView(QWidget *parent = 0);
    //detructor
    virtual ~GameView();
    //paint event
    void paintEvent(QPaintEvent*);
    //key press event
    void keyPressEvent(QKeyEvent *);
    //key release event
    void keyReleaseEvent(QKeyEvent*);
    //timer event
    void timerEvent(QTimerEvent *);
    //Get model
    Model* getModel();
signals:
    void movePaddle(const char,int);
public slots:

private:
    int increment;
    Model* m_Model;
    GameEngine* m_Engine;
    void drawBackground(QPainter*);

};

#endif // GAMEVIEW_H
