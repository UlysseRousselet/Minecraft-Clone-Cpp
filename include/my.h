#ifndef __MY_H_
    #define __MY_H_
    #include <iostream>
    #include <fstream>
    #include <sstream>
    #include <cstring>
    #include <string>
    #include <cmath>
    #include <cstdlib>
    #include <random>
    #include <glad/glad.h>
    #include <GLFW/glfw3.h>
    #include <glm/glm.hpp>
    #include <glm/gtc/matrix_transform.hpp>
    #include <glm/gtc/type_ptr.hpp>
    #define SCREEN_WIDTH 1920
    #define SCREEN_HEIGHT 1080
    #define SCREEN_WIDTH_F 1920.0f
    #define SCREEN_HEIGHT_F 1080.0f
    #define RENDER_DISTANCE 50

typedef struct Dot_vector Dot_vector;
typedef struct Dot_vector {
    float top_right[2];
    float down_right[2];
    float top_left[2];
    float down_left[2];
}Dot_vector;

typedef struct Element Element;
typedef struct Element {
    int pos[2];
    int grid[10][10];
    char chunk[21][11][11];
    int height;
    int height_factor;
    Dot_vector *vector;
    Element *suivant;
} Element;

typedef struct liste liste;
typedef struct liste {
    Element *premier;
    Element *dernier;
} liste;

class Shader
{
    public:
    unsigned int program_id;
    Shader(const char* vertex_shader, const char* fragment_shader);
    void use();
    void setBool(const std::string &name, bool value) const;  
    void setInt(const std::string &name, int value) const;   
    void setFloat(const std::string &name, float value) const;
    void setMatrix4(const std::string &name, glm::mat4 value) const;
};

class Mesh
{
    public:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    unsigned int texture[100];
    glm::mat4 model;
    Mesh(float vertices[], int vsize, unsigned int indices[], int isize);
    Mesh(float vertices[], int vsize);
    void set_attribut_vertices(int location, int len, int total_len, int start_index);
    void set_texture(const char *path, unsigned int texture_index);
};

void init_all();
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void processInput(liste *chunk_list);
void display_mesh_texture_triangle(Mesh mesh, Mesh mesh2, Shader shader);
void display_mesh_texture_indice(Mesh mesh, Shader shader);
void display_mesh_texture_indice_back(Mesh mesh, Shader shader, char chunk[21][11][11], int pos[2]);
void display_mesh_texture_indice_front(Mesh mesh, Shader shader, char chunk[21][11][11], int pos[2]);
void display_mesh_texture_indice_right(Mesh mesh, Shader shader, char chunk[21][11][11], int pos[2]);
void display_mesh_texture_indice_left(Mesh mesh, Shader shader, char chunk[21][11][11], int pos[2]);
void display_mesh_texture_indice_top(Mesh mesh, Shader shader, char chunk[21][11][11], int pos[2]);
void display_mesh_texture_indice_down(Mesh mesh, Shader shader, char chunk[21][11][11], int pos[2]);
void map_gestion(Mesh cube_back, Mesh cube_front, Mesh cube_right, Mesh cube_left, Mesh cube_top, Mesh cube_down, liste *chunk_list, Shader shader);
liste *initialisation(void);
void insertion(liste *liste, char chunk[21][11][11], int pos[2], Dot_vector *vector, int grid[10][10], int height, int height_factor);
void supprimer(liste *liste);
void show_liste(liste *liste);
int get_len(Element *actuel);
void free_list(liste *liste);
void remove_block(liste *chunk_list);
float get_distance(float x1, float y1, float x2, float y2);
void add_block(liste *chunk_list);
void create_chunk(liste *chunk_list, int pos1, int pos2, int height, int height_factor);
void set_seed_point(float point[2], int x, int z);
void air_gestion(liste *chunk_list);
void collision(liste *chunk_list, int direction);
void collision_top_jump(liste *chunk_list);
bool randomBool();
int random_range_int(int range_min, int range_max);
float get_distance_3d(float x1, float y1, float z1, float x2, float y2, float z2);
std::string GetcurrentDirectory();

extern GLFWwindow *window;
extern int seed;
extern bool firstMouse;
extern bool mouse_clicked_right;
extern bool mouse_clicked_left;
extern bool is_in_air;
extern bool is_sprinting;
extern float Speed;
extern float cameraSpeed;
extern float yaw;
extern float pitch;
extern float lastX;
extern float lastY;
extern float deltaTime;
extern float lastFrame;
extern float gravity;
extern glm::vec3 cameraPos;
extern glm::vec3 cameraFront;
extern glm::vec3 cameraUp;
extern glm::mat4 view;
extern glm::mat4 projection;

#endif