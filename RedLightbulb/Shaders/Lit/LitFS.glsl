#version 460

uniform sampler2D baseColorTexture;
uniform sampler2D normalTexture;
uniform sampler2D armTexture;

out vec4 out_color;

layout (std140, binding = 3) uniform Material
{
	uniform vec3 baseColor;
	int usesBaseColorTexture;

	float roughness;
	int usesRoughnessTexture;

	float metallic;
	int usesMetallicTexture;

	int usesNormalTexture;
};

in vec3 out_positionWS;
in vec2 out_uv;
in vec3 out_normal;

void main()
{
	//out_color = vec4(baseColor, 1.0);
	out_color = texture(baseColorTexture, out_uv);
	
	//out_color = vec4(out_normal, 1.0);
	//out_color = vec4(texture(normalTexture, out_uv).xyz, 1.0);
}