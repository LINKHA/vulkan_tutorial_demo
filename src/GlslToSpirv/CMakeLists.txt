cmake_minimum_required(VERSION 3.1)

set (TARGET_NAME GlslToSpirv)

file (GLOB SOURCE_FILES *.cpp *.h *.c)

add_library(${TARGET_NAME} ${SOURCE_FILES} )

set_target_properties(${TARGET_NAME} PROPERTIES FOLDER "Tool") 

set_target_properties(${THIS_PROJECT} PROPERTIES LINKER_LANGUAGE cxx) 

include_directories (${CMAKE_SOURCE_DIR}/thire_party/vulkan)

target_link_libraries (${TARGET_NAME} vulkan-1)

include_directories (${CMAKE_SOURCE_DIR}/thire_party/vulkan_spir)

target_link_libraries (${TARGET_NAME} vulkan_spir)