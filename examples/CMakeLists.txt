#find_package(LibJWT)
enable_language(C)

add_definitions(-D_GNU_SOURCE)

find_package(jansson CONFIG REQUIRED)

if (MSVC)
	SET(WIN_SRC ../win32/basename.c ../win32/getopt.c)

	cmake_policy(SET CMP0091 NEW)
	
	if(LIBRARY_TYPE MATCHES "STATIC")
		set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
	else()
		set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDLL$<$<CONFIG:Debug>:Debug>")
	endif()

endif ()

add_executable(jwtauth
	main-auth.c
	${WIN_SRC}
)

target_include_directories(jwtauth
		PUBLIC "../win32"
)	


#target_compile_options(jwtauth PRIVATE -Werror -Wall -Wextra)
#target_compile_options(jwtauth PRIVATE -g -fPIC -O2 -funwind-tables)

set_property(TARGET jwtauth PROPERTY C_STANDARD 11)

target_link_libraries(jwtauth 
						PUBLIC jwt
						PRIVATE jansson::jansson)

#target_link_libraries(jwtauth ${LIBJWT_LIBRARIES})

#target_include_directories(jwtauth
#	PUBLIC ${LIBJWT_INCLUDE_DIRS}}
#)

add_executable(jwtgen
	main-gen.c
	${WIN_SRC}
)

#target_compile_options(jwtgen PRIVATE -Werror -Wall -Wextra)
#target_compile_options(jwtgen PRIVATE -g -fPIC -O2 -funwind-tables)

set_property(TARGET jwtgen PROPERTY C_STANDARD 11)

target_link_libraries(jwtgen
						PUBLIC  jwt
						PRIVATE jansson::jansson)

#target_link_libraries(jwtgen ${LIBJWT_LIBRARIES})

if (MSVC)
	target_include_directories(jwtgen
	PUBLIC "../win32"
	)
endif ()

#target_include_directories(jwtgen
#	PUBLIC ${LIBJWT_INCLUDE_DIRS}
#)

