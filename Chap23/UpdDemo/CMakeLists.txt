set(PROJECT_NAME UpdDemo)
message("==== ${PROJECT_NAME} ====")
project(${PROJECT_NAME})

sge_add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC Wininet.lib)

set_target_properties (${PROJECT_NAME} PROPERTIES FOLDER Chap23/UpdDemo)
set_target_properties(${PROJECT_NAME} PROPERTIES VS_PLATFORM_TOOLSET v142)