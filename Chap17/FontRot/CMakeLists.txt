set(PROJECT_NAME FontRot)
message("==== ${PROJECT_NAME} ====")
project(${PROJECT_NAME})

#SOURCE=..\EzTest\EzFont.c
#SOURCE=..\EZTest\FontDemo.c
#SOURCE=..\EZTest\FontDemo.rc
set(tmp_src_files 
    ../EZTest/EzFont.c
    ../EZTest/FontDemo.c
    ../EZTest/FontDemo.rc
)

sge_add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties (${PROJECT_NAME} PROPERTIES FOLDER Chap17/FontRot)
set_target_properties(${PROJECT_NAME} PROPERTIES VS_PLATFORM_TOOLSET v142)