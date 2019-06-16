cmake_minimum_required(VERSION 3.1)

set (TARGET_NAME 02.instance_creation)

if(CMAKE_CL_64)
	link_directories(${CMAKE_SOURCE_DIR}/lib/x64)
else()
	link_directories(${CMAKE_SOURCE_DIR}/lib/x86)
endif()

file (GLOB SOURCE_FILES *.cpp *.h)

add_executable (${TARGET_NAME} ${SOURCE_FILES} ${HANDER_DIR} ${INLINE_DIR})

set_target_properties(${TARGET_NAME} PROPERTIES FOLDER "02.Draw_a_triangle") 

target_link_libraries (${TARGET_NAME} vulkan-1)

target_link_libraries (${TARGET_NAME} glfw3)

include_directories (${CMAKE_SOURCE_DIR}/thire_party/glfw/include)

include_directories (${CMAKE_SOURCE_DIR}/thire_party/glm)

include_directories (${CMAKE_SOURCE_DIR}/thire_party/vulkan)