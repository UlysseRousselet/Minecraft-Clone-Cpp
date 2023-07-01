#include "my.h"

void display_mesh_texture_indice_back(Mesh mesh, Shader shader, char chunk[21][11][11], int pos[2])
{
    shader.use();
    shader.setMatrix4("model", mesh.model);
    shader.setMatrix4("view", view);
    shader.setMatrix4("projection", projection);
    glBindVertexArray(mesh.VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.EBO);
    for (int w = 0; w < 20; ++w) {
        for (int i = 0; i < 10; ++i) {
            for (int y = 0; y < 10; ++y) {
                if (chunk[w][i][y] != ' ') {
                    if (cameraPos.z < i + pos[1]) {
                        if (chunk[w][i][y] == '#')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[0]);
                        if (chunk[w][i][y] == 'D')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[1]);
                        if (chunk[w][i][y] == 'S')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[2]);
                        if (chunk[w][i][y] == 'W')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[3]);
                        if (chunk[w][i][y] == 'F')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[4]);
                        if (i == 0) {
                            glm::mat4 model = glm::mat4(1.0f);
                            model = glm::translate(model, glm::vec3(y + pos[0], w, i + pos[1]));
                            shader.setMatrix4("model", model);
                            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
                        } else if (chunk[w][i - 1][y] == ' ') {
                            glm::mat4 model = glm::mat4(1.0f);
                            model = glm::translate(model, glm::vec3(y + pos[0], w, i + pos[1]));
                            shader.setMatrix4("model", model);
                            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
                        }
                    }
                }
            }
        }
    }
}

void display_mesh_texture_indice_front(Mesh mesh, Shader shader, char chunk[21][11][11], int pos[2])
{
    shader.use();
    shader.setMatrix4("model", mesh.model);
    shader.setMatrix4("view", view);
    shader.setMatrix4("projection", projection);
    glBindVertexArray(mesh.VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.EBO);
    for (int w = 0; w < 20; ++w) {
        for (int i = 0; i < 10; ++i) {
            for (int y = 0; y < 10; ++y) {
                if (chunk[w][i][y] != ' ') {
                    if (cameraPos.z > i + pos[1]) {
                        if (chunk[w][i][y] == '#')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[0]);
                        if (chunk[w][i][y] == 'D')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[1]);
                        if (chunk[w][i][y] == 'S')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[2]);
                        if (chunk[w][i][y] == 'W')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[3]);
                        if (chunk[w][i][y] == 'F')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[4]);
                        if (i == 9) {
                            glm::mat4 model = glm::mat4(1.0f);
                            model = glm::translate(model, glm::vec3(y + pos[0], w, i + pos[1]));
                            shader.setMatrix4("model", model);
                            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
                        } else if (chunk[w][i + 1][y] == ' ') {
                            glm::mat4 model = glm::mat4(1.0f);
                            model = glm::translate(model, glm::vec3(y + pos[0], w, i + pos[1]));
                            shader.setMatrix4("model", model);
                            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
                        }
                    }
                }
            }
        }
    }
}

void display_mesh_texture_indice_right(Mesh mesh, Shader shader, char chunk[21][11][11], int pos[2])
{
    shader.use();
    shader.setMatrix4("model", mesh.model);
    shader.setMatrix4("view", view);
    shader.setMatrix4("projection", projection);
    glBindVertexArray(mesh.VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.EBO);
    for (int w = 0; w < 20; ++w) {
        for (int i = 0; i < 10; ++i) {
            for (int y = 0; y < 10; ++y) {
                if (chunk[w][i][y] != ' ') {
                    if (cameraPos.x > y + pos[0]) {
                        if (chunk[w][i][y] == '#')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[0]);
                        if (chunk[w][i][y] == 'D')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[1]);
                        if (chunk[w][i][y] == 'S')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[2]);
                        if (chunk[w][i][y] == 'W')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[3]);
                        if (chunk[w][i][y] == 'F')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[4]);
                        if (y == 9) {
                            glm::mat4 model = glm::mat4(1.0f);
                            model = glm::translate(model, glm::vec3(y + pos[0], w, i + pos[1]));
                            shader.setMatrix4("model", model);
                            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
                        } else if (chunk[w][i][y + 1] == ' ') {
                            glm::mat4 model = glm::mat4(1.0f);
                            model = glm::translate(model, glm::vec3(y + pos[0], w, i + pos[1]));
                            shader.setMatrix4("model", model);
                            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
                        }
                    }
                }
            }
        }
    }
}

void display_mesh_texture_indice_left(Mesh mesh, Shader shader, char chunk[21][11][11], int pos[2])
{
    shader.use();
    shader.setMatrix4("model", mesh.model);
    shader.setMatrix4("view", view);
    shader.setMatrix4("projection", projection);
    glBindVertexArray(mesh.VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.EBO);
    for (int w = 0; w < 20; ++w) {
        for (int i = 0; i < 10; ++i) {
            for (int y = 0; y < 10; ++y) {
                if (chunk[w][i][y] != ' ') {
                    if (cameraPos.x < y + pos[0]) {
                        if (chunk[w][i][y] == '#')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[0]);
                        if (chunk[w][i][y] == 'D')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[1]);
                        if (chunk[w][i][y] == 'S')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[2]);
                        if (chunk[w][i][y] == 'W')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[3]);
                        if (chunk[w][i][y] == 'F')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[4]);
                        if (y == 0) {
                            glm::mat4 model = glm::mat4(1.0f);
                            model = glm::translate(model, glm::vec3(y + pos[0], w, i + pos[1]));
                            shader.setMatrix4("model", model);
                            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
                        } else if (chunk[w][i][y - 1] == ' ') {
                            glm::mat4 model = glm::mat4(1.0f);
                            model = glm::translate(model, glm::vec3(y + pos[0], w, i + pos[1]));
                            shader.setMatrix4("model", model);
                            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
                        }
                    }
                }
            }
        }
    }
}

void display_mesh_texture_indice_top(Mesh mesh, Shader shader, char chunk[21][11][11], int pos[2])
{
    shader.use();
    shader.setMatrix4("model", mesh.model);
    shader.setMatrix4("view", view);
    shader.setMatrix4("projection", projection);
    glBindVertexArray(mesh.VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.EBO);
    for (int w = 0; w < 20; ++w) {
        for (int i = 0; i < 10; ++i) {
            for (int y = 0; y < 10; ++y) {
                if (chunk[w][i][y] != ' ') {
                    if (cameraPos.y > w) {
                        if (chunk[w][i][y] == '#')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[0]);
                        if (chunk[w][i][y] == 'D')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[1]);
                        if (chunk[w][i][y] == 'S')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[2]);
                        if (chunk[w][i][y] == 'F')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[3]);
                        if (w == 19) {
                            glm::mat4 model = glm::mat4(1.0f);
                            model = glm::translate(model, glm::vec3(y + pos[0], w, i + pos[1]));
                            shader.setMatrix4("model", model);
                            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
                        } else if (chunk[w + 1][i][y] == ' ') {
                            glm::mat4 model = glm::mat4(1.0f);
                            model = glm::translate(model, glm::vec3(y + pos[0], w, i + pos[1]));
                            shader.setMatrix4("model", model);
                            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
                        }
                    }
                }
            }
        }
    }
}

void display_mesh_texture_indice_down(Mesh mesh, Shader shader, char chunk[21][11][11], int pos[2])
{
    shader.use();
    shader.setMatrix4("model", mesh.model);
    shader.setMatrix4("view", view);
    shader.setMatrix4("projection", projection);
    glBindVertexArray(mesh.VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.EBO);
    for (int w = 0; w < 20; ++w) {
        for (int i = 0; i < 10; ++i) {
            for (int y = 0; y < 10; ++y) {
                if (chunk[w][i][y] != ' ') {
                    if (cameraPos.y < w) {
                        if (chunk[w][i][y] == 'S')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[1]);
                        else if (chunk[w][i][y] == 'F')
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[2]);
                        else
                            glBindTexture(GL_TEXTURE_2D, mesh.texture[0]);
                        if (w == 0) {
                            glm::mat4 model = glm::mat4(1.0f);
                            model = glm::translate(model, glm::vec3(y + pos[0], w, i + pos[1]));
                            shader.setMatrix4("model", model);
                            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
                        } else if (chunk[w - 1][i][y] == ' ') {
                            glm::mat4 model = glm::mat4(1.0f);
                            model = glm::translate(model, glm::vec3(y + pos[0], w, i + pos[1]));
                            shader.setMatrix4("model", model);
                            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
                        }
                    }
                }
            }
        }
    }
}
