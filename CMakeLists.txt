project (vulkan_tutorial_demo)

cmake_minimum_required (VERSION 2.8)

# Define CMake options
include (CMakeDependentOption)

# Use folders
set_property(GLOBAL PROPERTY USE_FOLDERS On)

# Macro to set output directories on all configurations
macro (set_output_directories OUTPUT_PATH)
    foreach (TYPE ${ARGN})
        set (CMAKE_${TYPE}_OUTPUT_DIRECTORY ${OUTPUT_PATH})
        foreach (CONFIG ${CMAKE_CONFIGURATION_TYPES})
            string (TOUPPER ${CONFIG} CONFIG)
            set (CMAKE_${TYPE}_OUTPUT_DIRECTORY_${CONFIG} ${OUTPUT_PATH})
        endforeach ()
    endforeach ()
endmacro ()

# Set output directory for executables
set_output_directories (${PROJECT_SOURCE_DIR}/bin RUNTIME PDB)

include_directories(${CMAKE_SOURCE_DIR}/includes)

add_subdirectory (src)
add_subdirectory (thire_party)