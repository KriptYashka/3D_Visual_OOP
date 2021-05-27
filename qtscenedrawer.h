#ifndef QTSCENEDRAWER_H
#define QTSCENEDRAWER_H
#include <QGraphicsView>
#include "scenedrawerbase.h"

class QtSceneDrawer : public SceneDrawerBase, public QGraphicsView{
private:
    QGraphicsScene* QScene;
public:
    QtSceneDrawer(QWidget*);
    virtual void drawScene(Scene _scene) override;
    void drawScene();
    void drawLine(Scene _scene);
    void drawVertices(Scene _scene);

};

#endif // QTSCENEDRAWER_H
