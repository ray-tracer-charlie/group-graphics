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

// Room lmain ight position
glm::vec3 lightPos(10.2f, 1.0f, 2.0f);

//ceiling tile lights
glm::vec3 tilelightPos[] = {
    //right side
    glm::vec3(8.0f, 1.0f, 4.0f),
    glm::vec3(8.0f, 1.0f, 2.0f),
    glm::vec3(8.0f, 1.0f, 0.0f),
    //left side
    glm::vec3(-8.0f, 1.0f, 4.0f),
    glm::vec3(-8.0f, 1.0f, 2.0f),
    glm::vec3(-8.0f, 1.0f, 0.0f),
    //front
    glm::vec3(-6.0f, 1.0f, 0.0f),
    glm::vec3(-2.2f, 1.0f, 0.0f),
    glm::vec3(2.2f, 1.0f, 0.0f),
    glm::vec3(-6.2f, 1.0f, 0.0f),
    //back
    glm::vec3(-6.0f, 1.0f, 4.0f),
    glm::vec3(-2.2f, 1.0f, 4.0f),
    glm::vec3(2.2f, 1.0f, 4.0f),
    glm::vec3(-6.2f, 1.0f, 4.0f)
};



//Room spotlight positions
glm::vec3 spotlightPos[] = {
    glm::vec3(0.12f, 0.4f, -6.04f),
    glm::vec3(5.12f, 0.4f, -6.04f),
    glm::vec3(4.50f, 0.0f, 9.0f),
    glm::vec3(-5.12f, 0.4f, -6.04f),
    glm::vec3(-13.0f, 0.0f, 2.0f),
    glm::vec3(11.90f, 0.2f, 2.0f)
};

// Deltatime
GLfloat deltaTime = 0.0f;   // Time between current frame and last frame
GLfloat lastFrame = 0.0f;   // Time of last frame

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



    ///////////////////////////////
    // Setup and compile shaders //
    ///////////////////////////////

    Shader paintingShader("shader.vs", "shader.frag");
    Shader paintingShader2("shader2.vs", "shader2.frag");
    Shader paintingShader3("shader3.vs", "shader3.frag");
    Shader paintingShader4("shader4.vs", "shader4.frag");
    Shader paintingShader5("shader5.vs", "shader5.frag");
    Shader paintingShader6("shader6.vs", "shader6.frag");
    Shader roomShader("room-shader.vs", "room-shader.frag");



    ///////////////////////////////
    // Set up buffers and arrays //
    ///////////////////////////////

    // Reference; LearnOpenGL, 1.getting_started code.

    /* Painting 1 */
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


    /* Painting 2 */
    // Set up vertex data (and buffer(s)) and attribute pointers
    GLfloat vertices2[] = {
        // Positions          // Colors           // Texture Coords
         2.5f,  1.5f, 1.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // Top Right
         1.5f, -1.5f, 1.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // Bottom Right
        -1.5f, -1.5f, 1.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
        -1.5f,  1.5f, 1.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // Top Left
    };

    GLuint indices2[] = {  // Note that we start from 0!
        0, 1, 3, // First Triangle
        1, 2, 3  // Second Triangle
    };

    // First, set the container's VAO (and VBO)
    GLuint VBO2, containerVAO2, EBO2;
    glGenVertexArrays(1, &containerVAO2);
    glGenBuffers(1, &VBO2);
    glGenBuffers(1, &EBO2);

    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO2);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);

    glBindVertexArray(containerVAO2);


    /* Painting 3 */
    // Set up vertex data (and buffer(s)) and attribute pointers
    GLfloat vertices3[] = {
        // Positions          // Colors           // Texture Coords
         4.5f,  2.5f, 1.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // Top Right
         4.5f, -2.5f, 1.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // Bottom Right
        -2.5f, -2.5f, 1.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
        -2.5f, 2.5f, 1.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // Top Left
    };

    GLuint indices3[] = {  // Note that we start from 0!
        0, 1, 3, // First Triangle
        1, 2, 3  // Second Triangle
    };

    // First, set the container's VAO (and VBO)
    GLuint VBO3, containerVAO3, EBO3;
    glGenVertexArrays(1, &containerVAO3);
    glGenBuffers(1, &VBO3);
    glGenBuffers(1, &EBO3);

    glBindBuffer(GL_ARRAY_BUFFER, VBO3);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices3), vertices3, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO3);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices3), indices3, GL_STATIC_DRAW);

    glBindVertexArray(containerVAO3);


    /* Painting 4 */
    // Set up vertex data (and buffer(s)) and attribute pointers
    GLfloat vertices4[] = {
        // Positions          // Colors           // Texture Coords
         4.5f,  1.5f, 1.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // Top Right
         1.5f, -1.5f, 1.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // Bottom Right
        -1.5f, -1.5f, 1.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
        -1.5f,  1.5f, 1.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // Top Left
    };

    GLuint indices4[] = {  // Note that we start from 0!
        0, 1, 3, // First Triangle
        1, 2, 3  // Second Triangle
    };

    // First, set the container's VAO (and VBO)
    GLuint VBO4, containerVAO4, EBO4;
    glGenVertexArrays(1, &containerVAO4);
    glGenBuffers(1, &VBO4);
    glGenBuffers(1, &EBO4);

    glBindBuffer(GL_ARRAY_BUFFER, VBO4);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices4), vertices4, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO4);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices4), indices4, GL_STATIC_DRAW);

    glBindVertexArray(containerVAO4);

    /* Painting 5 */
    // Set up vertex data (and buffer(s)) and attribute pointers
    GLfloat vertices5[] = {
        // Positions          // Colors           // Texture Coords
         2.5f,  1.5f, 1.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // Top Right
         1.5f, -1.5f, 1.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // Bottom Right
        -1.5f, -1.5f, 1.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
        -1.5f,  1.5f, 1.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // Top Left
    };

    GLuint indices5[] = {  // Note that we start from 0!
        0, 1, 3, // First Triangle
        1, 2, 3  // Second Triangle
    };

    // First, set the container's VAO (and VBO)
    GLuint VBO5, containerVAO5, EBO5;
    glGenVertexArrays(1, &containerVAO5);
    glGenBuffers(1, &VBO5);
    glGenBuffers(1, &EBO5);

    glBindBuffer(GL_ARRAY_BUFFER, VBO5);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices5), vertices5, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO5);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices5), indices5, GL_STATIC_DRAW);

    glBindVertexArray(containerVAO5);

    /* Painting 6 */
    // Set up vertex data (and buffer(s)) and attribute pointers
    GLfloat vertices6[] = {
        // Positions          // Colors           // Texture Coords
         2.5f,  1.5f, 1.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // Top Right
         1.5f, -1.5f, 1.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // Bottom Right
        -1.5f, -1.5f, 1.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
        -1.5f,  1.5f, 1.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // Top Left
    };

    GLuint indices6[] = {  // Note that we start from 0!
        0, 1, 3, // First Triangle
        1, 2, 3  // Second Triangle
    };

    // First, set the container's VAO (and VBO)
    GLuint VBO6, containerVAO6, EBO6;
    glGenVertexArrays(1, &containerVAO6);
    glGenBuffers(1, &VBO6);
    glGenBuffers(1, &EBO6);

    glBindBuffer(GL_ARRAY_BUFFER, VBO6);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices6), vertices6, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO6);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices6), indices6, GL_STATIC_DRAW);

    glBindVertexArray(containerVAO6);

    /* Room */
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



    //////////////////////
    // Set up textures ///
    //////////////////////

    GLuint texture1;
    GLuint texture2;
    GLuint texture3;
    GLuint texture4;
    GLuint texture5;
    GLuint texture6;

    /* Texture 1 */
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

    unsigned char* image = SOIL_load_image(FileSystem::getPath("resources/images/phelps.jpg").c_str(), &width, &height, 0, SOIL_LOAD_RGB);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

    
    /* Texture 2 */
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    // Set our texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Load, create texture and generate mipmaps
    unsigned char* image2 = SOIL_load_image(FileSystem::getPath("resources/images/running.jpg").c_str(), &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image2);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image2);
    glBindTexture(GL_TEXTURE_2D, 0);


    /* Texture 3 */
    glGenTextures(1, &texture3);
    glBindTexture(GL_TEXTURE_2D, texture3);
    // Set our texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Load, create texture and generate mipmaps
    unsigned char* image3 = SOIL_load_image(FileSystem::getPath("resources/images/rowing.jpg").c_str(), &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image3);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image3);
    glBindTexture(GL_TEXTURE_2D, 0);


    /* Texture 4 */
    glGenTextures(1, &texture4);
    glBindTexture(GL_TEXTURE_2D, texture4);
    // Set our texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Load, create texture and generate mipmaps
    unsigned char* image4 = SOIL_load_image(FileSystem::getPath("resources/images/volleyball.jpg").c_str(), &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image4);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image4);
    glBindTexture(GL_TEXTURE_2D, 0);

    /* Texture 5 */
    glGenTextures(1, &texture5);
    glBindTexture(GL_TEXTURE_2D, texture5);
    // Set our texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Load, create texture and generate mipmaps
    unsigned char* image5 = SOIL_load_image(FileSystem::getPath("resources/images/swimming-cheah.jpg").c_str(), &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image5);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image5);
    glBindTexture(GL_TEXTURE_2D, 0);

        /* Texture 6 */
    glGenTextures(1, &texture6);
    glBindTexture(GL_TEXTURE_2D, texture6);
    // Set our texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Load, create texture and generate mipmaps
    unsigned char* image6 = SOIL_load_image(FileSystem::getPath("resources/images/gymnastics.jpg").c_str(), &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image6);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image6);
    glBindTexture(GL_TEXTURE_2D, 0);


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



    //////////////////
    // Load objects //
    //////////////////

    // TODO: Remove.
    std::cout << "check point 1" << std::endl;

    // Load model
    Model paintingModel(FileSystem::getPath("resources/objects/painting/frame-plane-2.obj").c_str());
    Model paintingModel2(FileSystem::getPath("resources/objects/painting/frame-plane-2.obj").c_str());
    Model paintingModel3(FileSystem::getPath("resources/objects/painting/frame-plane-2.obj").c_str());
    Model paintingModel4(FileSystem::getPath("resources/objects/painting/frame-plane-2.obj").c_str());
    Model paintingModel5(FileSystem::getPath("resources/objects/painting/frame-plane-2.obj").c_str());
    Model paintingModel6(FileSystem::getPath("resources/objects/painting/frame-plane-2.obj").c_str());

    // TODO: Remove.
    std::cout << "check point 1.5" << std::endl;

    //Load room model
    Model roomModel(FileSystem::getPath("resources/objects/gallery/gallery-room-2-trophy.obj").c_str());

    // TODO: Remove.
    std::cout << "check point 2" << std::endl;



    ///////////////
    // Main loop //
    ///////////////

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


        /* Image 1 */

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glUniform1i(glGetUniformLocation(paintingShader.Program, "ourTexture1"), 0);

        // Use cooresponding shader when setting uniforms/drawing objects
        paintingShader.Use();

        GLint objectColorLoc = glGetUniformLocation(paintingShader.Program, "objectColor");
        GLint lightColorLoc  = glGetUniformLocation(paintingShader.Program, "lightColor");
        GLint lightPosLoc    = glGetUniformLocation(paintingShader.Program, "lightPos");
        GLint viewPosLoc     = glGetUniformLocation(paintingShader.Program, "viewPos");
        glUniform3f(objectColorLoc, 1.0f, 1.0f, 1.0f);
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
        model = glm::translate(model, glm::vec3(0.12f, 0.4f, -6.04f)); // Translate it down a bit so it's at the center of the scene
        model = glm::scale(model, glm::vec3(1.12f, 1.12f, 1.12f)); // It's a bit too big for our scene, so scale it down
        glUniformMatrix4fv(glGetUniformLocation(paintingShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
        paintingModel.Draw(paintingShader);

        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);


        /* Image 2 */

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture2);
        glUniform1i(glGetUniformLocation(paintingShader2.Program, "ourTexture2"), 0);

        // Use cooresponding shader when setting uniforms/drawing objects
        paintingShader2.Use();

        GLint objectColorLoc2 = glGetUniformLocation(paintingShader2.Program, "objectColor");
        GLint lightColorLoc2  = glGetUniformLocation(paintingShader2.Program, "lightColor");
        GLint lightPosLoc2    = glGetUniformLocation(paintingShader2.Program, "lightPos");
        GLint viewPosLoc2     = glGetUniformLocation(paintingShader2.Program, "viewPos");
        glUniform3f(objectColorLoc2, 1.0f, 1.0f, 1.0f);
        glUniform3f(lightColorLoc2,  1.0f, 1.0f, 1.0f);
        glUniform3f(lightPosLoc2,    lightPos.x, lightPos.y, lightPos.z);
        glUniform3f(viewPosLoc2,     camera.Position.x, camera.Position.y, camera.Position.z);

        // Create camera transformations
        glm::mat4 view2;
        view2 = camera.GetViewMatrix();
        glm::mat4 projection2 = glm::perspective(camera.Zoom, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);
        // Get the uniform locations
        GLint modelLoc2 = glGetUniformLocation(paintingShader2.Program, "model");
        GLint viewLoc2  = glGetUniformLocation(paintingShader2.Program,  "view");
        GLint projLoc2  = glGetUniformLocation(paintingShader2.Program,  "projection");
        // Pass the matrices to the shader
        glUniformMatrix4fv(viewLoc2, 1, GL_FALSE, glm::value_ptr(view2));
        glUniformMatrix4fv(projLoc2, 1, GL_FALSE, glm::value_ptr(projection2));

        // Draw the container (using container's vertex attributes)
        glBindVertexArray(containerVAO2);

        glm::mat4 model2;
        // The following line modifies the location of the painting.
        model2 = glm::translate(model2, glm::vec3(5.12f, 0.4f, -6.04f)); // Translate it down a bit so it's at the center of the scene
        model2 = glm::scale(model2, glm::vec3(1.12f, 1.12f, 1.12f)); // It's a bit too big for our scene, so scale it down
        glUniformMatrix4fv(glGetUniformLocation(paintingShader2.Program, "model2"), 1, GL_FALSE, glm::value_ptr(model2));
        paintingModel2.Draw(paintingShader2);

        glUniformMatrix4fv(modelLoc2, 1, GL_FALSE, glm::value_ptr(model2));
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);


        /* Image 3 */

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture3);
        glUniform1i(glGetUniformLocation(paintingShader3.Program, "ourTexture3"), 0);

        // Use cooresponding shader when setting uniforms/drawing objects
        paintingShader3.Use();

        GLint objectColorLoc3 = glGetUniformLocation(paintingShader3.Program, "objectColor");
        GLint lightColorLoc3  = glGetUniformLocation(paintingShader3.Program, "lightColor");
        GLint lightPosLoc3    = glGetUniformLocation(paintingShader3.Program, "lightPos");
        GLint viewPosLoc3     = glGetUniformLocation(paintingShader3.Program, "viewPos");
        glUniform3f(objectColorLoc3, 1.0f, 1.0f, 1.0f);
        glUniform3f(lightColorLoc3,  1.0f, 1.0f, 1.0f);
        glUniform3f(lightPosLoc3,    lightPos.x, lightPos.y, lightPos.z);
        glUniform3f(viewPosLoc3,     camera.Position.x, camera.Position.y, camera.Position.z);

        // Create camera transformations
        glm::mat4 view3;
        view3 = camera.GetViewMatrix();
        glm::mat4 projection3 = glm::perspective(camera.Zoom, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);
        // Get the uniform locations
        GLint modelLoc3 = glGetUniformLocation(paintingShader3.Program, "model");
        GLint viewLoc3  = glGetUniformLocation(paintingShader3.Program,  "view");
        GLint projLoc3  = glGetUniformLocation(paintingShader3.Program,  "projection");
        // Pass the matrices to the shader
        glUniformMatrix4fv(viewLoc3, 1, GL_FALSE, glm::value_ptr(view3));
        glUniformMatrix4fv(projLoc3, 1, GL_FALSE, glm::value_ptr(projection3));

        // Draw the container (using container's vertex attributes)
        glBindVertexArray(containerVAO3);

        glm::mat4 model3;
        // The following line modifies the location of the painting.
        model3 = glm::translate(model3, glm::vec3(4.50f, 0.0f, 9.0f)); // Translate it down a bit so it's at the center of the scene
        model3 = glm::scale(model3, glm::vec3(1.12f, 1.12f, 1.12f)); // It's a bit too big for our scene, so scale it down
        model3 = glm::rotate(model3, (glm::mediump_float)110, glm::vec3(0.0f, 1.0f, 0.0f)); //put it on the back wall 180 degree rotation
        glUniformMatrix4fv(glGetUniformLocation(paintingShader3.Program, "model3"), 1, GL_FALSE, glm::value_ptr(model3));
        paintingModel3.Draw(paintingShader3);

        glUniformMatrix4fv(modelLoc3, 1, GL_FALSE, glm::value_ptr(model3));
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);



        /* Image 4 */

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture4);
        glUniform1i(glGetUniformLocation(paintingShader4.Program, "ourTexture4"), 0);

        // Use cooresponding shader when setting uniforms/drawing objects
        paintingShader4.Use();

        GLint objectColorLoc4 = glGetUniformLocation(paintingShader4.Program, "objectColor");
        GLint lightColorLoc4  = glGetUniformLocation(paintingShader4.Program, "lightColor");
        GLint lightPosLoc4    = glGetUniformLocation(paintingShader4.Program, "lightPos");
        GLint viewPosLoc4     = glGetUniformLocation(paintingShader4.Program, "viewPos");
        glUniform3f(objectColorLoc4, 1.0f, 1.0f, 1.0f);
        glUniform3f(lightColorLoc4,  1.0f, 1.0f, 1.0f);
        glUniform3f(lightPosLoc4,    lightPos.x, lightPos.y, lightPos.z);
        glUniform3f(viewPosLoc4,     camera.Position.x, camera.Position.y, camera.Position.z);

        // Create camera transformations
        glm::mat4 view4;
        view4 = camera.GetViewMatrix();
        glm::mat4 projection4 = glm::perspective(camera.Zoom, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);
        // Get the uniform locations
        GLint modelLoc4 = glGetUniformLocation(paintingShader4.Program, "model");
        GLint viewLoc4  = glGetUniformLocation(paintingShader4.Program,  "view");
        GLint projLoc4  = glGetUniformLocation(paintingShader4.Program,  "projection");
        // Pass the matrices to the shader
        glUniformMatrix4fv(viewLoc4, 1, GL_FALSE, glm::value_ptr(view4));
        glUniformMatrix4fv(projLoc4, 1, GL_FALSE, glm::value_ptr(projection4));

        // Draw the container (using container's vertex attributes)
        glBindVertexArray(containerVAO4);

        glm::mat4 model4;
        // The following line modifies the location of the painting.
        model4 = glm::translate(model4, glm::vec3(-5.12f, 0.4f, -6.04f)); // Translate it down a bit so it's at the center of the scene
        model4 = glm::scale(model4, glm::vec3(1.12f, 1.12f, 1.12f)); // It's a bit too big for our scene, so scale it down
        glUniformMatrix4fv(glGetUniformLocation(paintingShader4.Program, "model4"), 1, GL_FALSE, glm::value_ptr(model4));
        paintingModel4.Draw(paintingShader4);

        glUniformMatrix4fv(modelLoc4, 1, GL_FALSE, glm::value_ptr(model4));
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);

         /* Image 5 */

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture5);
        glUniform1i(glGetUniformLocation(paintingShader5.Program, "ourTexture5"), 0);

        // Use cooresponding shader when setting uniforms/drawing objects
        paintingShader5.Use();

        GLint objectColorLoc5 = glGetUniformLocation(paintingShader5.Program, "objectColor");
        GLint lightColorLoc5  = glGetUniformLocation(paintingShader5.Program, "lightColor");
        GLint lightPosLoc5    = glGetUniformLocation(paintingShader5.Program, "lightPos");
        GLint viewPosLoc5     = glGetUniformLocation(paintingShader5.Program, "viewPos");
        glUniform3f(objectColorLoc5, 1.0f, 1.0f, 1.0f);
        glUniform3f(lightColorLoc5,  1.0f, 1.0f, 1.0f);
        glUniform3f(lightPosLoc5,    lightPos.x, lightPos.y, lightPos.z);
        glUniform3f(viewPosLoc5,     camera.Position.x, camera.Position.y, camera.Position.z);

        // Create camera transformations
        glm::mat4 view5;
        view5 = camera.GetViewMatrix();
        glm::mat4 projection5 = glm::perspective(camera.Zoom, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);
        // Get the uniform locations
        GLint modelLoc5 = glGetUniformLocation(paintingShader5.Program, "model");
        GLint viewLoc5  = glGetUniformLocation(paintingShader5.Program,  "view");
        GLint projLoc5  = glGetUniformLocation(paintingShader5.Program,  "projection");
        // Pass the matrices to the shader
        glUniformMatrix4fv(viewLoc5, 1, GL_FALSE, glm::value_ptr(view5));
        glUniformMatrix4fv(projLoc5, 1, GL_FALSE, glm::value_ptr(projection5));

        // Draw the container (using container's vertex attributes)
        glBindVertexArray(containerVAO5);

        glm::mat4 model5;
        // The following line modifies the location of the painting.
        model5 = glm::translate(model5, glm::vec3(-13.0f, 0.0f, 2.0f)); // Translate it down a bit so it's at the center of the scene
        model5 = glm::scale(model5, glm::vec3(1.12f, 1.12f, 1.12f)); // It's a bit too big for our scene, so scale it down
        model5 = glm::rotate(model5, (glm::mediump_float)-190.08, glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(glGetUniformLocation(paintingShader5.Program, "model5"), 1, GL_FALSE, glm::value_ptr(model5));
        paintingModel5.Draw(paintingShader5);

        glUniformMatrix4fv(modelLoc5, 1, GL_FALSE, glm::value_ptr(model5));
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);


        /* Image 6 */

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture6);
        glUniform1i(glGetUniformLocation(paintingShader6.Program, "ourTexture6"), 0);

        // Use cooresponding shader when setting uniforms/drawing objects
        paintingShader4.Use();

        GLint objectColorLoc6 = glGetUniformLocation(paintingShader6.Program, "objectColor");
        GLint lightColorLoc6  = glGetUniformLocation(paintingShader6.Program, "lightColor");
        GLint lightPosLoc6    = glGetUniformLocation(paintingShader6.Program, "lightPos");
        GLint viewPosLoc6     = glGetUniformLocation(paintingShader6.Program, "viewPos");
        glUniform3f(objectColorLoc6, 1.0f, 1.0f, 1.0f);
        glUniform3f(lightColorLoc6,  1.0f, 1.0f, 1.0f);
        glUniform3f(lightPosLoc6,    lightPos.x, lightPos.y, lightPos.z);
        glUniform3f(viewPosLoc6,     camera.Position.x, camera.Position.y, camera.Position.z);

        // Create camera transformations
        glm::mat4 view6;
        view6 = camera.GetViewMatrix();
        glm::mat4 projection6 = glm::perspective(camera.Zoom, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);
        // Get the uniform locations
        GLint modelLoc6 = glGetUniformLocation(paintingShader4.Program, "model");
        GLint viewLoc6  = glGetUniformLocation(paintingShader4.Program,  "view");
        GLint projLoc6  = glGetUniformLocation(paintingShader4.Program,  "projection");
        // Pass the matrices to the shader
        glUniformMatrix4fv(viewLoc6, 1, GL_FALSE, glm::value_ptr(view6));
        glUniformMatrix4fv(projLoc6, 1, GL_FALSE, glm::value_ptr(projection6));

        // Draw the container (using container's vertex attributes)
        glBindVertexArray(containerVAO6);

        glm::mat4 model6;
        // The following line modifies the location of the painting.
        model6 = glm::translate(model6, glm::vec3(11.90f, 0.2f, 2.0f)); // Translate it down a bit so it's at the center of the scene
        model6 = glm::scale(model6, glm::vec3(1.12f, 1.12f, 1.12f)); // It's a bit too big for our scene, so scale it down
        model6 = glm::rotate(model6, (glm::mediump_float)-190.08, glm::vec3(0.0f, 1.0f, 0.0f)); //rotate it so it's on the right side wall!
        glUniformMatrix4fv(glGetUniformLocation(paintingShader6.Program, "model6"), 1, GL_FALSE, glm::value_ptr(model6));
        paintingModel6.Draw(paintingShader6);

        glUniformMatrix4fv(modelLoc6, 1, GL_FALSE, glm::value_ptr(model6));
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);


        /* Room */

        roomShader.Use();
        GLint objectColorLocRoom = glGetUniformLocation(roomShader.Program, "objectColor");
        GLint lightColorLocRoom  = glGetUniformLocation(roomShader.Program, "lightColor");
        //GLint lightPosLocRoom1    = glGetUniformLocation(roomShader.Program, "tilelightPos");
        GLint viewPosLocRoom     = glGetUniformLocation(roomShader.Program, "viewPos");
        glUniform3f(objectColorLocRoom, 1.0f, 1.0f, 1.0f);
        glUniform3f(lightColorLocRoom,  1.0f, 1.0f, 1.0f);
        //glUniform3f(lightPosLocRoom1,    tilelightPos[0].x, tilelightPos[0].y, tilelightPos[0].z);
        //glUniform3f(lightPosLocRoom2,    tilelightPos[1].x, tilelightPos[1].y, tilelightPos[1].z);
        //glUniform3f(lightPosLocRoom3,    tilelightPos[2].x, tilelightPos[2].y, tilelightPos[2].z);
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
        modelRoom = glm::translate(modelRoom, glm::vec3(0.0f, 0.0f, 0.0f)); // Translate it down a bit so it's at the center of the scene
        modelRoom = glm::scale(modelRoom, glm::vec3(1.0f, 1.0f, 1.0f)); // It's a bit too big for our scene, so scale it down
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


//////////////////////////////////////////////////////////
// Code for keyboard and mouse interactions.  From HW3. //
//////////////////////////////////////////////////////////

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
