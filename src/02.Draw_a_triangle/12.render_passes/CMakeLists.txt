cmake_minimum_required(VERSION 3.10)

set (TARGET_NAME 12.render_passes)

file (GLOB SOURCE_FILES *.cpp *.h *.frag *.vert)

add_executable (${TARGET_NAME} ${SOURCE_FILES} ${HANDER_DIR} ${INLINE_DIR})

set_property(TARGET ${TARGET_NAME} PROPERTY CXX_STANDARD 17)

set_target_properties(${TARGET_NAME} PROPERTIES FOLDER "02.Draw_a_triangle") 

target_link_libraries (${TARGET_NAME} vulkan-1)

target_link_libraries (${TARGET_NAME} glfw3)

target_link_libraries (${TARGET_NAME} GlslToSpirv)

target_link_libraries (${TARGET_NAME} vulkan_spir)

include_directories (${CMAKE_SOURCE_DIR}/thire_party/glfw/include)

include_directories (${CMAKE_SOURCE_DIR}/thire_party/glm)

include_directories (${CMAKE_SOURCE_DIR}/thire_party/vulkan)

include_directories (${CMAKE_SOURCE_DIR}/thire_party/vulkan_spir)

include_directories (${CMAKE_SOURCE_DIR}/src/GlslToSpirv)