cmake_minimum_required(VERSION 2.8)
project(allegrotest)

include(ExternalProject)
# allegro
ExternalProject_Add(
   project_allegro
   URL ${CMAKE_CURRENT_SOURCE_DIR}/3rd-party/allegro5-5.2.2.0.tar.gz
   URL_MD5 c0c5222b2e8093c1664b7221250bc8a9
   PREFIX ${CMAKE_CURRENT_BINARY_DIR}/allegro
   CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
)

ExternalProject_Get_Property(project_allegro INSTALL_DIR)

# allegro includes
include_directories(${INSTALL_DIR}/include)

# allegro libraries
add_library(allegro SHARED IMPORTED)
set_property(TARGET allegro PROPERTY IMPORTED_LOCATION ${INSTALL_DIR}/lib/liballegro.so)

add_library(allegro_primitives SHARED IMPORTED)
set_property(TARGET allegro_primitives PROPERTY IMPORTED_LOCATION ${INSTALL_DIR}/lib/liballegro_primitives.so)

add_executable(allegrotest main.cpp)

target_link_libraries(allegrotest allegro allegro_primitives)
