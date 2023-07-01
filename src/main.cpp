#include "my.h"

void game_loop()
{
    float vertices_back[] = {
    -0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 0.0f
    };

    float vertices_front[] = {
    -0.5f, -0.5f, 0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, 0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, 0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, 0.5f,  1.0f, 0.0f
    };

    float vertices_right[] = {
     0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
    };

    float vertices_left[] = {
     -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
     -0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
     -0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
    };

    float vertices_top[] = {
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    };

    float vertices_down[] = {
    -0.5f,  -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  -0.5f,  0.5f,  0.0f, 0.0f,
    };

    unsigned int indices[] = {  
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    Shader monshader(GetcurrentDirectory().append("\\shader\\shader.vs").c_str(), GetcurrentDirectory().append("\\shader\\shader.fs").c_str());
    //unsigned int shaderProgram = set_up_shader();

    Mesh cube_back(vertices_back, sizeof(vertices_back), indices, sizeof(indices));
    cube_back.set_attribut_vertices(0, 3, 5, 0);
    cube_back.set_attribut_vertices(1, 2, 5, 3);
    cube_back.set_texture(GetcurrentDirectory().append("\\texture\\grass_block.jpg").c_str(), 0);
    cube_back.set_texture(GetcurrentDirectory().append("\\texture\\dirt_block.jpg").c_str(), 1);
    cube_back.set_texture(GetcurrentDirectory().append("\\texture\\stone_block.jpg").c_str(), 2);
    cube_back.set_texture(GetcurrentDirectory().append("\\texture\\wood_tree_block.jpg").c_str(), 3);
    cube_back.set_texture(GetcurrentDirectory().append("\\texture\\leaf_block.jpg").c_str(), 4);

    Mesh cube_front(vertices_front, sizeof(vertices_front), indices, sizeof(indices));
    cube_front.set_attribut_vertices(0, 3, 5, 0);
    cube_front.set_attribut_vertices(1, 2, 5, 3);
    cube_front.set_texture(GetcurrentDirectory().append("\\texture\\grass_block.jpg").c_str(), 0);
    cube_front.set_texture(GetcurrentDirectory().append("\\texture\\dirt_block.jpg").c_str(), 1);
    cube_front.set_texture(GetcurrentDirectory().append("\\texture\\stone_block.jpg").c_str(), 2);
    cube_front.set_texture(GetcurrentDirectory().append("\\texture\\wood_tree_block.jpg").c_str(), 3);
    cube_front.set_texture(GetcurrentDirectory().append("\\texture\\leaf_block.jpg").c_str(), 4);

    Mesh cube_right(vertices_right, sizeof(vertices_right), indices, sizeof(indices));
    cube_right.set_attribut_vertices(0, 3, 5, 0);
    cube_right.set_attribut_vertices(1, 2, 5, 3);
    cube_right.set_texture(GetcurrentDirectory().append("\\texture\\grass_block.jpg").c_str(), 0);
    cube_right.set_texture(GetcurrentDirectory().append("\\texture\\dirt_block.jpg").c_str(), 1);
    cube_right.set_texture(GetcurrentDirectory().append("\\texture\\stone_block.jpg").c_str(), 2);
    cube_right.set_texture(GetcurrentDirectory().append("\\texture\\wood_tree_block.jpg").c_str(), 3);
    cube_right.set_texture(GetcurrentDirectory().append("\\texture\\leaf_block.jpg").c_str(), 4);

    Mesh cube_left(vertices_left, sizeof(vertices_left), indices, sizeof(indices));
    cube_left.set_attribut_vertices(0, 3, 5, 0);
    cube_left.set_attribut_vertices(1, 2, 5, 3);
    cube_left.set_texture(GetcurrentDirectory().append("\\texture\\grass_block.jpg").c_str(), 0);
    cube_left.set_texture(GetcurrentDirectory().append("\\texture\\dirt_block.jpg").c_str(), 1);
    cube_left.set_texture(GetcurrentDirectory().append("\\texture\\stone_block.jpg").c_str(), 2);
    cube_left.set_texture(GetcurrentDirectory().append("\\texture\\wood_tree_block.jpg").c_str(), 3);
    cube_left.set_texture(GetcurrentDirectory().append("\\texture\\leaf_block.jpg").c_str(), 4);

    Mesh cube_top(vertices_top, sizeof(vertices_top), indices, sizeof(indices));
    cube_top.set_attribut_vertices(0, 3, 5, 0);
    cube_top.set_attribut_vertices(1, 2, 5, 3);
    cube_top.set_texture(GetcurrentDirectory().append("\\texture\\top_grass_block.jpg").c_str(), 0);
    cube_top.set_texture(GetcurrentDirectory().append("\\texture\\dirt_block.jpg").c_str(), 1);
    cube_top.set_texture(GetcurrentDirectory().append("\\texture\\stone_block.jpg").c_str(), 2);
    cube_top.set_texture(GetcurrentDirectory().append("\\texture\\leaf_block.jpg").c_str(), 3);

    Mesh cube_down(vertices_down, sizeof(vertices_down), indices, sizeof(indices));
    cube_down.set_attribut_vertices(0, 3, 5, 0);
    cube_down.set_attribut_vertices(1, 2, 5, 3);
    cube_down.set_texture(GetcurrentDirectory().append("\\texture\\dirt_block.jpg").c_str(), 0);
    cube_down.set_texture(GetcurrentDirectory().append("\\texture\\stone_block.jpg").c_str(), 1);
    cube_down.set_texture(GetcurrentDirectory().append("\\texture\\leaf_block.jpg").c_str(), 2);

    liste *chunk_list = initialisation();
    create_chunk(chunk_list, 0, 0, 5, 5);

    while(!glfwWindowShouldClose(window))
    {
        processInput(chunk_list);
        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        map_gestion(cube_back, cube_front, cube_right, cube_left, cube_top, cube_down, chunk_list, monshader);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    free_list(chunk_list);
    glfwDestroyWindow(window);
}

int main(int ac, char **av)
{
    init_all();
    game_loop();
    glfwTerminate();
    return 0;
}
