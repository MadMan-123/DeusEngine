//
// Created by Madoc on 26/03/2023.
//

#include "EntityManager.h"

void EntityManager::AddEntity(Entity &entity)
{
    Entities.push_back(&entity);
    entity.HandleOnStart();
    entity.HandleComponentsOnStart();
}

void EntityManager::RemoveEntity(Entity &entity)
{
    int i = 0;
    for(auto ent: Entities)
    {
        if(typeid(*ent) == typeid(entity))
        {
            //remove the entity
            std::cout << "Removing Entity: " << typeid(entity).name() << std::endl;
            Entities.erase(Entities.begin() + i);
        }

        i++;
    }
}

void EntityManager::RunUpdates()
{
    for (auto ent: Entities)
    {
        //call the entity update first
        ent->HandleOnUpdate();
        //call the entities component updates
        ent->HandleComponentsOnUpdate();
    }
}

void EntityManager::RunStarts()
{
    for (auto ent: Entities)
    {
        //call the entity update first
        ent->HandleOnStart();
        //call the entities component updates
        ent->HandleComponentsOnStart();
    }
}

bool EntityManager::CheckEntityExists(Entity& entity)
{
    for (auto ent: Entities) {
        if(typeid(*ent) == typeid(entity))
        {
            return true;
        }
    }

    return false;
}
