#ifndef __TEXTURE_MANAGER_HPP__
#define __TEXTURE_MANAGER_HPP__
#include "../../Render/General/Texture/TextureType.hpp"

namespace RedLightbulb
{
	class Texture;
	class TextureOpenGL;

	class TextureManager
	{
	public:
		static TextureManager& createInstance();
		static TextureManager& getInstance();
		static void destroy();

		std::shared_ptr<Texture> loadFromFile(const std::string& pathToFile, const std::string& textureName, TextureType type);
		std::shared_ptr<Texture> loadFromMemory(const unsigned char* data, int length, const std::string& textureName, TextureType type);

	private:
		std::shared_ptr<TextureOpenGL> loadOpenGLTexture(const std::string& textureName, TextureType type, const void* data, int width, int height);

		static std::unique_ptr<TextureManager> s_instance;

		std::unordered_map<std::string, std::shared_ptr<Texture>> m_textures;
	};
}

#endif