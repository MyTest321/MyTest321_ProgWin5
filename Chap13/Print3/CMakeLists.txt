set(PROJECT_NAME Print3)
message("==== ${PROJECT_NAME} ====")
project(${PROJECT_NAME})

#SOURCE=..\Print1\GetPrnDC.c
#SOURCE=..\Print1\Print.c

set(tmp_src_files
    ../Print1/GetPrnDC.c
    ../Print1/Print.c
)

sge_add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties (${PROJECT_NAME} PROPERTIES FOLDER Chap13/Print3)
set_target_properties(${PROJECT_NAME} PROPERTIES VS_PLATFORM_TOOLSET v142)