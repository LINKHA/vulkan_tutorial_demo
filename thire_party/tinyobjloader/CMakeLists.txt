cmake_minimum_required(VERSION 3.1)
set(THIS_PROJECT tinyobjloader)
set(_HEADERS 
tiny_obj_loader.h
   )
	
set(_SCRS 
tiny_obj_loader.cc
)
	
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(${THIS_PROJECT} ${_SCRS} ${_HEADERS} )
set_target_properties(${THIS_PROJECT} PROPERTIES FOLDER "ThirdParty") 
set_target_properties(${THIS_PROJECT} PROPERTIES LINKER_LANGUAGE cxx) 
