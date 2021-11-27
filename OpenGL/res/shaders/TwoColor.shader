#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 v_Color;

out vec4 Color;

void main()
{
	gl_Position = position;
	Color = v_Color;
};


#shader fragment
#version 410 core

layout(location = 0) out vec4 color;

in vec4 Color;

uniform vec4 u_Color;

void main()
{
	color = Color;
};