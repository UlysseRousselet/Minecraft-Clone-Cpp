#include "my.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Mesh::Mesh(float vertices[], int vsize, unsigned int indices[], int isize)
{
    model = glm::mat4(1.0f);
    glGenVertexArrays(1, &VAO); 
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vsize, vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, isize, indices, GL_STATIC_DRAW);
}

Mesh::Mesh(float vertices[], int vsize)
{
    model = glm::mat4(1.0f);
    glGenVertexArrays(1, &VAO); 
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vsize, vertices, GL_STATIC_DRAW);
}

void Mesh::set_attribut_vertices(int location, int len, int total_len, int start_index)
{
    glVertexAttribPointer(location, len, GL_FLOAT, GL_FALSE, total_len * sizeof(float), (void*)(start_index * sizeof(float)));
    glEnableVertexAttribArray(location);
}

void Mesh::set_texture(const char *path, unsigned int texture_index)
{
    glGenTextures(1, &texture[texture_index]);
    glBindTexture(GL_TEXTURE_2D, texture[texture_index]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST); // GL_LINEAR sinon
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    int width, height, nrChannels;
    unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}