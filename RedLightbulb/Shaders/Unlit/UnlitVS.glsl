#version 460

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec2 in_uv;

layout (std140, binding = 1) uniform PerFrame
{
	uniform mat4 viewMat;
	uniform mat4 projMat;
};
layout (std140, binding = 2) uniform PerModel
{
	uniform mat4 modelMat;
};

out vec2 out_uv;

void main()
{
	vec4 positionWS = vec4(in_position, 1.0);

	vec3 out_positionWS = positionWS.xyz;

	vec4 out_positionCS = projMat * viewMat * positionWS;
	gl_Position = out_positionCS;

	out_uv = in_uv;
}