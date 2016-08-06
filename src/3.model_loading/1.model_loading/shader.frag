// Fragment Shader

#version 330 core
out vec4 FragColor;

in vec3 FragPos;  
in vec3 Normal;  
in vec2 TexCoords;
in vec3 Color;

uniform sampler2D ourTexture1;

uniform vec3 lightPos; 
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{

    ///////////////////////////////////
    // SET UP TEXTURE / TOON SHADING //
    ///////////////////////////////////

    // Set texture-based color.
    vec4 TxtColor = texture(ourTexture1, TexCoords);
    vec3 TxtColor3;
    TxtColor3[0] = TxtColor[0];
    TxtColor3[1] = TxtColor[1];
    TxtColor3[2] = TxtColor[2];

    // Reference: http://in2gpu.com/2014/06/23/toon-shading-effect-and-simple-contour-detection/
    // Number of lighting levels for toon shading.
    int levels = 5;

    //////////////
    // LIGHTING //
    //////////////

    // Reference: chuyi@'s HW3 fragment shader code.
    /* Ambient lighting */

    // Choose a fraction for ambient: 0.2 (arbitrarily).
    float ambient = 0.5f;   


    /* Diffuse lighting */
    
    // Calculate normalized vector from fragment to light.
    vec3 fragToLightVector = normalize(lightPos - FragPos);
    
    // Compute dot product (or use 0 if the dot product is negative) as a way to determine the alignment between fragToLightVector and the Normal vector.  The greater the alignment, the stronger the diffusion lighting.  Note that Normal has unit length, from phong.frag.
    float diffuse = max(dot(fragToLightVector, Normal), 0.0);
    // Discretize diffuse depending on the range in which it falls.
    if (diffuse < 0.25f) {
        diffuse = 0.125f;
    }
    else if (diffuse < 0.5f) {
        diffuse = 0.375f;
    }
    else if (diffuse < 0.75f) {
        diffuse = 0.625f;
    }
    else {
        diffuse = 0.875f;
    }

    
    /* Specular lighting */
    
    // Set scaling factor to be 0.2 (arbitrarily).
    float specular = 0.8f;

    // Set a shininess for the object.  LearnOpenGL uses 32, so using it here as well!
    float shininess = 16;
    
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
    // FragColor = vec4(cumulativeLight * objectColor, 1.0f);

    // TODO: Replace with below.
    FragColor = vec4(cumulativeLight * TxtColor3, 1.0f);

}