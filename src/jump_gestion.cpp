#include "my.h"

void air_gestion(liste *chunk_list)
{
    Element *actual_chunk = chunk_list->premier;
    while (actual_chunk != NULL) {
        float distance = get_distance(cameraPos.x, cameraPos.z, actual_chunk->pos[0] + 5, actual_chunk->pos[1] + 5);
        if (distance < 8) {
            for (int w = 0; w < 20; ++w) {
                for (int i = 0; i < 10; ++i) {
                    for (int y = 0; y < 10; ++y) {
                        if (cameraPos.x < y + actual_chunk->pos[0] + 0.5 && cameraPos.x > y + actual_chunk->pos[0] - 0.5
                        && cameraPos.y - 1.5 < w + 0.5 && cameraPos.y - 1.5 > w - 0.5
                        && cameraPos.z < i + actual_chunk->pos[1] + 0.5 && cameraPos.z > i + actual_chunk->pos[1] - 0.5
                        && actual_chunk->chunk[w][i][y] != ' ') {
                            is_in_air = false;
                            gravity = 0.0f;
                            break;
                        }
                    }
                }
            }
        }
        actual_chunk = actual_chunk->suivant;
    }
    cameraPos.y += gravity * deltaTime;
    gravity += -deltaTime * 20;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        collision_top_jump(chunk_list);
        if (is_in_air == false) {
            is_in_air = true;
            gravity = 7;
            cameraPos.y += 0.1f;
        }
    }
}