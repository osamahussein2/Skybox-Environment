
#include "Window.h"
#include "VertexShaderLoader.h"
#include "FragmentShaderLoader.h"
#include "ShaderProgram.h"

int main()
{
	Window window;

	std::array <VertexShaderLoader*, 3> vertexShaderLoader;
	vertexShaderLoader = {
		new VertexShaderLoader("TextureVertexShader.glsl"),
		new VertexShaderLoader("SkyboxVertexShader.glsl"),
		new VertexShaderLoader("EnvironmentMappingVertexShader.glsl")
	};

	std::array <FragmentShaderLoader*, 3> fragmentShaderLoader;

	fragmentShaderLoader = {
		new FragmentShaderLoader("TextureFragmentShader.glsl"),
		new FragmentShaderLoader("SkyboxFragmentShader.glsl"),
		new FragmentShaderLoader("EnvironmentMappingFragmentShader.glsl")
	};

	// I don't need to make this shader program object a pointer because the constructor doesn't pass in anything
	ShaderProgram shaderProgram;

	// Just initialize the OpenGL window by filling in the right parameters below
	window.InitializeOpenGLwindow(1280, 960, "Skybox Environment", NULL, NULL);

	for (unsigned int i = 0; i < vertexShaderLoader.size(); i++)
	{
		vertexShaderLoader[i]->InitializeVertexShaderLoader();
	}

	for (unsigned int j = 0; j < fragmentShaderLoader.size(); j++)
	{
		fragmentShaderLoader[j]->InitializeFragmentShaderLoader();
	}

	shaderProgram.~ShaderProgram();

	window.WindowStillRunning();

	// Return 0 is needed because the main function is of type int
	return 0;
}