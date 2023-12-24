#ifndef __UBO_HPP__
#define __UBO_HPP__

namespace RedLightbulb
{
	class UniformBufferObject
	{
	public:
		void create();
		void bind();
		void unbind();

		void bufferData(const void* data, unsigned int size);
		void setToSlot(int slot);
	private:
		GLuint m_id;
		//GLuint m_index;
	};
}

#endif