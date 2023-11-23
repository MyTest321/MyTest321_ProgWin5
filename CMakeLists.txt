cmake_minimum_required(VERSION 3.18)

#set(CMAKE_BUILD_TYPE Debug)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(ProgWin5)

set(cmake_root_dir ${CMAKE_CURRENT_SOURCE_DIR})
set(cmake_root_bin_dir ${CMAKE_CURRENT_BINARY_DIR})

set(tmp_src_files "")

function(sge_source_group src_path src_files)
	foreach(FILE ${src_files}) 
		get_filename_component(PARENT_DIR "${FILE}" PATH)
		file(RELATIVE_PATH PARENT_DIR ${src_path} ${PARENT_DIR})
		string(REPLACE "/" "\\" GROUP "${PARENT_DIR}")
		set(GROUP "${GROUP}")
		source_group("${GROUP}" FILES "${FILE}")	
	endforeach()
endfunction()

function(sge_add_executable target_name src_path)
	file(GLOB_RECURSE src_files
		"${src_path}/*.*"
	)

	sge_source_group(${src_path} "${src_files}")
	add_compile_definitions(MY_CMAKE_BIN_DIR="${cmake_root_bin_dir}")
	add_executable(${target_name}
		${src_files}
		${tmp_src_files}
		${cmake_root_dir}/main.c
	)

	target_link_libraries(${target_name} PUBLIC
		kernel32.lib
		user32.lib
		gdi32.lib
		winspool.lib
		comdlg32.lib
		advapi32.lib
		shell32.lib
		ole32.lib
		oleaut32.lib
		uuid.lib
		odbc32.lib
		odbccp32.lib
	)

endfunction()

#----------
add_subdirectory(Chap01/HelloMsg)

add_subdirectory(Chap02/ScrnSize)

add_subdirectory(Chap03/HelloWin)

add_subdirectory(Chap04/SysMets1)
add_subdirectory(Chap04/SysMets2)
add_subdirectory(Chap04/SysMets3)

add_subdirectory(Chap05/AltWind)
add_subdirectory(Chap05/Bezier)
add_subdirectory(Chap05/Clover)
add_subdirectory(Chap05/DevCaps1)
add_subdirectory(Chap05/LineDemo)
add_subdirectory(Chap05/RandRect)
add_subdirectory(Chap05/SineWave)
add_subdirectory(Chap05/WhatSize)

add_subdirectory(Chap06/KeyView1)
add_subdirectory(Chap06/KeyView2)
add_subdirectory(Chap06/StokFont)
add_subdirectory(Chap06/SysMets4)
add_subdirectory(Chap06/Typer)

add_subdirectory(Chap07/BlokOut1)
add_subdirectory(Chap07/BlokOut2)
add_subdirectory(Chap07/Checker1)
add_subdirectory(Chap07/Checker2)
add_subdirectory(Chap07/Checker3)
add_subdirectory(Chap07/Checker4)
add_subdirectory(Chap07/Connect)
add_subdirectory(Chap07/SysMets)

add_subdirectory(Chap08/Beeper1)
add_subdirectory(Chap08/Beeper2)
add_subdirectory(Chap08/Clock)
add_subdirectory(Chap08/DigClock)
add_subdirectory(Chap08/WhatClr)

add_subdirectory(Chap09/BtnLook)
add_subdirectory(Chap09/Colors1)
add_subdirectory(Chap09/Environ)
add_subdirectory(Chap09/head)
add_subdirectory(Chap09/OwnDraw)
add_subdirectory(Chap09/PopPad1)

add_subdirectory(Chap10/IconDemo)
add_subdirectory(Chap10/MenuDemo)
add_subdirectory(Chap10/NoPopups)
add_subdirectory(Chap10/PoePoem)
add_subdirectory(Chap10/PoorMenu)
add_subdirectory(Chap10/PopMenu)
add_subdirectory(Chap10/PopPad2)

add_subdirectory(Chap11/About1)
add_subdirectory(Chap11/About2)
add_subdirectory(Chap11/About3)
add_subdirectory(Chap11/Colors2)
add_subdirectory(Chap11/Colors3)
add_subdirectory(Chap11/HexCalc)
add_subdirectory(Chap11/PopPad3)

add_subdirectory(Chap12/ClipText)
add_subdirectory(Chap12/ClipView)

add_subdirectory(Chap13/DevCaps2)
add_subdirectory(Chap13/FormFeed)
add_subdirectory(Chap13/PopPad)
add_subdirectory(Chap13/Print1)
add_subdirectory(Chap13/Print2)
add_subdirectory(Chap13/Print3)

add_subdirectory(Chap14/BitBlt)
add_subdirectory(Chap14/BitMask)
add_subdirectory(Chap14/Blowup)
add_subdirectory(Chap14/Bounce)
add_subdirectory(Chap14/Bricks1)
add_subdirectory(Chap14/Bricks2)
add_subdirectory(Chap14/Bricks3)
add_subdirectory(Chap14/GrafMenu)
add_subdirectory(Chap14/HelloBit)
add_subdirectory(Chap14/Scramble)
add_subdirectory(Chap14/Sketch)
add_subdirectory(Chap14/Stretch)

add_subdirectory(Chap15/Apollo11)
add_subdirectory(Chap15/DibConv)
add_subdirectory(Chap15/DibHeads)
add_subdirectory(Chap15/DibSect)
add_subdirectory(Chap15/SeqDisp)
add_subdirectory(Chap15/ShowDib1)
add_subdirectory(Chap15/ShowDib2)

add_subdirectory(Chap16/AllColor)
add_subdirectory(Chap16/Bounce)
add_subdirectory(Chap16/Dibble)
add_subdirectory(Chap16/Fader)
add_subdirectory(Chap16/Grays1)
add_subdirectory(Chap16/Grays2)
add_subdirectory(Chap16/Grays3)
add_subdirectory(Chap16/Pipes)
add_subdirectory(Chap16/ShowDib3)
add_subdirectory(Chap16/ShowDib4)
add_subdirectory(Chap16/ShowDib5)
add_subdirectory(Chap16/ShowDib6)
add_subdirectory(Chap16/ShowDib7)
add_subdirectory(Chap16/ShowDib8)
add_subdirectory(Chap16/SysPal1)
add_subdirectory(Chap16/SysPal2)
add_subdirectory(Chap16/SysPal3)
add_subdirectory(Chap16/Tunnel)

add_subdirectory(Chap17/ChosFont)
add_subdirectory(Chap17/EndJoin)
add_subdirectory(Chap17/EZTest)
add_subdirectory(Chap17/FontClip)
add_subdirectory(Chap17/FontFill)
add_subdirectory(Chap17/FontOut1)
add_subdirectory(Chap17/FontOut2)
add_subdirectory(Chap17/FontRot)
add_subdirectory(Chap17/Justify1)
add_subdirectory(Chap17/Justify2)
add_subdirectory(Chap17/PickFont)
add_subdirectory(Chap17/UniChars)

add_subdirectory(Chap18/Emf1)
add_subdirectory(Chap18/Emf2)
add_subdirectory(Chap18/Emf3)
add_subdirectory(Chap18/Emf4)
add_subdirectory(Chap18/Emf5)
add_subdirectory(Chap18/Emf6)
add_subdirectory(Chap18/Emf7)
add_subdirectory(Chap18/Emf8)
add_subdirectory(Chap18/Emf9)
add_subdirectory(Chap18/Emf10)
add_subdirectory(Chap18/Emf11)
add_subdirectory(Chap18/Emf12)
add_subdirectory(Chap18/Emf13)
add_subdirectory(Chap18/EmfView)
add_subdirectory(Chap18/Metafile)

add_subdirectory(Chap19/MDIDemo)

add_subdirectory(Chap20/BigJob1)
add_subdirectory(Chap20/BigJob2)
add_subdirectory(Chap20/Multi1)
add_subdirectory(Chap20/Multi2)
add_subdirectory(Chap20/RndRctMT)

add_subdirectory(Chap21/EdrTest)
add_subdirectory(Chap21/ShowBit)
add_subdirectory(Chap21/StrProg)

add_subdirectory(Chap22/AddSynth)
add_subdirectory(Chap22/BachTocc)
add_subdirectory(Chap22/Drum)
add_subdirectory(Chap22/KBMidi)
add_subdirectory(Chap22/Record1)
add_subdirectory(Chap22/Record2)
add_subdirectory(Chap22/Record3)
add_subdirectory(Chap22/SineWave)
add_subdirectory(Chap22/TestMci)
add_subdirectory(Chap22/WakeUp)

add_subdirectory(Chap23/NetTime)
add_subdirectory(Chap23/UpdDemo)

#set_property (DIRECTORY PROPERTY VS_STARTUP_PROJECT HelloWin)

