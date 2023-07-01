#include "my.h"

static void sprint()
{
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && is_sprinting == false) {
        is_sprinting = true;
        Speed = 7.0f;
        //cameraPos.y -= cameraSpeed;
        projection = glm::perspective(glm::radians(100.0f), SCREEN_WIDTH_F / SCREEN_HEIGHT_F, 0.01f, 100.0f);
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE && is_sprinting == true) {
        is_sprinting = false;
        Speed = 5.0f;
        projection = glm::perspective(glm::radians(90.0f), SCREEN_WIDTH_F / SCREEN_HEIGHT_F, 0.01f, 100.0f);
    }
    cameraSpeed = Speed * deltaTime;
}

static void deplacement(liste *chunk_list)
{
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        cameraPos += cameraSpeed * glm::vec3(cameraFront.x / cos(glm::radians(pitch)), 0 ,cameraFront.z / cos(glm::radians(pitch)));
        collision(chunk_list, 1);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        cameraPos -= cameraSpeed * glm::vec3(cameraFront.x / cos(glm::radians(pitch)), 0 ,cameraFront.z / cos(glm::radians(pitch)));
        collision(chunk_list, 2);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
        collision(chunk_list, 3);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
        collision(chunk_list, 4);
    }
}

static void mouse_move_and_click(liste *chunk_list)
{
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS && mouse_clicked_right == false) {
        mouse_clicked_right = true;
        add_block(chunk_list);
    }
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE && mouse_clicked_right == true)
        mouse_clicked_right = false;

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && mouse_clicked_left == false) {
        mouse_clicked_left = true;
        remove_block(chunk_list);
    }
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE && mouse_clicked_left == true)
        mouse_clicked_left = false;
}

void processInput(liste *chunk_list)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    air_gestion(chunk_list);
    sprint();
    //cameraPos.y += cameraSpeed;
    deplacement(chunk_list);
    mouse_move_and_click(chunk_list);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
  
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; 
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw   += xoffset;
    pitch += yoffset;

    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(direction);
}

