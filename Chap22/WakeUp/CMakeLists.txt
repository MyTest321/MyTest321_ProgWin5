set(PROJECT_NAME WakeUp)
message("==== ${PROJECT_NAME} ====")
project(${PROJECT_NAME})

sge_add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC Winmm.lib Comctl32.lib)
set_target_properties (${PROJECT_NAME} PROPERTIES FOLDER Chap22/WakeUp)