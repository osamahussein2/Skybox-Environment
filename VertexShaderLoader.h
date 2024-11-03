#ifndef VERTEXSHADERLOADER_H
#define VERTEXSHADERLOADER_H

#include <glad/glad.h>
#include <glfw3.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <list>
#include <array>
#include "stb_image.h"

// Include the GLM header files (OpenGL Mathematics Library)
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

class VertexShaderLoader
{
public:
	VertexShaderLoader(const char* vertexShaderPath_);
	~VertexShaderLoader();
	void InitializeVertexShaderLoader();

	unsigned int vertexShader;

private:
	unsigned int VAO, VBO, lightVAO;

	unsigned int cubeVAO, cubeVBO;
	unsigned int planeVAO, planeVBO;

	//unsigned int EBO;
	std::string vertexShaderCode;
	std::ifstream vertexShaderFile;
	std::stringstream vertexShaderStream;
	const char* vShaderCode;
	unsigned char* data;

	int width, height, nrChannels;

	unsigned int cubeTexture, floorTexture;

	std::array<float, 180> cubeVertices;
	std::array<float, 30> planeVertices;

	std::array<float, 288> vertices;
};

#endif