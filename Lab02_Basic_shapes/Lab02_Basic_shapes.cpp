#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <common/shader.hpp>

// Function prototypes
void keyboardInput(GLFWwindow *window);

int main(void)
{
    // =========================================================================
    // Window creation - you shouldn't need to change this code
    // -------------------------------------------------------------------------
    // Initialise GLFW
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        getchar();
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    GLFWwindow* window;
    window = glfwCreateWindow(1024, 768, "Lab02 Basic Shapes", NULL, NULL);

    if (window == NULL) {
        fprintf(stderr, "Failed to open GLFW window.\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    // -------------------------------------------------------------------------
    // End of window creation
    // =========================================================================

    // Ensure we can capture keyboard inputs
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

   // //Define vertices
   // const float verticies[] = { //SQUARE
   //     //x    y      z
   //     -0.5f, -0.5f, 0.0f, //lower left
   //      -0.5f, 0.5f, 0.0f,
   //      0.5f, -0.5f, 0.0f, // tringle 1
		 //0.5f, 0.5f, 0.0f,  //upper right
   //      -0.5f, 0.5f, 0.0f,
		 //0.5f, -0.5f, 0.0f // triangle 2

   // };

    //Define vertices
	const float verticies[] = {  //RESIDENT EVIL LOGO
        //x    y      z
        -0.3f, 1.0f, 0.0f, 
         0.3f, 1.0f, 0.0f,
         0.0f, 0.2f, 0.0f, // triangle 1
         -0.3f, 1.0f, 0.0f,
         -0.7f, 0.5f, 0.0f,
		 0.0f, 0.2f, 0.0f, // triangle 2
		 0.3f, 1.0f, 0.0f,
         0.7f, 0.5f, 0.0f,
		 0.0f, 0.2f, 0.0f, // triangle 3
		 -0.7f, 0.5f, 0.0f,
		 -0.7f, -0.2f, 0.0f,
		 0.0f, 0.2f, 0.0f, // triangle 4
		 0.7f, 0.5f, 0.0f,
		 0.7f, -0.2f, 0.0f,
		 0.0f, 0.2f, 0.0f, // triangle 5
		 0.7f, -0.2f, 0.0f,
		 0.3f, -0.7f, 0.0f,
		 0.0f, 0.2f, 0.0f, // triangle 6
		 -0.7f, -0.2f, 0.0f,
		 -0.3f, -0.7f, 0.0f,
		 0.0f, 0.2f, 0.0f, // triangle 7
		 0.3f, -0.7f, 0.0f,
         -0.3f, -0.7f, 0.0f,
		 0.0f, 0.2f, 0.0f, // triangle 8 (Opposite of triangle 1)
    };

    //Define vertex colours
    const float colours[] = {
        //R    G     B
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f , // triangle 1
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f , // triangle 2
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, // triangle 3
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f, // triangle 4
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f, // triangle 5
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, // triangle 6
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, // triangle 7
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f, // triangle 8
    };


	
    // Create Vertex Array Object
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

	//Create a Vertex Buffer Object and copy the vertex data to it
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

	//create a colour buffer object and copy the colour data to it
    unsigned int colourBuffer;
	glGenBuffers(1, &colourBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colourBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colours), colours, GL_STATIC_DRAW);

    //Compile shader program
    unsigned int shaderID = LoadShaders("vertexShader.glsl", "fragmentShader.glsl");
	// Use our shader
    glUseProgram(shaderID);

    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        // Clear the window
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
		
		// Enable the vertex array
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(
            0, //attributte
            3, //size
            GL_FLOAT, //type
            GL_FALSE, //normalise?
            0, //stride
            (void*)0); //offset

		//Enable the colour buffer
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, colourBuffer);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		//Draw the triangle
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(verticies) / (3 * sizeof(float)));
        glDisableVertexAttribArray(0);

        // Get inputs
        keyboardInput(window);
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Close OpenGL window and terminate GLFW
    glfwTerminate();
    return 0;
}

void keyboardInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
