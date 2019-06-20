#pragma once
#include "md5.h"
#include <string>
#include <vector>

enum VkShaderStageFlagBits;

void GlslToSpirvCached(const std::string& glsl, VkShaderStageFlagBits shader_type, std::vector<unsigned int>& spirv);

std::string GetShaderSource(const std::string& path);