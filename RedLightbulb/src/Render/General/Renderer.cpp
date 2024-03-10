#include "pch.h"
#include "Renderer.hpp"
#include "../OpenGL/RendererOpenGL.hpp"
#include "../OpenGL/ShadingModels/UnlitShadingModelOpenGL.hpp"

namespace RedLightbulb
{
    std::unique_ptr<Renderer> Renderer::s_instance = nullptr;

    Renderer& Renderer::getInstance()
    {
        return *s_instance;
    }

    Renderer* Renderer::getInstancePtr()
    {
        return s_instance.get();
    }

    Renderer& Renderer::createInstance(Window& window)
    {
        s_instance = std::unique_ptr<RendererOpenGL>(new RendererOpenGL());
        s_instance->m_window = &window;
        //s_instance->m_unlitShadingModels = 

        s_instance->init();

        return *s_instance;
    }

    void Renderer::destroyInstance()
    {
        s_instance->deinit();
        s_instance.release();
    }
    void Renderer::addUnlitMesh(const sPtr<Mesh> mesh, UnlitShadingModel::InstanceT instance)
    {
        std::vector<sPtr<UnlitShadingModel::MaterialT>> materials;
        m_unlitShadingModels->addMesh(mesh, materials, instance);
    }
    void Renderer::addUnlitMesh(const sPtr<Mesh> mesh, std::vector<sPtr<UnlitShadingModel::MaterialT>>& materials, UnlitShadingModel::InstanceT instance)
    {
        m_unlitShadingModels->addMesh(mesh, materials, instance);
    }
    void Renderer::addLitMesh(const sPtr<Mesh> mesh, LitShadingModel::InstanceT instance)
    {
        std::vector<sPtr<LitShadingModel::MaterialT>> materials;
        m_litShadingModels->addMesh(mesh, materials, instance);
    }
    void Renderer::addLitMesh(const sPtr<Mesh> mesh, std::vector<sPtr<LitShadingModel::MaterialT>>& materials, LitShadingModel::InstanceT instance)
    {
        m_litShadingModels->addMesh(mesh, materials, instance);
    }
}