file(GLOB HEADERS "include/mtpio/http_plugin/*.hpp")
add_library( http_plugin
             http_plugin.cpp
             ${HEADERS} )

target_link_libraries( http_plugin mtpio_chain appbase fc )
target_include_directories( http_plugin PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
