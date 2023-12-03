#include "pch.h"
#include "Mouse.hpp"

namespace RedLightbulb
{
    bool Mouse::isPressed(Button button)
    {
        return m_buttons[static_cast<int>(button)];
    }
    const Vec2& Mouse::getPosition() const
    {
        return m_position;
    }
}