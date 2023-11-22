set(PROJECT_NAME Apollo11)
message("==== ${PROJECT_NAME} ====")
project(${PROJECT_NAME})

#SOURCE=..\ShowDib1\DibFile.c
set(tmp_src_files ../ShowDib1/DibFile.c)

sge_add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties (${PROJECT_NAME} PROPERTIES FOLDER Chap15/Apollo11)
set_target_properties(${PROJECT_NAME} PROPERTIES VS_PLATFORM_TOOLSET v142)