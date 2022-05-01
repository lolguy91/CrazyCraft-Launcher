#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#define RMLUI_STATIC_LIB
#include <RmlUi/Core.h>
int main(void){
 	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return 0;
	}


	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	GLFWwindow* window = glfwCreateWindow(960, 540, "CrazyCraft", NULL, NULL);
	if (window == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		return 0;

	}

	glfwMakeContextCurrent(window);

	// Initialize GLAD
	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
	{

		std::cout << "Failed to initialize GLAD.\n";
		glfwTerminate();
		return 0;
	}

	std::cout << "Using openGL Version: " << glGetString(GL_VERSION) << std::endl;

while (!glfwWindowShouldClose(window))
{
   glClear(GL_COLOR_BUFFER_BIT);


   glfwSwapBuffers(window);
   glfwPollEvents();
}


}