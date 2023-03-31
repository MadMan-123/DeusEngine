//
// Created by Madoc on 26/03/2023.
//

#ifndef ENTITY_H
#define ENTITY_H
#include "Component.h"
#include "ComponentManager.h"

//inherited from component manager
class Entity : public ComponentManager
{
public:

    void HandleOnStart();
    void HandleOnUpdate();
    void HandleComponentsOnStart();
    void HandleComponentsOnUpdate();



private:
protected:
    //called when component is updated on start
    virtual void OnStart();
    //called when component is updated
    virtual void OnUpdate();

};


#endif //ENTITY_H
