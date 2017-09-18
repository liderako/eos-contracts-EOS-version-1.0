file(GLOB SOURCE_FILES "*.cpp")
add_wast_target(mydice "${SOURCE_FILES}" "${CMAKE_SOURCE_DIR}/contracts" ${CMAKE_CURRENT_SOURCE_DIR})
