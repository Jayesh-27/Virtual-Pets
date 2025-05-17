#version 460 core
out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D imageTexture;

void main()
{
    FragColor = texture(imageTexture, TexCoord);
    //FragColor = vec4(TexCoord, 0.0, 1.0);
    // FragColor = vec4(1.0, 0.0, 0.0, 1.0); // Remove or comment this
}
