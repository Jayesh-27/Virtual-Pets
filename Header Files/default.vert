#version 460 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform vec2 imagePosition;
uniform vec2 imageScale;

void main()
{
    vec2 scaledPos = aPos * imageScale + imagePosition;

    gl_Position = vec4(scaledPos, 0.0, 1.0);
    TexCoord = aTexCoord;
}