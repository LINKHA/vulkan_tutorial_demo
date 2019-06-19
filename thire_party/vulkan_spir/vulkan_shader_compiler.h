#pragma once

#include "vulkan_include.h"
#include <vector>
#include <string.h>

void InitShaderCompiler();
bool GlslToSpv(const VkShaderStageFlagBits shader_type, const char* src, Vector<unsigned int>& spirv, String& error);
void DeinitShaderCompiler();
