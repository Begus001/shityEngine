#version 450 core

out vec4 col;

in vec3 fragColor;

void main()
{
	col = vec4(fragColor, 1.0f);
}