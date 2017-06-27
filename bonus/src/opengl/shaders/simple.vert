#version 330 core

layout(location = 0) in vec3 vertex;
layout(location = 1) in vec3 vertexColor;

uniform mat4 MVP;

out vec3 color_out;

void main()
{
  gl_Position = MVP * vec4(vertex, 1);
  color_out = vertexColor;
}
