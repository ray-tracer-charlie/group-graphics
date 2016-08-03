#version 330 core
out vec4 FragColor;

in VS_OUT {
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
    vec3 Color;
} fs_in;

uniform sampler2D ourTexture1;
uniform bool blinn;

uniform vec3 lightPos; 
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{
    vec4 tex = texture(ourTexture1, fs_in.TexCoords); // works

    // objectColor = texture(ourTexture1, fs_in.TexCoords);

    /* Use one of the below */
    // vec3 color = texture(ourTexture1, fs_in.TexCoords).rgb;
    // vec3 color = texture(ourTexture1, fs_in.TexCoords);
    // vec3 color = fs_in.Color;  // works
    
    vec3 color;
    color[0] = tex[0];
    color[1] = tex[1];
    color[2] = tex[2];

    // Ambient
    vec3 ambient = 0.1f * color;

    // Diffuse
    vec3 lightDir = normalize(lightPos - fs_in.FragPos);
    vec3 normal = normalize(fs_in.Normal);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = diff * color;
    
    // Specular
    vec3 viewDir = normalize(viewPos - fs_in.FragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = 0.5f;
    vec3 halfwayDir = normalize(lightDir + viewDir);  
    spec = pow(max(dot(normal, halfwayDir), 0.0), 32.0);
    vec3 specular = vec3(1) * spec; // assuming bright white light color

    // Calculate impact on light by multiplying this combined factor with lightColor.
    vec3 cumulativeLight = vec3(ambient + diffuse + specular) * lightColor;

    /* Use one of the below */
    // FragColor = vec4(cumulativeLight * objectColor, 1.0f);
    FragColor = vec4(cumulativeLight * objectColor, 1.0f); // works
    // FragColor = vec4(cumulativeLight * color, 1.0f);
    // FragColor = vec4(ambient + diffuse + specular, 1.0f);
    // FragColor = vec4(cumulativeLight * texture(ourTexture1, fs_in.TexCoords), 1.0f);
    // FragColor = texture(texture_diffuse1, fs_in.TexCoords) * vec4(fs_in.Color, 1.0);

}