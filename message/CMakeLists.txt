file(GLOB SOURCE_FILES "*.cpp")
add_wast_target(message "${CMAKE_SOURCE_DIR}/contracts" ${CMAKE_CURRENT_BINARY_DIR})
