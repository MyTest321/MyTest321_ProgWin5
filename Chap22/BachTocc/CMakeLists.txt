set(PROJECT_NAME BachTocc)
message("==== ${PROJECT_NAME} ====")
project(${PROJECT_NAME})

sge_add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC Winmm.lib)

set_target_properties (${PROJECT_NAME} PROPERTIES FOLDER Chap22/BachTocc)