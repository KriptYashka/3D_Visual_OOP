#ifndef SCENEDRAWERBASE_H
#define SCENEDRAWERBASE_H
#include "scene.h"

class SceneDrawerBase
{
public:
    SceneDrawerBase();
    virtual void drawScene(Scene _scene);
};

#endif // SCENEDRAWERBASE_H
