set(PROJECT_NAME ShowDib4)
message("==== ${PROJECT_NAME} ====")
project(${PROJECT_NAME})

#SOURCE=..\ShowDib3\PackeDib.c
set(tmp_src_files ../ShowDib3/PackeDib.c)

sge_add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties (${PROJECT_NAME} PROPERTIES FOLDER Chap16/ShowDib4)
set_target_properties(${PROJECT_NAME} PROPERTIES VS_PLATFORM_TOOLSET v142)