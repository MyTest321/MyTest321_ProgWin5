set(PROJECT_NAME AllColor)
message("==== ${PROJECT_NAME} ====")
project(${PROJECT_NAME})

#SOURCE=..\Bounce\PalAnim.c
set(tmp_src_files ../Bounce/PalAnim.c)

sge_add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties (${PROJECT_NAME} PROPERTIES FOLDER Chap16/AllColor)