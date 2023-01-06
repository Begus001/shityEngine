#version 450 core

layout (location = 0) in vec4 pos;
layout (location = 1) in vec3 vertexColor;

out vec3 fragColor;

void main()
{
	fragColor = vertexColor;
	gl_Position = pos;
}