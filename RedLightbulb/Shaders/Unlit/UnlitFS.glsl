#version 460

uniform sampler2D baseColorTexture;

out vec4 out_color;

layout (std140, binding = 3) uniform Material
{
	uniform vec3 baseColor;
	uniform int usesBaseColorTexture;
};

in vec2 out_uv;

void main()
{
	out_color = usesBaseColorTexture != 0 ? texture(baseColorTexture, out_uv) : vec4(baseColor, 1.0);
}