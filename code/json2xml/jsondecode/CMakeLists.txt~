CMAKE_MINIMUM_REQUIRED (VERSION 3.0)
CMAKE_POLICY (VERSION 3.0)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}-m64)
set(LOACL_PATH /home/chy/)
MESSAGE(STATUS "LOACL_PATH=" ${LOACL_PATH})
INCLUDE_DIRECTORIES(
${LOACL_PATH}json2xml/jsondecod
)
add_definitions("-Wall -std=c++11")
add_executable(demo
   json2xml.cpp)
MESSAGE(STATUS "PROJECT_SOURCE_DIR=" ${PROJECT_SOURCE_DIR})
target_link_libraries(demo
		jsoncpp	
		${PROJECT_SOURCE_DIR}/libpugixml.a		
	)
