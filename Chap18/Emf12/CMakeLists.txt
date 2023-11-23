set(PROJECT_NAME Emf12)
message("==== ${PROJECT_NAME} ====")
project(${PROJECT_NAME})

#SOURCE=..\Emf8\Emf.c
#SOURCE=..\Emf8\Emf.rc

set(tmp_src_files
    ../Emf8/Emf.c
    ../Emf8/Emf.rc
)

sge_add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties (${PROJECT_NAME} PROPERTIES FOLDER Chap18/Emf12)
set_target_properties(${PROJECT_NAME} PROPERTIES VS_PLATFORM_TOOLSET v142)