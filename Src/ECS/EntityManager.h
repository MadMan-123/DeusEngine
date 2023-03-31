//
// Created by Madoc on 26/03/2023.
//

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H


#include "Entity.h"

class EntityManager
{
public:
    void AddEntity(Entity& entity);
    void RemoveEntity(Entity& entity);
    bool CheckEntityExists(Entity& entity);
    void RunUpdates();
    void RunStarts();


private:
    std::vector<Entity*> Entities;
};


#endif //ENTITYMANAGER_H
