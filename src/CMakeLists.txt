set(SRCS 
    shader/shader.cpp

    main.cpp
)

set(HDRS
	shader/shader.h
	shader/shader_simple.h
	shader/shader_uniform_color.h

    geometry/triangle.h
	texture/texture.h

)

add_executable(main ${SRCS} ${HDRS})

target_link_libraries(main
	PRIVATE
		glad
		glfw
		stb_image
)

target_compile_definitions(main
    PRIVATE
        STB_IMAGE_IMPLEMENTATION
)

set_target_properties(main PROPERTIES
	VS_DEBUGGER_WORKING_DIRECTORY
		"${CMAKE_BINARY_DIR}/output/$(Configuration)"
)
viz_source_code_ide(
	SOURCES			${SRCS}
	HEADERS			${HDRS}
	HEADERS_PATHS	${CMAKE_CURRENT_LIST_DIR}
	SOURCES_PATHS	${CMAKE_CURRENT_LIST_DIR}
)