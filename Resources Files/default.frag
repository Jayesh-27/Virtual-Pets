#version 460 core
out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D imageTexture;

void main()
{
    FragColor = texture(imageTexture, TexCoord);
}
