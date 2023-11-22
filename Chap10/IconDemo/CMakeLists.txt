set(PROJECT_NAME IconDemo)
message("==== ${PROJECT_NAME} ====")
project(${PROJECT_NAME})

sge_add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties (${PROJECT_NAME} PROPERTIES FOLDER Chap10/IconDemo)

#https://github.com/electronicarts/CnC_Remastered_Collection/issues/36
#https://cmake.org/cmake/help/latest/variable/CMAKE_VS_PLATFORM_TOOLSET.html
set_target_properties(${PROJECT_NAME} PROPERTIES VS_PLATFORM_TOOLSET v142)