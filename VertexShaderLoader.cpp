// The preprocessor modifies the header file to contain only the relevant definition source code
// Turns this header file below into a .cpp file
#define STB_IMAGE_IMPLEMENTATION

#include "VertexShaderLoader.h"

VertexShaderLoader::VertexShaderLoader(const char* vertexShaderPath_)
{
	// Make sure the vertex shader file ifstream will throw an exception error
	vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		// Open the vertex shader file
		vertexShaderFile.open(vertexShaderPath_);

		// Read the vertex shader's file buffer contents into a stream of the vertex shader file
		vertexShaderStream << vertexShaderFile.rdbuf();

		// Close the vertex shader's file handlers
		vertexShaderFile.close();

		// Convert the vertex shader stream into a vertex shader string
		vertexShaderCode = vertexShaderStream.str();
	}

	catch (std::ifstream::failure error)
	{
		std::cout << "ERROR::SHADER::VERTEX::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
	}

	vShaderCode = vertexShaderCode.c_str();

	vertices =
	{
		NULL
	};

	VAO = NULL;
	VBO = NULL;

	vertexShader = NULL;

	data = nullptr;

	width = 0;
	height = 0;
	nrChannels = 0;

	lightVAO = NULL;

	cubeTexture = NULL;

	cubeVAO = NULL;
	cubeVBO = NULL;

	planeVAO = NULL;
	planeVBO = NULL;

	cubeVertices =
	{
		NULL
	};

	planeVertices =
	{
		NULL
	};

	//shaderProg = ShaderProgram();
}

VertexShaderLoader::~VertexShaderLoader()
{
	// Deallocate all the VAOs and VBOs
	glDeleteVertexArrays(1, &cubeVAO);
	glDeleteVertexArrays(1, &planeVAO);
	glDeleteBuffers(1, &cubeVBO);
	glDeleteBuffers(1, &planeVBO);

	vertices =
	{
		NULL
	};

	VAO = NULL;
	VBO = NULL;

	vertexShader = NULL;

	data = nullptr;

	width = 0;
	height = 0;
	nrChannels = 0;

	lightVAO = NULL;

	cubeTexture = NULL;

	cubeVertices =
	{
		NULL
	};

	planeVertices =
	{
		NULL
	};
}

void VertexShaderLoader::InitializeVertexShaderLoader()
{
	// Create a shader object ID to use it when we create the shader
	vertexShader = glCreateShader(GL_VERTEX_SHADER); // Create a vertex shader using OpenGL's version of it

	// Attach the shader source code (the GLSL one) to the shader object and compile it
	glShaderSource(vertexShader, 1, &vShaderCode, NULL);
	glCompileShader(vertexShader);

	int successfullyCompiled; // An integer that checks if the vertex shader compilation was successful
	char compilationInformationLog[512]; // Gives information about its compilation in a log file (maybe?)

	// Returns a successful compilation of the vertex shader if it can compile successfully
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &successfullyCompiled);

	// If the compilation failed, then return a log compilation error and explain the error
	if (!successfullyCompiled)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, compilationInformationLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << compilationInformationLog << std::endl;
	}
}
