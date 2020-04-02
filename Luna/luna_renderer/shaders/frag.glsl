#version 430
out vec4 FragColor;

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform bool isLightSource;

struct Material {
    sampler2D diffuse;
    vec3 specular;
    float shininess;
};

uniform Material material;


struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Light light;

void main(void)
{
        //FragColor = texture(ourTexture, TexCoord);

        if(!isLightSource)
        {

            // ambient
            vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoord));

            //diffuse
            vec3 norm = normalize(Normal);
            vec3 lightDir = normalize(lightPos - FragPos);
            float diff = max(dot(norm, lightDir), 0.0);
            vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoord));

            //specular
            float specularStrength = 0.5;
            vec3 viewDir = normalize(viewPos - FragPos);
            vec3 reflectDir = reflect(-lightDir, norm);
            float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
            vec3 specular = light.specular * (spec * material.specular);

            vec3 result = (ambient + diffuse + specular);

            FragColor = vec4(result, 1.0);
        }
        else
        {
            FragColor = vec4(lightColor * objectColor, 1.0);
        }
}
