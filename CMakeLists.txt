cmake_minimum_required (VERSION 2.6)
project (SFML-Sidescroller)
option(64BitBuild "64BitBuild" OFF)
include_directories("${CMAKE_SOURCE_DIR}/include" "{CMAKE_SOURCE_DIR}/SFML/include")
file(GLOB_RECURSE Sources src/*.cpp)

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	if(64BitBuild)
		#64 Bit
		link_directories("${CMAKE_SOURCE_DIR}/SFML/lib_linux64")
		set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/Linux64Release )
	else()
		#32 Bit
		link_directories("${CMAKE_SOURCE_DIR}/SFML/lib_linux32")
		set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/Linux32Release )
	endif()
	
	link_libraries("sfml-system" "sfml-graphics" "sfml-window" "sfml-audio" "sfml-network" "boost_signals" "boost_thread" "boost_system")
    SET(OperatingSystem "Linux")
else()
	if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
		SET(OperatingSystem "Windows")
		include_directories("${CMAKE_SOURCE_DIR}/SFML/include")
		link_libraries("libsfml-system.a" "libsfml-graphics.a" "libsfml-window.a" "libsfml-audio.a" "libsfml-network.a")
		
		set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/w32Release )
		add_definitions("-DBOOST_THREAD_USE_LIB -Os -O3 -O2 -O1 -O")
		set(CMAKE_CXX_FLAGS "-O2 -std=c++0x")
		set(CMAKE_CXX_LINKER_FLAGS "-static -s")
	endif()
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-O2 -std=c++0x")        ## Optimize
    set(CMAKE_EXE_LINKER_FLAGS "-s")  ## Strip binary
endif()

add_executable("SFMLSidescroller" "${Sources}")
