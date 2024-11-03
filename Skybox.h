#pragma once

// Include the GLM header files (OpenGL Mathematics Library)
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include <glad/glad.h>
#include "stb_image.h"

#include "ShaderProgram.h"
#include "Camera.h"

#include <array>
#include <iostream>
#include <vector>


using namespace std;
using namespace glm;

class Skybox
{
public:
	Skybox();
	~Skybox();

	void SetSkyboxObject();
	void SetSkyboxTexture();
	void UseShaderProgramForSkybox(float aspect_ratio, float near_plane, float far_plane);

	void SetCubeObject();
	void SetCubeTexture();
	void UseShaderProgramForReflectiveCube(float aspect_ratio, float near_plane, float far_plane);

	void UseShaderProgramForPersonCube(float aspect_ratio, float near_plane, float far_plane);

	static vec3 cubePosition;
	static bool isTextureInverted;

private:
	unsigned int skyboxVAO, skyboxVBO;
	array<unsigned int, 2> cubeVAO, cubeVBO;

	unsigned int skyboxTexture;
	unsigned int cubeTexture;

	vector<string> skyboxTextures;

	unsigned char* skyboxData;
	unsigned char* cubeData;

	array<float, 108> skyboxVertices;
	array<float, 216> cubeVertices;
	array<float, 180> cubeVertices2;

	int width, height, nrChannels;

	mat4 viewMatrix, projectionMatrix, modelMatrix;
};