#include "qtscenedrawer.h"

QtSceneDrawer::QtSceneDrawer(QWidget* mainWindow):QGraphicsView(mainWindow){
    QScene = new QGraphicsScene(200, 200, width(), height());
}

void QtSceneDrawer::drawScene(Scene _scene){
    QScene->clear();
    drawLine(_scene);
    drawVertices(_scene);
    setScene(QScene);
}

void QtSceneDrawer::drawLine(Scene _scene){
    /* Отрисовка всех линий */
    QPen pen(Qt::blue);
    pen.setWidth(2);
    int countOfPoints = _scene.getFigures()[0].getVertices().size();
    int k = 0;
    for (int i = 0; i < countOfPoints - 1; i++) {
        Point curPoint = _scene.getFigures()[0].getVertices()[i].getPosition();
        if ((i % (19 + k * 20)) != 0 || i == 0) {
            Point nextPoint = _scene.getFigures()[0].getVertices()[i + 1].getPosition();
            QScene->addLine(curPoint.x, curPoint.y, nextPoint.x, nextPoint.y, pen);
        } else {
            k += 1;
        }
        if(i < countOfPoints - 20){
            Point step20Point = _scene.getFigures()[0].getVertices()[i + 20].getPosition();
            QScene->addLine(curPoint.x, curPoint.y, step20Point.x, step20Point.y, pen);
        }
    }
}

QColor getMyColor(int param){
    /* Регулирует цвет взависимости от дальности точки */
    int minGreen = 100;
    int currentGreen = max(0, min(255 - minGreen + param * 2, 255));
    QColor color = QColor(100, currentGreen, 220);
    return color;
}

void QtSceneDrawer::drawVertices(Scene _scene){
    /* Отрисовка всех точек */
    QPen pen(Qt::black);
    QColor color = QColor(100, 100, 220);
    QBrush br(color);
    pen.setWidth(2);
    int sizeOfPoint = 8;
    int countOfPoints = _scene.getFigures()[0].getVertices().size();
    for (int i = 0; i < countOfPoints; i++){
        Point curPoint = _scene.getFigures()[0].getVertices()[i].getPosition();
        color = getMyColor(curPoint.z);
        br.setColor(color);
        QScene->addEllipse(curPoint.x - sizeOfPoint/2.0, curPoint.y - sizeOfPoint/2.0, sizeOfPoint, sizeOfPoint, pen, br);
    }
}

void QtSceneDrawer::drawScene(){}
