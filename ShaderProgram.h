#pragma once

#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>
#include "VertexShaderLoader.h"
#include "FragmentShaderLoader.h"

// Include the GLM header files (OpenGL Mathematics Library)
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

class ShaderProgram
{
public:
	ShaderProgram();
	~ShaderProgram();
	void InitializeShaderProgram(VertexShaderLoader* vertexShader_, FragmentShaderLoader* fragmentShader_);

	static unsigned int shaderProgram;

private:
	std::array<VertexShaderLoader*, 3> vertexShaderLoader;
	std::array<FragmentShaderLoader*, 3> fragmentShaderLoader;
};

