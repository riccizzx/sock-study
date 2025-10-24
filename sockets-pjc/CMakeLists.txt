# CMakeList.txt : CMake project for sockets-pjc, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (sockets-pjc "sockets-pjc.cpp" "sockets-pjc.h" "section0/server-echo.cpp" "section1/ifsc.cpp" "section0/client-echo.cpp" "section2/sctp.cpp" "section3/asyncronos.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET sockets-pjc PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
