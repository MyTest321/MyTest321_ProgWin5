set(PROJECT_NAME FormFeed)
message("==== ${PROJECT_NAME} ====")
project(${PROJECT_NAME})

#SOURCE=..\Print1\GetPrnDC.c

set(tmp_src_files
    ../Print1/GetPrnDC.c
)

sge_add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties (${PROJECT_NAME} PROPERTIES FOLDER Chap13/FormFeed)