 //ceiling tile lights
glm::vec3 tilelightPos[] = {
    //right side
    glm::vec3(8.0f, 3.0f, 4.0f),
    glm::vec3(8.0f, 3.0f, 2.0f),
    glm::vec3(8.0f, 3.0f, 0.0f),
    //left side
    glm::vec3(-8.0f, 3.0f, 4.0f),
    glm::vec3(-8.0f, 3.0f, 2.0f),
    glm::vec3(-8.0f, 3.0f, 0.0f),
    //front
    glm::vec3(-6.0f, 3.0f, 0.0f),
    glm::vec3(-2.2f, 3.0f, 0.0f),
    glm::vec3(2.2f, 3.0f, 0.0f),
    glm::vec3(-6.2f, 3.0f, 0.0f),
    //back
    glm::vec3(-6.0f, 3.0f, 4.0f),
    glm::vec3(-2.2f, 3.0f, 4.0f),
    glm::vec3(2.2f, 3.0f, 4.0f),
    glm::vec3(-6.2f, 3.0f, 4.0f)
};



//Room spotlight positions
glm::vec3 spotlightPos[] = {
    glm::vec3(0.12f, 3.0f, -5.04f), //painting 1
    glm::vec3(5.12f, 3.0f, -5.04f), //painting 2
    glm::vec3(4.50f, 3.0f, 9.0f), //painting 3
    glm::vec3(-5.12f, 3.0f, -4.54f), //painting 4
    glm::vec3(-12.0f, 3.0f, 2.0f), //painting 5
    glm::vec3(10.90f, 3.0f, 2.0f) //painting 6
};

 /* Tile Lights */
        //tile lights
        /*
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureTile);
        glUniform1i(glGetUniformLocation(lightingShader.Program, "ourTextureTile"), 0);

        // Use cooresponding shader when setting uniforms/drawing objects
        lightingShader.Use();

        GLint lightPosLocRoom1    = glGetUniformLocation(roomShader.Program, "tileLights[0]");
        GLint lightPosLocRoom2    = glGetUniformLocation(roomShader.Program, "tileLights[1]");
        GLint lightPosLocRoom3    = glGetUniformLocation(roomShader.Program, "tileLights[2]");
        GLint lightPosLocRoom4    = glGetUniformLocation(roomShader.Program, "tileLights[3]");
        GLint lightPosLocRoom5    = glGetUniformLocation(roomShader.Program, "tileLights[4]");
        GLint lightPosLocRoom6    = glGetUniformLocation(roomShader.Program, "tileLights[5]");
        GLint lightPosLocRoom7    = glGetUniformLocation(roomShader.Program, "tileLights[6]");
        GLint lightPosLocRoom8    = glGetUniformLocation(roomShader.Program, "tileLights[7]");
        GLint lightPosLocRoom9    = glGetUniformLocation(roomShader.Program, "tileLights[8]");
        GLint lightPosLocRoom10    = glGetUniformLocation(roomShader.Program, "tileLights[9]");
        GLint lightPosLocRoom11    = glGetUniformLocation(roomShader.Program, "tileLights[10]");
        GLint lightPosLocRoom12    = glGetUniformLocation(roomShader.Program, "tileLights[11]");
        GLint lightPosLocRoom13    = glGetUniformLocation(roomShader.Program, "tileLights[12]");
        GLint lightPosLocRoom14    = glGetUniformLocation(roomShader.Program, "tileLights[13]");
        GLint viewPosLocRoom     = glGetUniformLocation(roomShader.Program, "viewPos");

        glUniform3f(lightPosLocRoom1,    tilelightPos[0].x, tilelightPos[0].y, tilelightPos[0].z);
        glUniform3f(lightPosLocRoom2,    tilelightPos[1].x, tilelightPos[1].y, tilelightPos[1].z);
        glUniform3f(lightPosLocRoom3,    tilelightPos[2].x, tilelightPos[2].y, tilelightPos[2].z);
        glUniform3f(lightPosLocRoom4,    tilelightPos[3].x, tilelightPos[3].y, tilelightPos[3].z);
        glUniform3f(lightPosLocRoom5,    tilelightPos[4].x, tilelightPos[4].y, tilelightPos[4].z);
        glUniform3f(lightPosLocRoom6,    tilelightPos[5].x, tilelightPos[5].y, tilelightPos[5].z);
        glUniform3f(lightPosLocRoom7,    tilelightPos[6].x, tilelightPos[6].y, tilelightPos[6].z);
        glUniform3f(lightPosLocRoom8,    tilelightPos[7].x, tilelightPos[7].y, tilelightPos[7].z);
        glUniform3f(lightPosLocRoom9,    tilelightPos[8].x, tilelightPos[8].y, tilelightPos[8].z);
        glUniform3f(lightPosLocRoom10,    tilelightPos[9].x, tilelightPos[9].y, tilelightPos[9].z);
        glUniform3f(lightPosLocRoom11,    tilelightPos[10].x, tilelightPos[10].y, tilelightPos[10].z);
        glUniform3f(lightPosLocRoom12,    tilelightPos[11].x, tilelightPos[11].y, tilelightPos[11].z);
        glUniform3f(lightPosLocRoom13,    tilelightPos[12].x, tilelightPos[12].y, tilelightPos[12].z);
        glUniform3f(lightPosLocRoom14,    tilelightPos[13].x, tilelightPos[13].y, tilelightPos[13].z);


        GLint objectColorLocTile = glGetUniformLocation(lightingShader.Program, "objectColor");
        GLint lightColorLocTile  = glGetUniformLocation(lightingShader.Program, "lightColor");
        GLint viewPosLocTile     = glGetUniformLocation(lightingShader.Program, "viewPos");
        glUniform3f(objectColorLocTile, 1.0f, 1.0f, 1.0f);
        glUniform3f(lightColorLocTile,  1.0f, 1.0f, 1.0f);
        //glUniform3f(lightPosLocTile,    lightPos.x, lightPos.y, lightPos.z);
        glUniform3f(viewPosLocTile,     camera.Position.x, camera.Position.y, camera.Position.z);

        // Create camera transformations
        glm::mat4 viewTile;
        viewTile = camera.GetViewMatrix();
        glm::mat4 projectionTile = glm::perspective(camera.Zoom, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);
        // Get the uniform locations
        GLint modelLocTile = glGetUniformLocation(lightingShader.Program, "model");
        GLint viewLocTile  = glGetUniformLocation(lightingShader.Program,  "view");
        GLint projLocTile  = glGetUniformLocation(lightingShader.Program,  "projection");
        // Pass the matrices to the shader
        glUniformMatrix4fv(viewLocTile, 1, GL_FALSE, glm::value_ptr(viewTile));
        glUniformMatrix4fv(projLocTile, 1, GL_FALSE, glm::value_ptr(projectionTile));

        // Draw the container (using container's vertex attributes)

        glm::mat4 modelTile;
        glBindVertexArray(containerVAOTile);
        for (GLuint i = 0; i < 14; i++)
        {
            modelTile = glm::mat4();
            modelTile = glm::translate(modelTile, tilelightPos[i]);
            modelTile = glm::scale(modelTile, glm::vec3(0.2f)); // Make it a smaller cube

            glUniformMatrix4fv(glGetUniformLocation(lightingShader.Program, "modelTile"), 1, GL_FALSE, glm::value_ptr(modelTile));

            tileLightModel.Draw(lightingShader);
            glUniformMatrix4fv(modelLocTile, 1, GL_FALSE, glm::value_ptr(modelTile));
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        glBindVertexArray(0);

    
        */




        // shader frag

        /* Room Shader - Fragment Shader */

#version 330 core
out vec4 color;

in vec3 FragPos;  
in vec3 Normal;  

struct TileLight {
    vec3 position;
};
  
uniform vec3 lightPos; 
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

uniform TileLight tileLights[14];
//uniform vec3 tilelightPos;

// **Reference: chuyi@'s HW3 vertex shader code.

void main()
{   
    
    vec3 result;

    for(int i = 0; i < 14; i++) {

    /* Ambient lighting */

    // Choose a fraction for ambient.
    float ambient = 0.2f;   


    /* Diffuse lighting */
    
    // Calculate normalized vector from fragment to light.
    vec3 fragToLightVector = normalize(tilelightPos[i] - FragPos);
    // Compute dot product (or use 0 if the dot product is negative) as a way to determine the alignment between fragToLightVector and the Normal vector.  The greater the alignment, the stronger the diffusion lighting.  Note that Normal already has unit length.
    float diffuse = max(dot(fragToLightVector, Normal), 0.0);

    
    /* Specular lighting */
    
    // Set scaling factor.
    float specular = 0.1f;

    // Set a shininess for the object.
    float shininess = 4;
    
    // Calculate normalized vector from fragment to view.
    vec3 fragToViewVector = normalize(viewPos - FragPos);

    // Calculate normalized vector from light to fragment.
    vec3 lightToFragVector = normalize(FragPos - tilelightPos[i]);
    
    // Calculate reflection of lightToFragVector across the Normal.  In the model, we assume that light from a source reflects across the Normal.
    vec3 reflectionVector = reflect(lightToFragVector, Normal);

    // Calculate the highlight by computing the dot product (or use 0 if the dot product is negative) between (1) the vector from the fragment to the view and (2) the vector representing the reflection of the light.  We take this to the power of the shininess of the object.
    float highlight = pow(max(dot(fragToViewVector, reflectionVector), 0.0), shininess);
    
    // Scale the specular lighting by this highlight.
    specular *= highlight;

    /* Combine all three lighting effects. */
    // Combine all three effects into a single factor.
    float cumulative = ambient + diffuse + specular;
    // Calculate impact on light by multiplying this combined factor with lightColor.
    vec3 cumulativeLight = cumulative * lightColor;
    // Set color by multiplying cumulativeLight with objectColor, and set "w"-term to 1.0f.
    result += cumulativeLight * objectColor;
    }
    
    color = vec4(result, 1.0f)
}