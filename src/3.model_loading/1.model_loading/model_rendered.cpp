/////////////
// Imports //
/////////////

// Standard libraries
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// GL includes
#include <learnopengl/shader.h>
#include <learnopengl/camera.h>
#include <learnopengl/model.h>

// GLM mathemtics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Other libraries
#include <SOIL.h>
#include <learnopengl/filesystem.h>

//////////////////
// Set up world //
//////////////////

// **Reference: HW3 starter code.

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void do_movement();

// Initial window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

// Set up camera
Camera  camera(glm::vec3(0.0f, 0.0f, 3.0f));
GLfloat lastX  =  WIDTH  / 2.0;
GLfloat lastY  =  HEIGHT / 2.0;
bool    keys[1024];

// Light position
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

// Deltatime
GLfloat deltaTime = 0.0f;	// Time between current frame and last frame
GLfloat lastFrame = 0.0f;  	// Time of last frame

//////////
// Main //
//////////

int main()
{
    // Init GLFW
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Cartoon Filter", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // Set the required callback functions
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    glewInit();

    int w,h;
    glfwGetFramebufferSize( window, &w, &h);

    // Define the viewport dimensions
    glViewport(0, 0, w, h);

    // OpenGL options
    glEnable(GL_DEPTH_TEST);

    // Setup and compile shaders
    Shader paintingShader("shader.vs", "shader.frag");
    Shader roomShader("room-shader.vs", "room-shader.frag");

    // Reference; LearnOpenGL, 1.getting_started code.

    // Set up vertex data (and buffer(s)) and attribute pointers
    GLfloat vertices[] = {
        // Positions          // Colors           // Texture Coords
         1.5f,  1.5f, 1.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // Top Right
         1.5f, -1.5f, 1.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // Bottom Right
        -1.5f, -1.5f, 1.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
        -1.5f,  1.5f, 1.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // Top Left 
    };

    GLuint indices[] = {  // Note that we start from 0!
        0, 1, 3, // First Triangle
        1, 2, 3  // Second Triangle
    };

    /////////////////////////////////////
    // Set up layout for vertex shader //
    /////////////////////////////////////

    // First, set the container's VAO (and VBO)
    GLuint VBO, containerVAO, EBO;
    glGenVertexArrays(1, &containerVAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindVertexArray(containerVAO);


    // Set up vertex data (and buffer(s)) and attribute pointers
    GLfloat roomVertices[] = {
        // Positions          // Colors           // Texture Coords
         5.5f,  5.5f, 5.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // Top Right
         5.5f, -5.5f, 5.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // Bottom Right
        -5.5f, -5.5f, 5.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
        -5.5f,  5.5f, 5.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // Top Left 
    };

    GLuint roomIndices[] = {  // Note that we start from 0!
        0, 1, 3, // First Triangle
        1, 2, 3  // Second Triangle
    };


    GLuint roomVBO, roomContainerVAO, roomEBO;
    glGenVertexArrays(1, &roomContainerVAO);
    glGenBuffers(1, &roomVBO);
    glGenBuffers(1, &roomEBO);

    glBindBuffer(GL_ARRAY_BUFFER, roomVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(roomVertices), roomVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, roomEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(roomIndices), roomIndices, GL_STATIC_DRAW);

    glBindVertexArray(roomContainerVAO);


    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    // Normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    // Texture attributes
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);
    // Color attributes
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(3);
    // Finish
    glBindVertexArray(0);


    ////////////////////
    // Set up texture //
    ////////////////////

    GLuint texture1;

    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
    // Set our texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   // Set texture wrapping to GL_REPEAT
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Load, create texture and generate mipmaps
    int width, height;

    unsigned char* image = SOIL_load_image(FileSystem::getPath("resources/images/dog.jpg").c_str(), &width, &height, 0, SOIL_LOAD_RGB);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

    //////////////////
    // Set up light //
    //////////////////

    // Then, we set the light's VAO (VBO stays the same. After all, the vertices are the same for the light object (also a 3D cube))
    GLuint lightVAO;
    glGenVertexArrays(1, &lightVAO);
    glBindVertexArray(lightVAO);
    // We only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need.
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Set up textures
    glEnable(GL_TEXTURE_2D);

    // Load model
    // TODO: Replace with plane object.
    Model paintingModel(FileSystem::getPath("resources/objects/painting/painting-2.obj").c_str());

    //glDisable(GL_TEXTURE_2D); //disable when loading the room model?

    //Load room model
    // TODO: Replace with an object that combines painting-2 and room-edit.
    Model roomModel(FileSystem::getPath("resources/objects/gallery/room-edit.obj").c_str());

    // Game loop
    while(!glfwWindowShouldClose(window))
    {
        // Calculate deltatime of current frame
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();
        do_movement();

        // Clear the colorbuffer
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glUniform1i(glGetUniformLocation(paintingShader.Program, "ourTexture1"), 0);

        // Use cooresponding shader when setting uniforms/drawing objects
        paintingShader.Use();

        GLint objectColorLoc = glGetUniformLocation(paintingShader.Program, "objectColor");
        GLint lightColorLoc  = glGetUniformLocation(paintingShader.Program, "lightColor");
        GLint lightPosLoc    = glGetUniformLocation(paintingShader.Program, "lightPos");
        GLint viewPosLoc     = glGetUniformLocation(paintingShader.Program, "viewPos");
        glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);
        glUniform3f(lightColorLoc,  1.0f, 1.0f, 1.0f);
        glUniform3f(lightPosLoc,    lightPos.x, lightPos.y, lightPos.z);
        glUniform3f(viewPosLoc,     camera.Position.x, camera.Position.y, camera.Position.z);

        // Create camera transformations
        glm::mat4 view;
        view = camera.GetViewMatrix();
        glm::mat4 projection = glm::perspective(camera.Zoom, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);
        // Get the uniform locations
        GLint modelLoc = glGetUniformLocation(paintingShader.Program, "model");
        GLint viewLoc  = glGetUniformLocation(paintingShader.Program,  "view");
        GLint projLoc  = glGetUniformLocation(paintingShader.Program,  "projection");
        // Pass the matrices to the shader
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

        // Draw the container (using container's vertex attributes)
        glBindVertexArray(containerVAO);

        glm::mat4 model;
        // The following line modifies the location of the painting.
        model = glm::translate(model, glm::vec3(0.0f, -1.5f, 10.0f)); // Translate it down a bit so it's at the center of the scene
        model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));	// It's a bit too big for our scene, so scale it down
        glUniformMatrix4fv(glGetUniformLocation(paintingShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        paintingModel.Draw(paintingShader);   

        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);

        ///////////////////////////
        /// handle room loading ///
        ///////////////////////////

        roomShader.Use();
        GLint objectColorLocRoom = glGetUniformLocation(roomShader.Program, "objectColor");
        GLint lightColorLocRoom  = glGetUniformLocation(roomShader.Program, "lightColor");
        GLint lightPosLocRoom    = glGetUniformLocation(roomShader.Program, "lightPos");
        GLint viewPosLocRoom     = glGetUniformLocation(roomShader.Program, "viewPos");
        glUniform3f(objectColorLocRoom, 1.0f, 0.5f, 0.31f);
        glUniform3f(lightColorLocRoom,  1.0f, 1.0f, 1.0f);
        glUniform3f(lightPosLocRoom,    lightPos.x, lightPos.y, lightPos.z);
        glUniform3f(viewPosLocRoom,     camera.Position.x, camera.Position.y, camera.Position.z);

        // Draw the container (using container's vertex attributes)
        glBindVertexArray(roomContainerVAO);

        // Create camera transformations
        glm::mat4 roomView;
        roomView = camera.GetViewMatrix();
        glm::mat4 roomProjection = glm::perspective(camera.Zoom, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);
        // Get the uniform locations
        GLint roomModelLoc = glGetUniformLocation(roomShader.Program, "model");
        GLint roomViewLoc  = glGetUniformLocation(roomShader.Program,  "view");
        GLint roomProjLoc  = glGetUniformLocation(roomShader.Program,  "projection");
        // Pass the matrices to the shader
        glUniformMatrix4fv(roomViewLoc, 1, GL_FALSE, glm::value_ptr(roomView));
        glUniformMatrix4fv(roomProjLoc, 1, GL_FALSE, glm::value_ptr(roomProjection));

        // Draw the container (using container's vertex attributes)
        glBindVertexArray(roomContainerVAO);

        glm::mat4 modelRoom;
        modelRoom = glm::translate(modelRoom, glm::vec3(0.0f, -1.75f, 0.0f)); // Translate it down a bit so it's at the center of the scene
        modelRoom = glm::scale(modelRoom, glm::vec3(0.8f, 0.8f, 0.8f)); // It's a bit too big for our scene, so scale it down
        glUniformMatrix4fv(glGetUniformLocation(roomShader.Program, "roomModel"), 1, GL_FALSE, glm::value_ptr(modelRoom));
        roomModel.Draw(roomShader);   

        glUniformMatrix4fv(roomModelLoc, 1, GL_FALSE, glm::value_ptr(modelRoom));
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);

        // Swap the screen buffers
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}

/* Do not modify below. */
// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
            keys[key] = true;
        else if (action == GLFW_RELEASE)
            keys[key] = false;
    }
}

void do_movement()
{
    // Camera controls
    if (keys[GLFW_KEY_W])
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (keys[GLFW_KEY_S])
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (keys[GLFW_KEY_A])
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (keys[GLFW_KEY_D])
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

bool firstMouse = true;
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    GLfloat xoffset = 10 * (xpos - lastX);
    GLfloat yoffset = 10 * (lastY - ypos);  // Reversed since y-coordinates go from bottom to left

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset / 5, yoffset / 5);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}


#pragma endregion