// Fragment Shader 4

#version 330 core
out vec4 FragColor;

in vec3 FragPos;  
in vec3 Normal;  
in vec2 TexCoords;
in vec3 Color;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;
uniform sampler2D ourTexture3;
uniform sampler2D ourTexture4;
uniform sampler2D ourTexture5;
uniform sampler2D ourTexture6;

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
    vec4 txtColor = texture(ourTexture5, TexCoords);

    vec3 txtColor3;
    txtColor3[0] = txtColor[0];
    txtColor3[1] = txtColor[1];
    txtColor3[2] = txtColor[2];

    // **Reference: http://in2gpu.com/2014/06/23/toon-shading-effect-and-simple-contour-detection/
    // **Reference: http://www.lighthouse3d.com/tutorials/glsl-12-tutorial/toon-shader-version-i/
    // **Reference: http://www.lighthouse3d.com/tutorials/glsl-12-tutorial/toon-shader-version-ii/
    // **Reference: http://www.lighthouse3d.com/tutorials/glsl-12-tutorial/toon-shader-version-iii/
    // Factor used to discretize levels for toon shading.
    float threshold = 0.2f;
    float colorFactor = 1.75f;
    float lightFactor = 1.75f;

    //////////////
    // LIGHTING //
    //////////////

    // **Reference: chuyi@'s HW3 vertex shader code.

    /* Ambient lighting */

    // Choose a fraction for ambient.
    float ambient = 2.0f;


    /* Diffuse lighting */
    
    // Calculate normalized vector from fragment to light.
    vec3 fragToLightVector = normalize(lightPos - FragPos);
    
    // Compute dot product (or use 0 if the dot product is negative) as a way to determine the alignment between fragToLightVector and the Normal vector.  The greater the alignment, the stronger the diffusion lighting.  Note that Normal has unit length, from phong.frag.
    float diffuse = max(dot(fragToLightVector, Normal), 0.0);

    // Modify diffuse for toon shading.
    // **Reference: http://prideout.net/blog/?p=22.
    if (diffuse < 0.1) diffuse = 0.0f;
    else if (diffuse < 0.3) diffuse = 0.3f;
    else if (diffuse < 0.6) diffuse = 0.6f;
    else diffuse = 1.0f;
    
    /* Specular lighting */
    
    // Set scaling factor.
    float specular = 0.4f;

    // Set a shininess for the object.
    float shininess = 8;
    
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

    // Modify specular for toon shading.
    // specular = (specular < threshold) ? 0 : specular;
    specular = round(specular * lightFactor) / lightFactor;

    /* Combine all three lighting effects. */
    // Combine all three effects into a single factor.
    float cumulative = ambient + diffuse + specular;

    // Discretize cumulative depending on the range in which it falls.
    // cumulative = (cumulative < threshold) ? 0 : cumulative;
    cumulative = round(cumulative * lightFactor) / lightFactor;

    // Calculate impact on light by multiplying this combined factor with lightColor.
    vec3 cumulativeLight = cumulative * lightColor;

    vec3 toonTxtColor3;
    toonTxtColor3[0] = round(txtColor3[0] * colorFactor) / colorFactor;
    toonTxtColor3[1] = round(txtColor3[1] * colorFactor) / colorFactor;
    toonTxtColor3[2] = round(txtColor3[2] * colorFactor) / colorFactor;


    // **Reference: http://computergraphics.stackexchange.com/questions/3646/opengl-glsl-sobel-edge-detection-filter.

    mat3 sx = mat3( 
        1.0, 2.0, 1.0, 
        0.0, 0.0, 0.0, 
       -1.0, -2.0, -1.0 
    );
    mat3 sy = mat3( 
        1.0, 0.0, -1.0, 
        2.0, 0.0, -2.0, 
        1.0, 0.0, -1.0 
    );

    mat3 I;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            vec3 sample = texelFetch(ourTexture5, ivec2(FragPos) + ivec2(i-1, j-1), 0).rgb;
            I[i][j] = length(sample);
        }
    }
    
    float gx = dot(sx[0], I[0]) + dot(sx[1], I[1]) + dot(sx[2], I[2]); 
    float gy = dot(sy[0], I[0]) + dot(sy[1], I[1]) + dot(sy[2], I[2]);

    float g = sqrt(pow(gx, 2.0)+pow(gy, 2.0));
    g = smoothstep(0.4, 0.6, g);
    vec3 edgeColor = vec3(1., 0., 0.2);

    // End experimental



    // Set color by multiplying cumulativeLight with the color from the texture, and set "w"-term to 1.0f.
    FragColor = vec4(cumulativeLight * toonTxtColor3 - vec3(g), 1.0f);

}