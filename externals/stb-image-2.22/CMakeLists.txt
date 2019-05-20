add_library(stb_image STATIC
    stb/stb_image.h
    stb/stb_image.cpp
)

target_include_directories(stb_image
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

target_compile_definitions(stb_image
    PRIVATE
        STB_IMAGE_IMPLEMENTATION
)