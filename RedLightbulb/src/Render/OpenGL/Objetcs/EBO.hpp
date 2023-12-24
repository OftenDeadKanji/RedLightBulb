#ifndef __EBO_HPP__
#define __EBO_HPP__

namespace RedLightbulb
{
	class EBO
	{
	public:
		~EBO();

		void create();
		void destroy();

		void bind();
		void unbind();

		void bufferData(const void* data, unsigned int size);
	private:
		bool m_isInitialized = false;
		GLuint m_id;
	};
}

#endif