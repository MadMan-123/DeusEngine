//
// Created by Madoc on 26/03/2023.
//

#include "ComponentManager.h"
//template<typename Type>
//void ComponentManager::AddComponent()
//{
//    //create new instance of Type
//    Type* newComp = new Type();
//
//    //checks if the component exists, if so return
//    for(auto component : Components)
//    {
//        if(typeid(*component) == typeid(*newComp))
//        {
//            std::cout << "Cannot Add Component, " << typeid(*newComp).name() << " Already Exists" << std::endl;
//            return;
//        }
//    }
//
//    //if not add the component
//    Components.push_back(newComp);
//}

void ComponentManager::RunAllComponentOnUpdates()
{
    for(auto component : Components)
    {
        component->OnUpdate();
    }
}

ComponentManager::~ComponentManager()
{
    //handle destroying all components
    DestroyAllComponents();
}

void ComponentManager::DestroyAllComponents()
{
    for (auto &comp : Components)
    {
        //deleting all components
        std::cout << "Deleting " << typeid(comp).name() << std::endl;
        delete comp;
    }
}

//void ComponentManager::SetParentEntity(Entity &entity)
//{
//    ParentEntity = entity;
//    std::cout << "Parented entity: " << typeid(ParentEntity).name() << std::endl;
//}
//
//ComponentManager::ComponentManager(Entity &parentEntity) : ParentEntity(parentEntity) {
//    this->ParentEntity = parentEntity;
//}


