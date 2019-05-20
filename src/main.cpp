#include "shader/shader.h"
#include "shader/shader_simple.h"
#include "shader/shader_uniform_color.h"

#include "geometry/triangle.h"
#include "texture/texture.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

static bool s_wireframe = false;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main(int argc, char** argv)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);											// specify size of screen for flagment shader
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);	// register callback when screen size changed

	//
	// Shader
	//
	Shader simpleShader(shader::simple::vertex_source, shader::simple::fragment_source);
	if (!simpleShader.build())
	{
		std::cout << simpleShader.getLastError() << std::endl;
		return 1;
	}

	Shader shaderB(shader::uniform_color::vertext_source, shader::uniform_color::fragment_source);
	if (!shaderB.build())
	{
		std::cout << shaderB.getLastError() << std::endl;
		return 1;
	}

	Triangle triangleSimple{ 1.f, -0.5 };
	triangleSimple.prepare();

	Triangle triangleB{ 1.f, 0.5 };
	triangleB.prepare();

	Texture texture_1;
	if (!texture_1.load("./resources/images/wall.jpg"))
	{
		std::cout << "failed to load texture\n";
		return 1;
	}

	Texture texture_2;
	if (!texture_2.load("./resources/images/awesomeface.png"))
	{
		std::cout << "failed to load texture2\n";
		return 1;
	}

	while (!glfwWindowShouldClose(window))
	{
		// process inputs
		processInput(window);

		// clear buffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// rendering commands
		// ..
		// ..
		if (s_wireframe)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		shaderB.active();
		float timeValue = glfwGetTime();
		float greenValue = sin(timeValue) / 2.0f + 0.5f;
		shaderB.setFloat("ourColor", greenValue);

		triangleB.draw();
		
		simpleShader.active();
		//simpleShader.setFloat("vertexOffset", greenValue);
		simpleShader.setInt("texture_1", 0); // or with shader class
		simpleShader.setInt("texture_2", 1); // or with shader class

		texture_1.active(0);
		texture_2.active(1);
		triangleSimple.draw();

		// check and call events and swap the buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);	// specify screensize for flagment shader
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	s_wireframe = false;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		s_wireframe = true;

}