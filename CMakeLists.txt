cmake_minimum_required(VERSION 3.16)

project(desafio1 LANGUAGES CXX)

# Qt configuración automática
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Buscar Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

# 🔥 IMPORTANTE: UN SOLO EJECUTABLE
add_executable(desafio1
    main.cpp
    funciones_tablero.cpp
    funciones_tablero.h
    fichas.cpp
    fichas.h
)

# Link con Qt
target_link_libraries(desafio1 PRIVATE Qt${QT_VERSION_MAJOR}::Core)

# Instalación (opcional pero correcto)
include(GNUInstallDirs)
install(TARGETS desafio1
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
