#pragma once

#include <iostream>
#include <list>
#include "Component.hpp"

class Entity
{
    private:
        std::string m_name;
        std::list<Component*> m_components;

    public:
        Entity(std::string name);
        void AddComponent(Component* component);
        void RemoveComponent(Component* component);
};