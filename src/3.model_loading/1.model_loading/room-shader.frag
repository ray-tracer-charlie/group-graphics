/* Room Shader - Fragment Shader */

#version 330 core
out vec4 color;

in vec3 FragPos;  
in vec3 Normal;  
  
uniform vec3 lightPos; 
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;
//uniform vec3 tilelightPos;

struct TileLight {
    vec3 position;
};

/*
struct SpotLight {
    vec3 position;
    vec3 direction;
};
*/

uniform TileLight tilelightPos[20];
//uniform SpotLight spotlightPos[6];



// **Reference: chuyi@'s HW3 vertex shader code.

vec3 CalcTileLight(TileLight light, vec3 Normal, vec3 FragPos, vec3 viewDir);
//vec3 CalcSpotLight(DirLight light, vec3 normal, vec3 viewDir);




void main()
{     
    vec3 result;
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);

    // cycle through and calculate the light from each spotlight
/*
    for (int j = 0; j < 6; j++) {
        result += CalcSpotLight(tilelightPos[i], Normal, viewDir);
    }
*/

    for(int i = 0; i < 20; i++) {
        result += CalcTileLight(tilelightPos[i], Normal, FragPos, viewDir);
    }
    
    color = vec4(result, 1.0);
}


//reference: Opengl Multiple Lights tutorial: http://learnopengl.com/code_viewer.php?code=lighting/multiple_lights

// Calculates the color when using tile light.
vec3 CalcTileLight(TileLight light, vec3 Normal, vec3 FragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - FragPos);
    
    float ambient = 0.005f;   


    /* Diffuse lighting */
    
    // Calculate normalized vector from fragment to light.
    vec3 fragToLightVector = normalize(light.position - FragPos);
    // Compute dot product (or use 0 if the dot product is negative) as a way to determine the alignment between fragToLightVector and the Normal vector.  The greater the alignment, the stronger the diffusion lighting.  Note that Normal already has unit length.
    float diffuse = max(dot(fragToLightVector, Normal), 0.0);

    
    /* Specular lighting */
    
    // Set scaling factor.
    float specular = 0.005f;

    // Set a shininess for the object.
    float shininess = 1;
    
    // Calculate normalized vector from fragment to view.
    vec3 fragToViewVector = normalize(viewPos - FragPos);

    // Calculate normalized vector from light to fragment.
    vec3 lightToFragVector = normalize(FragPos - light.position);
    
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
    
    return (cumulativeLight * objectColor);
}

/*
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    // Diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // Specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // Combine results
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));
    return (ambient + diffuse + specular);
}
*/