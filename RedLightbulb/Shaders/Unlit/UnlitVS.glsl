#version 460

layout (location = 0) in vec3 in_position;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projMat;

//out vec3 out_positionWS;
//out vec4 out_positionCS;

void main()
{
	vec4 positionWS = modelMat * vec4(in_position, 1.0);

	vec3 out_positionWS = positionWS.xyz;

	vec4 out_positionCS = projMat * viewMat * positionWS;
	gl_Position = out_positionCS;
}