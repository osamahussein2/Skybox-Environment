#version 330 core

out vec4 fragColor;

in vec2 texCoords;

uniform sampler2D textureImage;
uniform bool isTextureInverted;

vec4 textureColor;

void main()
{
	// If the texture isn't inverted, set the picture to show normal textures
	if (isTextureInverted == false)
	{
		textureColor = texture(textureImage, texCoords);
	}

	else if (isTextureInverted == true)
	{
		textureColor = 1.0 - (texture(textureImage, texCoords));
	}

	// Use the newly created texture color vector and make it equal to the fragment color
	fragColor = textureColor;
}