INCLUDE (CheckIncludeFiles)
cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
CHECK_INCLUDE_FILES (winsock2.h HAVE_WINSOCK2_H)
add_executable( DisplayImage DisplayImage.cpp UDPSend.cpp)
target_link_libraries( DisplayImage ${OpenCV_LIBS} )

