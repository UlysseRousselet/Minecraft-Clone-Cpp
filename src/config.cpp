#include "my.h"

GLFWwindow *window = NULL;
bool firstMouse = true;
bool mouse_clicked_right = false;
bool mouse_clicked_left = false;
bool is_in_air = true;
bool is_sprinting = false;
int seed = 1;
float Speed = 5.0f;
float cameraSpeed = 5.0f;
float yaw   = -90.0f;
float pitch =  0.0f;
float lastX =  SCREEN_WIDTH_F / 2.0;
float lastY =  SCREEN_HEIGHT_F / 2.0;
float deltaTime = 0.0f;
float lastFrame = 0.0f;
float gravity = 0.0f;
glm::vec3 cameraPos   = glm::vec3(0.0f, 20.0f, 0.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);
glm::mat4 view = glm::mat4(1.0f);
glm::mat4 projection = glm::perspective(glm::radians(90.0f), SCREEN_WIDTH_F / SCREEN_HEIGHT_F, 0.01f, 100.0f);

std::string GetcurrentDirectory()
{
	char buffer[3000];
	GetModuleFileNameA(NULL, buffer, 3000);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	
	return std::string(buffer).substr(0, pos);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void init_seed()
{
    std::string vertex_shader_str;
    std::ifstream vertex_shader_stream;
    vertex_shader_stream.open(GetcurrentDirectory().append("\\seed.txt").c_str());
    std::stringstream vertex_shader_s;
    vertex_shader_s << vertex_shader_stream.rdbuf();
    vertex_shader_str = vertex_shader_s.str();
    const char* vShader_prog = vertex_shader_str.c_str();
    for (int i = 0; i < strlen(vShader_prog); ++i) {
        seed += vShader_prog[i] * i;
    }
}

void init_all()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    //GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Project", NULL, NULL);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, true);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
    glEnable(GL_DEPTH_TEST);
    glfwSwapInterval(0);
    init_seed();
}
