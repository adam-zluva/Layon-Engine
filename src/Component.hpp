#pragma once

#include <iostream>

class Component
{
    private:
        bool m_isEnabled;

    public:
        bool isEnabled() { return m_isEnabled; }
        void Enable();
        void Disable();
};