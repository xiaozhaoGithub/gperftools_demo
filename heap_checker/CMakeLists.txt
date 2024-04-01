set(project_name "heap_checker")

add_executable(${project_name} main.cpp)

target_include_directories(${project_name}
PRIVATE
    ${CMAKE_SOURCE_DIR}/third_lib/gperftools/include
)

target_link_directories(${project_name}
PRIVATE
    ${CMAKE_SOURCE_DIR}/third_lib/gperftools/lib/lib
)

target_link_libraries(${project_name}
PRIVATE
    tcmalloc
)


