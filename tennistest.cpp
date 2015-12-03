#include <QTest>
#include "mainwindow.h"
#include <QDebug>
#include <QPixmap>

class MyTest: public QObject
{
    Q_OBJECT
private slots:
    void gameEngineTest();
    void modelTest();
    void gameTest();   
};

void MyTest::gameEngineTest()
{
    GameEngine* aEngine = new GameEngine();
    Model* aModel = new Model();
    aEngine->setModel(aModel);
    aEngine->updateModel();
}
void MyTest::modelTest()
{
    Model* aModel = new Model();
    aModel->move('L',32);
    aModel->move('R',33);
}

void MyTest::gameTest()
{
    MainWindow* wintest = new MainWindow;
    wintest->show();
    QPixmap pixmap(wintest->size());
    wintest->render(&pixmap);
    QVERIFY(pixmap.save("snapshot0.png","PNG"));
    qDebug()<<"initial snapshot taken";
    qDebug()<<"moving right paddle down";
    for(int i = 0 ; i < 10; ++i){
        QTest::keyClick(wintest->focusWidget(),Qt::Key_K);
    }
    qDebug()<<"moving left paddle up";
    for(int i = 0 ; i < 500; ++i){
        QTest::keyClick(wintest->focusWidget(),Qt::Key_S);
    }
    qDebug()<<"Taking second snapshot";
    wintest->render(&pixmap);
    QVERIFY(pixmap.save("snapshot1.png","PNG"));
    qDebug()<<"Snapshot1.png taken";
    qDebug()<<"moving left paddle down";
    qDebug()<<"moving right paddle up";
    for(int i = 0 ; i < 50; ++i){
        QTest::keyClick(wintest->focusWidget(),Qt::Key_A);
        QTest::keyClick(wintest->focusWidget(),Qt::Key_L);
    }
    QPixmap pix = (wintest->size());
    wintest->render(&pix);
    QVERIFY(pix.save("snapshot2.png","PNG"));
    qDebug()<<"Snapshot2.png taken";   
}

QTEST_MAIN(MyTest)

#include "tennistest.moc"
