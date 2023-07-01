#include "my.h"

int try_to_remove_on_this_chunk(Element *actual_chunk, float distance)
{
    for (int w = 0; w < 20; ++w) {
        for (int i = 0; i < 10; ++i) {
            for (int y = 0; y < 10; ++y) {
                if (cameraPos.x + cameraFront.x * distance < y + actual_chunk->pos[0] + 0.5 && cameraPos.x + cameraFront.x * distance > y + actual_chunk->pos[0] - 0.5
                && cameraPos.y + cameraFront.y * distance < w + 0.5 && cameraPos.y + cameraFront.y * distance > w - 0.5
                && cameraPos.z + cameraFront.z * distance < i + actual_chunk->pos[1] + 0.5 && cameraPos.z + cameraFront.z * distance > i + actual_chunk->pos[1] - 0.5
                && actual_chunk->chunk[w][i][y] != ' ') {
                    actual_chunk->chunk[w][i][y] = ' ';
                    return 1;
                }
            }
        }
    }
    return 0;
}

void remove_block(liste *chunk_list)
{
    for (float i = 0; i < 4; i += 0.1) {
        Element *actual_chunk = chunk_list->premier;
        while (actual_chunk != NULL) {
            float distance = get_distance(cameraPos.x, cameraPos.z, actual_chunk->pos[0] + 5, actual_chunk->pos[1] + 5);
            if (distance < 10) {
                if (try_to_remove_on_this_chunk(actual_chunk, i))
                    return;
            }
            actual_chunk = actual_chunk->suivant;
        }
    }
}

int check_if_has_block_on_side(char chunk[21][11][11], int w, int i, int y)
{
    if (w != 9) {
        if (chunk[w + 1][i][y] != ' ')
            return 1;
    }
    if (w != 0) {
        if (chunk[w - 1][i][y] != ' ')
            return 1;
    }
    if (i != 9) {
        if (chunk[w][i + 1][y] != ' ')
            return 1;
    }
    if (i != 0) {
        if (chunk[w][i - 1][y] != ' ')
            return 1;
    }
    if (y != 9) {
        if (chunk[w][i][y + 1] != ' ')
            return 1;
    }
    if (y != 0) {
        if (chunk[w][i][y - 1] != ' ')
            return 1;
    }
    return 0;
}

int check_if_is_on_player(Element *actual_chunk, int w, int i, int y)
{
    if (cameraPos.x < y + actual_chunk->pos[0] + 0.5 && cameraPos.x > y + actual_chunk->pos[0] - 0.5
    && cameraPos.y < w + 0.5 && cameraPos.y > w - 0.5
    && cameraPos.z < i + actual_chunk->pos[1] + 0.5 && cameraPos.z > i + actual_chunk->pos[1] - 0.5) {
        return 0;
    }
    return 1;
}

int try_to_add_on_this_chunk(Element *actual_chunk, float distance)
{
    float true_distance = 0;
    for (int w = 0; w < 20; ++w) {
        for (int i = 0; i < 10; ++i) {
            for (int y = 0; y < 10; ++y) {
                if (cameraPos.x + cameraFront.x * distance < y + actual_chunk->pos[0] + 0.5 && cameraPos.x + cameraFront.x * distance > y + actual_chunk->pos[0] - 0.5
                && cameraPos.y + cameraFront.y * distance < w + 0.5 && cameraPos.y + cameraFront.y * distance > w - 0.5
                && cameraPos.z + cameraFront.z * distance < i + actual_chunk->pos[1] + 0.5 && cameraPos.z + cameraFront.z * distance > i + actual_chunk->pos[1] - 0.5
                && actual_chunk->chunk[w][i][y] != ' ') {
                    true_distance = distance - 0.1;
                }
            }
        }
    }
    if (true_distance == 0)
        return 0;
    for (int w = 0; w < 20; ++w) {
        for (int i = 0; i < 10; ++i) {
            for (int y = 0; y < 10; ++y) {
                if (cameraPos.x + cameraFront.x * true_distance < y + actual_chunk->pos[0] + 0.5 && cameraPos.x + cameraFront.x * true_distance > y + actual_chunk->pos[0] - 0.5
                && cameraPos.y + cameraFront.y * true_distance < w + 0.5 && cameraPos.y + cameraFront.y * true_distance > w - 0.5
                && cameraPos.z + cameraFront.z * true_distance < i + actual_chunk->pos[1] + 0.5 && cameraPos.z + cameraFront.z * true_distance > i + actual_chunk->pos[1] - 0.5
                && actual_chunk->chunk[w][i][y] == ' ' && check_if_has_block_on_side(actual_chunk->chunk, w, i, y) && check_if_is_on_player(actual_chunk, w, i, y)) {
                    actual_chunk->chunk[w][i][y] = 'S';
                    return 1;
                }
            }
        }
    }
    return 0;
}

void add_block(liste *chunk_list)
{
    for (float i = 0; i < 5 ; i += 0.1) {
        Element *actual_chunk = chunk_list->premier;
        while (actual_chunk != NULL) {
            float distance = get_distance(cameraPos.x, cameraPos.z, actual_chunk->pos[0] + 5, actual_chunk->pos[1] + 5);
            if (distance < 10) {
                if (try_to_add_on_this_chunk(actual_chunk, i))
                    return;
            }
            actual_chunk = actual_chunk->suivant;
        }
    }
}