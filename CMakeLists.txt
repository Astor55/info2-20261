cmake_minimum_required(VERSION 3.16)

<<<<<<< HEAD
project(desafio1 LANGUAGES CXX)
=======
project(desafio1-20261 LANGUAGES CXX)
>>>>>>> origin/master

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

<<<<<<< HEAD
add_executable(desafio1
  main.cpp
  funciones_tablero.h
  funciones_tablero.cpp
)


set_target_properties(desafio1 PROPERTIES WIN32_EXECUTABLE OFF)


target_link_libraries(desafio1 PRIVATE Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS desafio1
=======
add_executable(desafio1-20261
  fichas.cpp
  fichas.h
  main.cpp
)
target_link_libraries(desafio1-20261 PRIVATE Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS desafio1-20261
>>>>>>> origin/master
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
