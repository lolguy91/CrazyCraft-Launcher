#include <glad/glad.h>
#include <GLFW/glfw3.h>
//#include <ShellRenderInterfaceOpenGL.h>
//#include <ShellSystemInterface.h>
#include <iostream>
#define RMLUI_STATIC_LIB
#include <RmlUi/Core.h>
#include <RmlUi/Debugger.h>

#include<RmlImpl.h>

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
	GLFWwindow* window = glfwCreateWindow(960, 540, "CrazyCraft Launcher", NULL, NULL);
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


    // Instantiate the interfaces to RmlUi.
	MyRenderInterface render_interface;
	MySystemInterface system_interface;

	// Begin by installing the custom interfaces.
	Rml::SetRenderInterface(&render_interface);
	Rml::SetSystemInterface(&system_interface);

	// Now we can initialize RmlUi.
	Rml::Initialise();
	
	// Create a context next.
	Rml::Context* context = Rml::CreateContext("main", Rml::Vector2i(960, 540));
	if (!context)
	{
		Rml::Shutdown();
		return -1;
	}

	// If you want to use the debugger, initialize it now.
	Rml::Debugger::Initialise(context);

    // Fonts should be loaded before any documents are loaded.
	Rml::LoadFontFace("../lol/Papernotes.otf");

	// Now we are ready to load our document.
	Rml::ElementDocument* document = context->LoadDocument("../lol/index.html");
	if (!document)
	{
		Rml::Shutdown();
		return -1;
	}
    document->Show();

    


while (!glfwWindowShouldClose(window))
{
    if(glfwGetKey(window,GLFW_KEY_F1))
    {
        std::cout<< "lol" << std::endl;
        Rml::Debugger::SetVisible(!Rml::Debugger::IsVisible());
    }
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    context->Update();
	context->Render();

   glfwSwapBuffers(window);
   glfwPollEvents();
}

	// Shutting down RmlUi releases all its resources, including elements, documents, and contexts.
	Rml::Shutdown();
}