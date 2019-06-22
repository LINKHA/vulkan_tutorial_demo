#pragma once

#include <string>
#include <vector>
#include "vulkan_include.h"

enum VkShaderStageFlagBits;

void ToSpirv_Init();

std::vector<unsigned int>& ToSpirv_GetSpirv(const std::string& glsl, VkShaderStageFlagBits shader_type, std::vector<unsigned int>& spirv);

std::string ToSpirv_GetShaderSource(const std::string& path);

const std::string ToSpirv_GetDataPath();

