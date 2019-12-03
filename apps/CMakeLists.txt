set(ubqp_dir ${CMAKE_CURRENT_SOURCE_DIR}/ubqp)

file(GLOB_RECURSE ubqp_sources ${ubqp_dir}/*.c ${ubqp_dir}/*.cpp)
file(GLOB_RECURSE ubqp_headers ${ubqp_dir}/*.h ${ubqp_dir}/*.hpp)
file(GLOB_RECURSE ubqp_inlines ${ubqp_dir}/*.inl)

set(tsp_dir ${CMAKE_CURRENT_SOURCE_DIR}/tsp)

file(GLOB_RECURSE tsp_sources ${tsp_dir}/*.c ${tsp_dir}/*.cpp)
file(GLOB_RECURSE tsp_headers ${tsp_dir}/*.h ${tsp_dir}/*.hpp)
file(GLOB_RECURSE tsp_inlines ${tsp_dir}/*.inl)

add_executable(ubqp ${ubqp_sources} ${ubqp_headers} ${ubqp_inlines})
#add_executable(tsp ${tsp_sources} ${tsp_headers} ${tsp_inlines})