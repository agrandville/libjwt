add_definitions(-D_GNU_SOURCE)

add_executable(jwtauth
	main-auth.c
	$<$<CXX_COMPILER_ID:MSVC>:${CMAKE_SOURCE_DIR}/compat/getopt.c>
	$<$<CXX_COMPILER_ID:MSVC>:${CMAKE_SOURCE_DIR}/compat/libgen.c>
)

set_property(TARGET jwtauth PROPERTY C_STANDARD 11)

target_link_libraries(jwtauth  PRIVATE
	${PROJECT_NAME}
)

target_include_directories(jwtauth PRIVATE  
	${LIBJWT_INCLUDE_DIRS}
	$<$<CXX_COMPILER_ID:MSVC>:${CMAKE_SOURCE_DIR}/compat>
)

add_executable(jwtgen
	main-gen.c
	$<$<CXX_COMPILER_ID:MSVC>:${CMAKE_SOURCE_DIR}/compat/getopt.c>
	$<$<CXX_COMPILER_ID:MSVC>:${CMAKE_SOURCE_DIR}/compat/libgen.c>
)

set_property(TARGET jwtgen PROPERTY C_STANDARD 11)

target_link_libraries(jwtgen PRIVATE 
	${PROJECT_NAME}
)

target_include_directories(jwtgen PRIVATE  
	${LIBJWT_INCLUDE_DIRS}
	$<$<CXX_COMPILER_ID:MSVC>:${CMAKE_SOURCE_DIR}/compat>
)

