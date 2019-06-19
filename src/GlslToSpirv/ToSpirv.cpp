#include "ToSpirv.h"
#include <vulkan/vulkan.h>
#include <vulkan_shader_compiler.h>
#include <stdarg.h>
#include <fstream>
#include <assert.h>


std::string gFormat(const char* format, ...)
{
	std::string result;

	va_list vs;
	va_start(vs, format);
	int size = vsnprintf(nullptr, 0, format, vs);
	va_end(vs);

	char* buffer = (char*)malloc(size + 1);
	buffer[size] = 0;

	va_start(vs, format);
	size = vsnprintf(buffer, size + 1, format, vs);
	va_end(vs);

	result = buffer;

	free(buffer);

	return result;
}
bool gFileExist(const std::string& path)
{
	std::ifstream is(path.c_str(), std::ios::binary);

	bool exist = !(!is);

	if (exist)
	{
		is.close();
	}

	return exist;
}

unsigned char* gReadAllBytes(const std::string& path)
{
	//ByteBuffer buffer;
	unsigned char* buffer;

	std::ifstream is(path.c_str(), std::ios::binary);
	if (is)
	{
		is.seekg(0, std::ios::end);
		int size = (int)is.tellg();
		is.seekg(0, std::ios::beg);

		buffer = (unsigned char*)malloc(size);
		
		is.read((char*)buffer, size);
		is.close();
	}

	return buffer;
}

int gReadSize(const std::string& path)
{
	std::ifstream is(path.c_str(), std::ios::binary);
	int size;
	if (is)
	{
		is.seekg(0, std::ios::end);
		size = (int)is.tellg();
		is.seekg(0, std::ios::beg);
		is.close();
	}

	return size;
}

bool gWriteAllBytes(const std::string& path, unsigned char* buffer,int size)
{
	std::ofstream os(path.c_str(), std::ios::binary);
	if (os)
	{
		os.write((const char*)buffer, size);
		os.close();

		return true;
	}
	else
	{
		return false;
	}
}

void GlslToSpirvCached(const std::string& glsl, VkShaderStageFlagBits shader_type, std::vector<unsigned int>& spirv)
{
	unsigned char hash_bytes[16];
	MD5_CTX md5_context;
	MD5_Init(&md5_context);
	MD5_Update(&md5_context, (void*)glsl.c_str(), glsl.size());
	MD5_Final(hash_bytes, &md5_context);
	std::string md5_str;
	for (int i = 0; i < sizeof(hash_bytes); ++i)
	{
		md5_str += gFormat("%02x", hash_bytes[i]);
	}

	//std::string cache_path = Application::Instance()->GetSavePath() + "/" + md5_str + ".cache";
	if (gFileExist(cache_path))
	{
		auto buffer = gReadAllBytes(cache_path);
		auto size = gReadSize(cache_path);
		spirv.resize(size / 4);
		memcpy(&spirv[0], buffer, size);
	}
	else
	{
		std::string error;
		bool success = GlslToSpv(shader_type, glsl.c_str(), spirv, error);
		if (!success)
		{
			//Log("shader compile error: %s", error.c_str());
		}
		assert(success);
		unsigned char* buffer;
		int bufferSize = sizeof(unsigned int) * spirv.size();
		buffer = (unsigned char*)malloc(bufferSize);
		memcpy(buffer, &spirv[0], bufferSize);
		gWriteAllBytes(cache_path, buffer, bufferSize);
	}
}
