set(SOURCES
    src/glad.c
)

set(HEADERS
    include/glad/glad.h
    include/KHR/khrplatform.h
)

add_library(glad STATIC ${SOURCES} ${HEADERS})

target_include_directories(glad
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
)

set_target_properties(glad PROPERTIES
    FOLDER
        externals/glad
)