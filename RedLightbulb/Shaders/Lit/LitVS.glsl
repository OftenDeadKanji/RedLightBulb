#version 460

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec2 in_uv;
layout (location = 2) in vec3 in_normal;
layout (location = 3) in vec3 in_tangent;
layout (location = 4) in vec3 in_bitangent;

layout (location = 5) in vec4 in_instanceMatrix0;
layout (location = 6) in vec4 in_instanceMatrix1;
layout (location = 7) in vec4 in_instanceMatrix2;
layout (location = 8) in vec4 in_instanceMatrix3;

layout (std140, binding = 1) uniform PerFrame
{
	uniform mat4 viewMat;
	uniform mat4 projMat;
};

out vec3 out_positionWS;
out vec2 out_uv;
out vec3 out_normal;

void main()
{
	mat4 modelMat = mat4(in_instanceMatrix0, in_instanceMatrix1, in_instanceMatrix2, in_instanceMatrix3);

	vec4 positionWS = modelMat * vec4(in_position, 1.0);

	out_positionWS = positionWS.xyz;

	vec4 out_positionCS = projMat * viewMat * positionWS;
	gl_Position = out_positionCS;

	out_uv = in_uv;

	out_normal = in_normal;
}