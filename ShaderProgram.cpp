#include "ShaderProgram.h"
#include "Window.h"

unsigned int ShaderProgram::shaderProgram = NULL;

ShaderProgram::ShaderProgram()
{
	vertexShaderLoader = {
		new VertexShaderLoader("TextureVertexShader.glsl"),
		new VertexShaderLoader("SkyboxVertexShader.glsl"),
		new VertexShaderLoader("EnvironmentMappingVertexShader.glsl")
	};

	fragmentShaderLoader = {
		new FragmentShaderLoader("TextureFragmentShader.glsl"),
		new FragmentShaderLoader("SkyboxFragmentShader.glsl"),
		new FragmentShaderLoader("EnvironmentMappingFragmentShader.glsl")
	};
}

ShaderProgram::~ShaderProgram()
{
	// Delete the vertex and fragment shaders after the shader objects have been linked with the shader program
	glDeleteShader(vertexShaderLoader[0]->vertexShader);
	glDeleteShader(fragmentShaderLoader[0]->fragmentShader);

	glDeleteShader(vertexShaderLoader[1]->vertexShader);
	glDeleteShader(fragmentShaderLoader[1]->fragmentShader);

	glDeleteShader(vertexShaderLoader[2]->vertexShader);
	glDeleteShader(fragmentShaderLoader[2]->fragmentShader);
}

void ShaderProgram::InitializeShaderProgram(VertexShaderLoader* vertexShader_, FragmentShaderLoader* fragmentShader_)
{
	// Create a shader program that will render both the vertex and fragment shaders to the window
	shaderProgram = glCreateProgram();

	vertexShader_->InitializeVertexShaderLoader();
	fragmentShader_->InitializeFragmentShaderLoader();

	// Attach the vertex and fragment shaders to our created shader program ID object
	glAttachShader(shaderProgram, vertexShader_->vertexShader);
	glAttachShader(shaderProgram, fragmentShader_->fragmentShader);

	// Link the attached vertex and fragment shaders together into one shader program
	glLinkProgram(shaderProgram);

	int successfullyCompiled; // An integer that checks if the shader program compilation was successful
	char compilationInformationLog[512]; // Gives information about its compilation in a log file (maybe?)

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &successfullyCompiled);

	if (!successfullyCompiled)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, compilationInformationLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << compilationInformationLog << std::endl;
	}
}