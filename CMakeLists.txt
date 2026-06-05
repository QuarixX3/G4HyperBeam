cmake_minimum_required(VERSION 3.16...3.27)
project(HyperBeam)

find_package (Geant4 REQUIRED gdml)
include (${Geant4_USE_FILE})

find_package (ROOT REQUIRED)
include (${ROOT_USE_FILE})

file (GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cxx)
file (GLOB headers ${PROJECT_SOURCE_DIR}/include/*.h)

add_executable (HyperBeam main.cxx ${sources} ${headers})
target_include_directories (HyperBeam PRIVATE include)
target_link_libraries (HyperBeam PRIVATE ${Geant4_LIBRARIES} ${ROOT_LIBRARIES})

configure_file (geometry.gdml geometry.gdml COPYONLY)


