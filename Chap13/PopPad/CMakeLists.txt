set(PROJECT_NAME PopPad)
message("==== ${PROJECT_NAME} ====")
project(${PROJECT_NAME})

sge_add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties (${PROJECT_NAME} PROPERTIES FOLDER Chap13/PopPad)
set_target_properties(${PROJECT_NAME} PROPERTIES VS_PLATFORM_TOOLSET v142)