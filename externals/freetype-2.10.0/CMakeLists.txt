add_library(freetype SHARED IMPORTED GLOBAL)

set_target_properties(freetype PROPERTIES
    INTERFACE_COMPILE_DEFINITIONS "EXTERN_HAVE_FREETYPE"
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/include"
    IMPORTED_IMPLIB "${CMAKE_CURRENT_LIST_DIR}/win64/freetype.lib"
    IMPORTED_LOCATION  "${CMAKE_CURRENT_LIST_DIR}/win64/freetype.dll"
)