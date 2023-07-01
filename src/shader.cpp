#include "my.h"

Shader::Shader(const char* vertex_shader, const char* fragment_shader)
{
    std::string vertex_shader_str;
    std::string fragment_shader_str;
    std::ifstream vertex_shader_stream;
    std::ifstream fragment_shader_stream;
    vertex_shader_stream.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fragment_shader_stream.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        vertex_shader_stream.open(vertex_shader);
        fragment_shader_stream.open(fragment_shader);
        std::stringstream vertex_shader_s;
        std::stringstream fragment_shader_s;
        vertex_shader_s << vertex_shader_stream.rdbuf();
        fragment_shader_s << fragment_shader_stream.rdbuf();
        vertex_shader_str = vertex_shader_s.str();
        fragment_shader_str = fragment_shader_s.str();
    }
    catch(std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char* vShader_prog = vertex_shader_str.c_str();
    const char* fShader_prog = fragment_shader_str.c_str();
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShader_prog, NULL);
    glCompileShader(vertexShader);
    // fragment shader
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShader_prog, NULL);
    glCompileShader(fragmentShader);
    // shader program
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    program_id = shaderProgram;
}

void Shader::use()
{
    glUseProgram(program_id);
}

void Shader::setBool(const std::string &name, bool value) const
{         
    glUniform1i(glGetUniformLocation(program_id, name.c_str()), (int)value); 
}
void Shader::setInt(const std::string &name, int value) const
{ 
    glUniform1i(glGetUniformLocation(program_id, name.c_str()), value); 
}
void Shader::setFloat(const std::string &name, float value) const
{ 
    glUniform1f(glGetUniformLocation(program_id, name.c_str()), value); 
}

void Shader::setMatrix4(const std::string &name, glm::mat4 value) const
{ 
    glUniformMatrix4fv(glGetUniformLocation(program_id, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
} 