//
// Created by Madoc on 26/03/2023.
//

#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H

#include <iostream>
#include <vector>
#include <typeinfo>
#include "Component.h"

class ComponentManager
{
public:

    template<typename Type>
    Type* AddComponent()
    {
        //create new instance of Type
        Type* newComp = new Type();

        //checks if the component exists, if so return
        if(CheckComponentExists<Type>())
        {
            std::cout << "Cannot Add Component, " << typeid(*newComp).name() << " Already Exists" << std::endl;
            delete newComp;
            return NULL;
        }


        //if not add the component
        std::cout << "Added component" << typeid(newComp).name() << std::endl;

        Components.push_back(newComp);

        //get the top of the vector and set the parent entity
        //Components.front()->SetParent(ParentEntity);
        return newComp;
    }

    template<typename Type>
    void RemoveComponent()
    {
        std::cout << "Removing Comp\n";
        //get an instance of the type to remove it
        Type* CompToRemove = new Type();
        //check if the type exists
        //if not return
        if(!CheckComponentExists<Type>())
        {
            std::cout << "Component: " << typeid(CompToRemove).name() << " does not exist"<< std::endl;

            return;
        }

        int iIndex = 0;
        //if so remove the component
        for(auto component : Components)
        {
            if(typeid(*component) == typeid(*CompToRemove))
            {
                Components.erase(Components.begin() + iIndex);
                std::cout << "Removed Component: " << typeid(CompToRemove).name() << std::endl;
                break;
            }
            iIndex++;
        }
        delete CompToRemove;

    }

    template<typename Type>
    bool CheckComponentExists()
    {
        Type* newComp = new Type();

        //checks if the component exists, if so return
        for(auto component : Components)
        {
            if(typeid(*component) == typeid(*newComp))
            {
                //memory manage
                delete newComp;
                return true;
            }
        }
        //memory manage
        delete newComp;
        return false;

    }

    template<typename Type>
    Type* GetComponent()
    {
        Type* RefComp = new Type();

        for(auto component : Components)
        {
            if(typeid(*component) == typeid(*RefComp))
            {
                delete RefComp;
                return component;
            }
        }

        delete RefComp;
        return NULL;

    }

    void RunAllComponentOnUpdates();

    void DestroyAllComponents();
    ~ComponentManager();
protected:
    std::vector<Component*> Components;
    //void SetParentEntity(Entity &entity);



};

#endif //COMPONENTMANAGER_H