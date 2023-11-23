set(PROJECT_NAME Record2)
message("==== ${PROJECT_NAME} ====")
project(${PROJECT_NAME})

#SOURCE=..\Record1\Record.rc
set(tmp_src_files ../Record1/Record.rc)

sge_add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC Winmm.lib)

set_target_properties (${PROJECT_NAME} PROPERTIES FOLDER Chap22/Record2)
set_target_properties(${PROJECT_NAME} PROPERTIES VS_PLATFORM_TOOLSET v142)