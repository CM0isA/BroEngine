#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 normals;
layout(location = 2) in vec2 texCoords;
layout(location = 3) in vec4 colors;

uniform mat4 Projection;
uniform mat4 View;
uniform mat4 Model;

out vec4 vertexColor;

void main()
{
    gl_Position = Projection * View * Model * vec4(aPos, 1.0);
    vertexColor = vec4(0.36f, 0.2f, 0.2f, 1f);
}