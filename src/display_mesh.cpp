#include "my.h"

void display_mesh_texture_triangle(Mesh mesh, Mesh mesh2, Shader shader)
{
    glBindTexture(GL_TEXTURE_2D, mesh.texture[0]);
    shader.use();
    shader.setMatrix4("model", mesh.model);
    shader.setMatrix4("view", view);
    shader.setMatrix4("projection", projection);
    glBindVertexArray(mesh.VAO);
        
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindTexture(GL_TEXTURE_2D, mesh2.texture[0]);
    for(unsigned int i = 0; i < 4; i++) {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.5f, 0.0f));
        float angle = 90.0f * i;
        model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
        shader.setMatrix4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }
}

void display_mesh_texture_indice(Mesh mesh, Shader shader)
{
    glBindTexture(GL_TEXTURE_2D, mesh.texture[0]);
    shader.use();
    shader.setMatrix4("model", mesh.model);
    shader.setMatrix4("view", view);
    shader.setMatrix4("projection", projection);
    glBindVertexArray(mesh.VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.EBO);
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, cameraPos + cameraFront);
    model = glm::rotate(model, glm::radians(-yaw), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(pitch), glm::vec3(0.0f, 0.0f, 1.0f));
    shader.setMatrix4("model", model);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
