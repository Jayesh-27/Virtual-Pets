/* #version 460 core
out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D imageTexture;

void main()
{
    FragColor = texture(imageTexture, TexCoord) * vec4(1.0f, 0.0f, 0.0f, 1.0f);
}*/



#version 460 core
out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D imageTexture;
uniform vec4 triangleColor; // Add this uniform for the triangle color

void main()
{
    vec4 texColor = texture(imageTexture, TexCoord);
    // Mix the triangle color and the texture color based on the texture's alpha
    FragColor = mix(triangleColor, texColor, texColor.a);
}
