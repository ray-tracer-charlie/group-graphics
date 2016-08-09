/* Room Shader - Fragment Shader */

#version 330 core
out vec4 color;

in vec3 FragPos;  
in vec3 Normal;  
  
uniform vec3 lightPos; 
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;
uniform vec3 tilelightPos;

// **Reference: chuyi@'s HW3 vertex shader code.

void main()
{   
    /* Ambient lighting */

    // Choose a fraction for ambient.
    float ambient = 0.2f;  	


    /* Diffuse lighting */
    
    // Calculate normalized vector from fragment to light.
    vec3 fragToLightVector = normalize(lightPos - FragPos);
    // Compute dot product (or use 0 if the dot product is negative) as a way to determine the alignment between fragToLightVector and the Normal vector.  The greater the alignment, the stronger the diffusion lighting.  Note that Normal already has unit length.
    float diffuse = max(dot(fragToLightVector, Normal), 0.0);

    
    /* Specular lighting */
    
    // Set scaling factor.
    float specular = 0.05f;

    // Set a shininess for the object.
    float shininess = 4;
    
    // Calculate normalized vector from fragment to view.
    vec3 fragToViewVector = normalize(viewPos - FragPos);

    // Calculate normalized vector from light to fragment.
    vec3 lightToFragVector = normalize(FragPos - lightPos);
    
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
    color = vec4(cumulativeLight * objectColor, 1.0f);
}