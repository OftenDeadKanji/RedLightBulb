#version 460

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec2 in_uv;
layout (location = 2) in vec3 in_normal;
layout (location = 3) in vec3 in_tangent;
layout (location = 4) in vec3 in_bitangent;

layout (std140, binding = 1) uniform PerFrame
{
	uniform mat4 viewMat;
	uniform mat4 projMat;
};
layout (std140, binding = 2) uniform PerModel
{
	uniform mat4 modelMat;
};

out vec3 out_positionWS;
out vec2 out_uv;
out vec3 out_normal;

void main()
{
	vec4 positionWS = vec4(in_position, 1.0);

	out_positionWS = positionWS.xyz;

	vec4 out_positionCS = projMat * viewMat * positionWS;
	gl_Position = out_positionCS;

	out_uv = in_uv;

	out_normal = in_normal;
}