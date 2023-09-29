#ifndef KINETIC_SHADERPROGRAM_H
#define KINETIC_SHADERPROGRAM_H

#include "cglm/cglm.h"

typedef enum shader_type {
    SHADER_TYPE_VERTEX,
    SHADER_TYPE_FRAGMENT,
} shader_type;

typedef struct ShaderProgram ShaderProgram;

ShaderProgram *shaderProgram_create();
void shaderProgram_destroy(ShaderProgram *program);

void shaderProgram_attach(ShaderProgram *this, const char *file_name, shader_type shader_type);
void shaderProgram_link(ShaderProgram *this);
void shaderProgram_use(ShaderProgram *this);

void shaderProgram_add_uniform(ShaderProgram *this, const char *varName);
void shaderProgram_set_float(ShaderProgram *this, const char *varName, float value);
void shaderProgram_set_vec3(ShaderProgram *this, const char *varName, vec3 value);
void shaderProgram_set_vec4(ShaderProgram *this, const char *varName, vec4 value);

#endif//KINETIC_SHADERPROGRAM_H
