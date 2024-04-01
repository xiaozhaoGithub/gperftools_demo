set(project_name "cpu_profiler")

add_executable(${project_name}
    main.cpp)

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
    profiler
)

# 使用 SET_TARGET_PROPERTIES 设置链接器选项
set_target_properties(${project_name}
PROPERTIES
    LINK_FLAGS "-Wl,--no-as-needed -lprofiler -Wl,--as-needed"
)

