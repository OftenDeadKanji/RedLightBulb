#include "pch.h"
#include "TextureManager.hpp"
#include "../../Render/General/Texture/Texture.hpp"
#include "../../Render/OpenGL/Texture/TextureOpenGL.hpp"

namespace RedLightbulb
{
	std::unique_ptr<TextureManager> TextureManager::s_instance = nullptr;

	TextureManager& TextureManager::createInstance()
	{
		s_instance = std::make_unique<TextureManager>();

		return *s_instance;
	}
	TextureManager& TextureManager::getInstance()
	{
		return *s_instance;
	}
	void TextureManager::destroy()
	{
		s_instance.release();
	}
	std::shared_ptr<Texture> TextureManager::loadFromFile(const std::string& pathToFile, const std::string& textureName, TextureType type)
	{
		std::string name = textureName.empty() ? pathToFile : textureName;

		int width{}, height{}, channelsCount{};
		unsigned char* data = stbi_load(pathToFile.c_str(), &width, &height, &channelsCount, 0);	

		auto texture = loadOpenGLTexture(name, type, data, width, height);

		return m_textures[textureName] = texture;
	}

	std::shared_ptr<Texture> TextureManager::loadFromMemory(const unsigned char* data, int length, const std::string& textureName, TextureType type)
	{
		int width{}, height{}, channelsCount{};
		unsigned char* _data = stbi_load_from_memory(data, length, &width, &height, &channelsCount, 0);

		auto texture = loadOpenGLTexture(textureName, type, _data, width, height);

		return texture;
	}

	std::shared_ptr<TextureOpenGL> TextureManager::loadOpenGLTexture(const std::string& textureName, TextureType type, const void* data, int width, int height)
	{
		std::shared_ptr<TextureOpenGL> texture = std::make_shared<TextureOpenGL>(type);

		texture->create(data, width, height);

		return texture;
	}
}
