#include "my.h"

void collision(liste *chunk_list, int direction)
{
    Element *actual_chunk = chunk_list->premier;
    while (actual_chunk != NULL) {
        float distance = get_distance(cameraPos.x, cameraPos.z, actual_chunk->pos[0] + 5, actual_chunk->pos[1] + 5);
        if (distance < 8) {
            for (int w = 0; w < 20; ++w) {
                for (int i = 0; i < 10; ++i) {
                    for (int y = 0; y < 10; ++y) {
                        if (cameraPos.x < y + actual_chunk->pos[0] + 0.5 && cameraPos.x > y + actual_chunk->pos[0] - 0.5
                        && (cameraPos.y - 0.5 < w + 0.5 && cameraPos.y - 0.5 > w - 0.5 || cameraPos.y + 0.5 < w + 0.5 && cameraPos.y + 0.5 > w - 0.5)
                        && cameraPos.z < i + actual_chunk->pos[1] + 0.5 && cameraPos.z > i + actual_chunk->pos[1] - 0.5
                        && actual_chunk->chunk[w][i][y] != ' ') {
                            if (direction == 1) {
                                cameraPos -= cameraSpeed * glm::vec3(cameraFront.x / cos(glm::radians(pitch)), 0 ,cameraFront.z / cos(glm::radians(pitch)));
                                return;
                            }
                            if (direction == 2) {
                                cameraPos += cameraSpeed * glm::vec3(cameraFront.x / cos(glm::radians(pitch)), 0 ,cameraFront.z / cos(glm::radians(pitch)));
                                return;
                            }
                            if (direction == 3) {
                                cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
                                return;
                            }
                            if (direction == 4) {
                                cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
                                return;
                            }
                        }
                    }
                }
            }
        }
        actual_chunk = actual_chunk->suivant;
    }
}

void collision_top_jump(liste *chunk_list)
{
    Element *actual_chunk = chunk_list->premier;
    while (actual_chunk != NULL) {
        float distance = get_distance(cameraPos.x, cameraPos.z, actual_chunk->pos[0] + 5, actual_chunk->pos[1] + 5);
        if (distance < 8) {
            for (int w = 0; w < 20; ++w) {
                for (int i = 0; i < 10; ++i) {
                    for (int y = 0; y < 10; ++y) {
                        if (cameraPos.x < y + actual_chunk->pos[0] + 0.5 && cameraPos.x > y + actual_chunk->pos[0] - 0.5
                        && cameraPos.y + 0.2 < w + 0.5 && cameraPos.y + 0.2 > w - 0.5
                        && cameraPos.z < i + actual_chunk->pos[1] + 0.5 && cameraPos.z > i + actual_chunk->pos[1] - 0.5
                        && actual_chunk->chunk[w][i][y] != ' ') {
                            gravity = -0.1f;
                            return;
                        }
                    }
                }
            }
        }
        actual_chunk = actual_chunk->suivant;
    }
}

