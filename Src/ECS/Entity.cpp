//
// Created by Madoc on 26/03/2023.
//

#include "Entity.h"



void Entity::OnStart()
{

}

void Entity::OnUpdate()
{

}

void Entity::HandleComponentsOnUpdate()
{
    RunAllComponentOnUpdates();
}

void Entity::HandleComponentsOnStart()
{

}

void Entity::HandleOnUpdate()
{
    OnStart();
}

void Entity::HandleOnStart()
{
    OnUpdate();
}


