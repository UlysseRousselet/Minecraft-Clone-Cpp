#include "my.h"

float get_distance(float x1, float y1, float x2, float y2)
{
    float distance_x = x1 - x2;
    float distance_y = y1 - y2;
    return sqrt(distance_x * distance_x + distance_y * distance_y); 
}

float get_distance_3d(float x1, float y1, float z1, float x2, float y2, float z2)
{
    float distance_x = x1 - x2;
    float distance_y = y1 - y2;
    float distance_z = z1 - z2;
    return sqrt(distance_x * distance_x + distance_y * distance_y + distance_z * distance_z); 
}

void print_chunk(Element *actual_chunk, Mesh cube_back, Mesh cube_front, Mesh cube_right, Mesh cube_left, Mesh cube_top, Mesh cube_down, liste *chunk_list, Shader shader)
{
    float distance = get_distance(cameraPos.x, cameraPos.z, actual_chunk->pos[0] + 5, actual_chunk->pos[1] + 5);
    if (distance < RENDER_DISTANCE) {
        display_mesh_texture_indice_back(cube_back, shader, actual_chunk->chunk, actual_chunk->pos);
        display_mesh_texture_indice_front(cube_front, shader, actual_chunk->chunk, actual_chunk->pos);
        display_mesh_texture_indice_right(cube_right, shader, actual_chunk->chunk, actual_chunk->pos);
        display_mesh_texture_indice_left(cube_left, shader, actual_chunk->chunk, actual_chunk->pos);
        display_mesh_texture_indice_top(cube_top, shader, actual_chunk->chunk, actual_chunk->pos);
        display_mesh_texture_indice_down(cube_down, shader, actual_chunk->chunk, actual_chunk->pos);
    }
}

int check_if_already_exist(Element *actual_chunk, liste *chunk_list, int pos1, int pos2)
{
    Element *actual = chunk_list->premier;
    while (actual != NULL) {
        if (actual->pos[0] == pos1 && actual->pos[1] == pos2) {
            //std::cout << "hey" << std::endl;
            return 1;
        }
        actual = actual->suivant;
    }
    return 0;
}

void create_vector(liste *chunk_list, Dot_vector *vector, int pos[2])
{
    bool top_right = false;
    bool down_right = false;
    bool top_left = false;
    bool down_left = false;
    Element *actual_chunk = chunk_list->premier;
    while (actual_chunk != NULL) {
        if (pos[0] - 10 == actual_chunk->pos[0] && pos[1] == actual_chunk->pos[1]) {
            vector->top_left[0] = actual_chunk->vector->top_right[0];
            vector->top_left[1] = actual_chunk->vector->top_right[1];
            vector->down_left[0] = actual_chunk->vector->down_right[0];
            vector->down_left[1] = actual_chunk->vector->down_right[1];
            top_left = true;
            down_left = true;
        }
        if (pos[0] + 10 == actual_chunk->pos[0] && pos[1] == actual_chunk->pos[1]) {
            vector->top_right[0] = actual_chunk->vector->top_left[0];
            vector->top_right[1] = actual_chunk->vector->top_left[1];
            vector->down_right[0] = actual_chunk->vector->down_left[0];
            vector->down_right[1] = actual_chunk->vector->down_left[1];
            top_right = true;
            down_right = true;
        }
        if (pos[0] == actual_chunk->pos[0] && pos[1] + 10 == actual_chunk->pos[1]) {
            vector->top_right[0] = actual_chunk->vector->down_right[0];
            vector->top_right[1] = actual_chunk->vector->down_right[1];
            vector->top_left[0] = actual_chunk->vector->down_left[0];
            vector->top_left[1] = actual_chunk->vector->down_left[1];
            top_right = true;
            top_left = true;
        }
        if (pos[0] == actual_chunk->pos[0] && pos[1] - 10 == actual_chunk->pos[1]) {
            vector->down_right[0] = actual_chunk->vector->top_right[0];
            vector->down_right[1] = actual_chunk->vector->top_right[1];
            vector->down_left[0] = actual_chunk->vector->top_left[0];
            vector->down_left[1] = actual_chunk->vector->top_left[1];
            down_right = true;
            down_left = true;
        }
        actual_chunk = actual_chunk->suivant;
    }
    if (top_right == false) {
        set_seed_point(vector->top_right, pos[0], pos[1]);
    }
    if (top_left == false) {
        set_seed_point(vector->top_left, pos[0], pos[1]);
    }
    if (down_right == false) {
        set_seed_point(vector->down_right, pos[0], pos[1]);
    }
    if (down_left == false) {
        set_seed_point(vector->down_left, pos[0], pos[1]);
    }
}

float fade(float t) {
    return t * t * t * (t * (t * 6 - 15) + 10);
}

void smooth_grid(liste *chunk_list, int grid[10][10], int pos[2])
{
    for (int i = 0; i < 10; ++i) {
        for (int y = 0; y < 10; ++y) {
            if (i == 0) {
                Element *actual = chunk_list->premier;
                while (actual != NULL) {
                    if (pos[0] == actual->pos[0] && pos[1] == actual->pos[1] + 10) {
                        if (grid[0][y] != actual->grid[9][y]) {
                            grid[0][y] = actual->grid[9][y];
                        }
                        break;
                    }
                    actual = actual->suivant;
                }
            }
            else if (i == 9) {
                Element *actual = chunk_list->premier;
                while (actual != NULL) {
                    if (pos[0] == actual->pos[0] && pos[1] == actual->pos[1] - 10) {
                        if (grid[9][y] != actual->grid[0][y]) {
                            grid[9][y] = actual->grid[0][y];
                        }
                        break;
                    }
                    actual = actual->suivant;
                }
            } else if (y == 0) {
                Element *actual = chunk_list->premier;
                while (actual != NULL) {
                    if (pos[0] == actual->pos[0] + 10 && pos[1] == actual->pos[1]) {
                        if (grid[i][0] != actual->grid[i][9]) {
                            grid[i][0] = actual->grid[i][9];
                        }
                        break;
                    }
                    actual = actual->suivant;
                }
            } else if (y == 9) {
                Element *actual = chunk_list->premier;
                while (actual != NULL) {
                    if (pos[0] == actual->pos[0] - 10 && pos[1] == actual->pos[1]) {
                        if (grid[i][9] != actual->grid[i][0]) {
                            grid[i][9] = actual->grid[i][0];
                        }
                        break;
                    }
                    actual = actual->suivant;
                }
            }
        }
    }
    //smooth
    for (int w = 0; w < 5; ++w) {
        for (int i = 0; i < 10; ++i) {
            for (int y = 0; y < 10; ++y) {
                if (i == 0 && y == 0) {
                    grid[i][y] = (grid[i + 1][y] + grid[i][y + 1]) / 2;
                    continue;
                }
                if (i == 0 && y == 9) {
                    grid[i][y] = (grid[i + 1][y] + grid[i][y - 1]) / 2;
                    continue;
                }
                if (i == 9 && y == 9) {
                    grid[i][y] = (grid[i - 1][y] + grid[i][y - 1]) / 2;
                    continue;
                }
                if (i == 9 && y == 0) {
                    grid[i][y] = (grid[i - 1][y] + grid[i][y + 1]) / 2;
                    continue;
                }
                if (i == 0 && y != 0 && y != 9) {
                    //grid[i][y] = (grid[i + 1][y] + grid[i][y + 1] + grid[i][y - 1]) / 3;
                    continue;
                }
                if (i == 9 && y != 0 && y != 9) {
                    //grid[i][y] = (grid[i - 1][y] + grid[i][y + 1] + grid[i][y - 1]) / 3;
                    continue;
                }
                if (y == 0 && i != 0 && i != 9) {
                    //grid[i][y] = (grid[i - 1][y] + grid[i][y + 1] + grid[i + 1][y]) / 3;
                    continue;
                }
                if (y == 9 && i != 0 && i != 9) {
                    //grid[i][y] = (grid[i - 1][y] + grid[i][y - 1] + grid[i + 1][y]) / 3;
                    continue;
                }
                if (grid[i + 1][y] > grid[i][y] + 1 || grid[i + 1][y] < grid[i][y] - 1 || grid[i - 1][y] > grid[i][y] + 1 || grid[i - 1][y] < grid[i][y] - 1
                    || grid[i][y + 1] > grid[i][y] + 1 || grid[i][y + 1] < grid[i][y] - 1 || grid[i][y - 1] > grid[i][y] + 1 || grid[i][y - 1] < grid[i][y] - 1) {
                        grid[i][y] = (grid[i + 1][y] + grid[i - 1][y] + grid[i][y + 1] + grid[i][y - 1]) / 4;
                        continue;
                        //std::cout << "chunk      = " << pos[0] << " " << pos[1] <<std::endl;
                }
            }
        }
    }
}

void create_grid(liste *chunk_list, Dot_vector *vector, int grid[10][10], int pos[2], int height, int height_factor)
{
    create_vector(chunk_list, vector, pos);
    //std::cout << "Debut" << std::endl;
    for (float i = 0; i < 10; ++i) {
        for (float y = 0; y < 10; ++y) {
            float vector_to_point[2] = {y / 10.0f, i / 10.0f};
            float top_left_dot_product = vector->top_left[0] * vector_to_point[0] +  vector->top_left[1] * vector_to_point[1];
            float vector_to_point2[2] = {- (1 - y) / 10.0f, i / 10.0f};
            float top_right_dot_product = vector->top_right[0] * vector_to_point2[0] +  vector->top_right[1] * vector_to_point2[1];
            float vector_to_point3[2] = {y / 10.0f, - (1 - i) / 10.0f};
            float down_left_dot_product = vector->down_left[0] * vector_to_point3[0] +  vector->down_left[1] * vector_to_point3[1];
            float vector_to_point4[2] = {- (1 - y) / 10.0f, - (1 - i) / 10.0f};
            float down_right_dot_product = vector->down_right[0] * vector_to_point4[0] +  vector->down_right[1] * vector_to_point4[1];
            float AB = top_left_dot_product + (y / 10.0f) * (top_right_dot_product - top_left_dot_product);
            float CD = down_left_dot_product + (y / 10.f) * (down_right_dot_product - down_left_dot_product);
            float final_value = AB + (i / 10.0f) * (CD - AB);
            //std::cout << fade(final_value) << " ";
            grid[(int)i][(int)y] = (int)((fade(final_value) + 1) * height_factor) + height;
            if (grid[(int)i][(int)y] < 1)
                grid[(int)i][(int)y] = 1;
            if (grid[(int)i][(int)y] > 19)
                grid[(int)i][(int)y] = 19;
            //std::cout << grid[(int)i][(int)y] << " ";
        }
        //std::cout << std::endl;
    }
    smooth_grid(chunk_list, grid, pos);
}

void create_tree_recursive(char chunk[21][11][11], int w, int i, int y, int probality)
{
    chunk[w][i][y] = 'F';
    if (chunk[w + 1][i][y] == ' ' && random_range_int(0, probality) == 0) {
        create_tree_recursive(chunk, w + 1, i, y, probality + 1);
    }
    if (chunk[w - 1][i][y] == ' ' && random_range_int(0, probality) == 0) {
        create_tree_recursive(chunk, w - 1, i, y, probality + 2);
    }
    if (chunk[w][i + 1][y] == ' ' && random_range_int(0, probality) == 0) {
        create_tree_recursive(chunk, w, i + 1, y, probality + 1);
    }
    if (chunk[w][i - 1][y] == ' ' && random_range_int(0, probality) == 0) {
        create_tree_recursive(chunk, w, i - 1, y, probality + 1);
    }
    if (chunk[w][i][y + 1] == ' ' && random_range_int(0, probality) == 0) {
        create_tree_recursive(chunk, w, i, y + 1, probality + 1);
    }
    if (chunk[w][i][y - 1] == ' ' && random_range_int(0, probality) == 0) {
        create_tree_recursive(chunk, w, i, y - 1, probality + 1);
    }
}

void create_tree(char chunk[21][11][11], int w, int i, int y)
{
    chunk[w][i][y] = 'W';
    chunk[w + 1][i][y] = 'W';
    create_tree_recursive(chunk, w + 2, i, y, 0);
    chunk[w + 2][i][y] = 'W';
}

void create_chunk(liste *chunk_list, int pos1, int pos2, int height, int height_factor)
{
    Dot_vector *vector = reinterpret_cast<Dot_vector*>(malloc(sizeof(*vector)));
    int pos[2];
    pos[0] = pos1;
    pos[1] = pos2;
    int grid[10][10];
    create_grid(chunk_list, vector, grid, pos, height, height_factor);
    char chunk[21][11][11];
    for (int w = 19; w >= 0; --w) {
        for (int i = 0; i < 10; ++i) {
            for (int y = 0; y < 10; ++y) {
                if (w >= grid[i][y])
                    chunk[w][i][y] = ' ';
                if (w == grid[i][y] && random_range_int(0, (height_factor + 1) * 30) == 1 && w < 15 && height_factor < 4) {
                    create_tree(chunk, w, i,  y);
                }
                if (w == grid[i][y] - 1)
                    chunk[w][i][y] = '#';
                if (w < grid[i][y] - 1 && w >= grid[i][y] - 4)
                    chunk[w][i][y] = 'D';
                if (w < grid[i][y] - 4)
                    chunk[w][i][y] = 'S';
            }
        }
    }
    insertion(chunk_list, chunk, pos, vector, grid, height, height_factor);
}

int create_height(int height)
{
    int height2 = height;
    int true_or_false = random_range_int(0, 1);
    if (true_or_false == 1) {
        ++height2;
    } else {
        --height2;
    }
    if (height2 < 1)
        height2 = 1;
    if (height2 > 7)
        height2 = 7;
    return height2;
}

int create_height_factor(int height)
{
    int height2 = height;
    int true_or_false = random_range_int(0, 1);
    if (true_or_false == 1) {
        ++height2;
    } else {
        --height2;
    }
    if (height2 < 0)
        height2 = 0;
    if (height2 > 7)
        height2 = 7;
    return height2;
}

void check_for_chunk_creation(Element *actual_chunk, liste *chunk_list)
{
    int direction[4][2] = {
        {10, 0}, {0, 10}, {-10, 0}, {0, -10}
    };
    for (int i = 0; i < 4; ++i) {
        float distance = get_distance(cameraPos.x, cameraPos.z, actual_chunk->pos[0] + 5 + direction[i][0], actual_chunk->pos[1] + 5 + direction[i][1]);
        if (distance < RENDER_DISTANCE) {
            if (check_if_already_exist(actual_chunk, chunk_list, actual_chunk->pos[0] + direction[i][0], actual_chunk->pos[1] + direction[i][1]) == 0) {
                int height = create_height(actual_chunk->height);
                int height_factor = create_height_factor(actual_chunk->height_factor);
                create_chunk(chunk_list, actual_chunk->pos[0] + direction[i][0], actual_chunk->pos[1] + direction[i][1], height, height_factor);
            }
        }
    }
}

int is_seen_by_the_player(Element *actual_chunk)
{
    float distance = get_distance_3d(cameraPos.x, cameraPos.z, cameraPos.y ,actual_chunk->pos[0] + 5, actual_chunk->pos[1] + 5, 0);
    float distance2 = get_distance_3d(cameraPos.x - cameraFront.x, cameraPos.z - cameraFront.z, cameraPos.y - cameraFront.y, actual_chunk->pos[0] + 5, actual_chunk->pos[1] + 5, 0);
    if (distance < distance2) {
        return 1;
    }
    if (distance < 20)
        return 1;
    return 0;
}

void map_gestion(Mesh cube_back, Mesh cube_front, Mesh cube_right, Mesh cube_left, Mesh cube_top, Mesh cube_down, liste *chunk_list, Shader shader)
{
    Element *actual_chunk = chunk_list->premier;
    while (actual_chunk != NULL) {
        if (is_seen_by_the_player(actual_chunk)) {
            check_for_chunk_creation(actual_chunk, chunk_list);
            print_chunk(actual_chunk, cube_back, cube_front, cube_right, cube_left, cube_top, cube_down, chunk_list, shader);
        }
        actual_chunk = actual_chunk->suivant;
    }
}
