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
        m_unlitShadingModels->addMesh(mesh, instance);
    }
    void Renderer::addUnlitMesh(const sPtr<Mesh> mesh, const std::vector<std::pair<const SubMesh*, sPtr<UnlitShadingModel::MaterialT>>>& subMeshesMaterials, UnlitShadingModel::InstanceT instance)
    {
        m_unlitShadingModels->addMesh(mesh, subMeshesMaterials, instance);
    }
    void Renderer::addLitMesh(const sPtr<Mesh> mesh, LitShadingModel::InstanceT instance)
    {
        m_litShadingModels->addMesh(mesh, instance);
    }
    void Renderer::addLitMesh(const sPtr<Mesh> mesh, const std::vector<std::pair<const SubMesh*, sPtr<LitShadingModel::MaterialT>>>& subMeshesMaterials, LitShadingModel::InstanceT instance)
    {
        m_litShadingModels->addMesh(mesh, subMeshesMaterials, instance);
    }
}