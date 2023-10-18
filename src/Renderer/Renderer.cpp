#include "Renderer.hpp"
#include "RendererOpenGL.hpp"

namespace RedLightbulb
{
    std::unique_ptr<Renderer> Renderer::s_instance = nullptr;

    Renderer& Renderer::getInstance()
    {
        return *s_instance;
    }

    Renderer& Renderer::createInstance(Window& window)
    {
        s_instance = std::unique_ptr<RendererOpenGL>(new RendererOpenGL());
        s_instance->m_window = &window;

        s_instance->init();

        return *s_instance;
    }

    void Renderer::destroyInstance()
    {
        s_instance.release();
    }
}