#include "pch.h"
#include "Mouse.hpp"

namespace RedLightbulb
{
    bool Mouse::isPressed(Button button)
    {
        return m_buttons[static_cast<int>(button)];
    }
    const Math::Vec2f& Mouse::getPosition() const
    {
        return m_position;
    }
}