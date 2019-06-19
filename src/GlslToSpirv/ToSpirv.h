#pragma once
#include "md5.h"
#include <string>
#include <vector>

void GlslToSpirvCached(const std::string& glsl, VkShaderStageFlagBits shader_type, std::vector<unsigned int>& spirv);