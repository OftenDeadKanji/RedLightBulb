#ifndef __VBO_HPP__
#define __VBO_HPP__

namespace RedLightbulb
{
	class VBO
	{
	public:
		void create();
		void destroy();

		void bind();
		void unbind();

		void bufferData(void* data, unsigned int size);
		void bufferSubData(void* data, unsigned int size, unsigned int offset);
	private:
		GLuint id = 0;
	};
}

#endif