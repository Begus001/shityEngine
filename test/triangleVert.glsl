#version 450 core

layout (location = 0) in vec4 pos;
layout (location = 1) in vec4 vertColor;
out vec4 color;

void main()
{
	gl_Position = pos;
	color = vertColor;
}