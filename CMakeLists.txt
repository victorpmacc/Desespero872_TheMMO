# Versao minima do cmake
cmake_minimum_required(VERSION 3.0)

# Nome do meu projeto
project(Desespero872)

#
add_executable(Desespero872 src/main.cpp)

# Especificar onde estao os header files
include_directories(include/)

# Bibliotecas locais (estaticas)
add_library(ballModel src/ballModel.cpp)
add_library(ballView src/ballView.cpp)
add_library(ballController src/ballController.cpp)
add_library(gameController src/gameController.cpp)
add_library(gameView src/gameView.cpp)
add_library(keyboard src/sdl_keyboard.cpp)
# add_library(clientController src/clientController.cpp)
# add_library(sender src/sender.cpp)
# add_library(receiver src/reveicer.cpp)

target_link_libraries(Desespero872 ballModel)
target_link_libraries(Desespero872 ballController)
target_link_libraries(Desespero872 ballView)
target_link_libraries(Desespero872 gameView)
target_link_libraries(Desespero872 gameController)
target_link_libraries(Desespero872 keyboard)
# target_link_libraries(Desespero872 clientController)
# target_link_libraries(Desespero872 sender)
# target_link_libraries(Desespero872 receiver)


# Garantir que usaremos C++11 (ou superior, se preciso)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/")

# Bibliotecas linkadas externamente
find_package(SDL2 REQUIRED)
include_directiories(${SDL2_INCLUDE_DIRS})

find_package(SDL2_image REQUIRED)
include_directoried(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(Desespero872 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

include_directories(/usr/local/include)
link_directories(/usr/local/lib)
