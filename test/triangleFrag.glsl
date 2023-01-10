#version 450 core

out vec4 col;

uniform vec4 fragColor;

void main()
{
	col = fragColor;
}