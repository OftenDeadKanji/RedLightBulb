#version 460

uniform sampler2D baseColorTexture;

out vec4 out_color;

layout (std140, binding = 3) uniform Material
{
	uniform vec3 baseColor;
	uniform bool usesColorTexture;
};

in vec2 out_uv;

void main()
{
	//out_color = vec4(baseColor, 1.0);
	out_color = texture(baseColorTexture, out_uv);
}