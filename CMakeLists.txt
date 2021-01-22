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
add_library(keyboard src/sdl_teclado.cpp)
# add_library(clientController src/clientController.cpp)
# add_library(sender src/sender.cpp)
# add_library(receiver src/reveicer.cpp)


target_link_libraries(gameController gameView)
target_link_libraries(gameController ballController)
target_link_libraries(gameController keyboard)

target_link_libraries(ballController ballModel)
target_link_libraries(ballController ballView)
target_link_libraries(ballController keyboard)
#target_link_libraries(sender clientController)
#target_link_libraries(receiver clientController)


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
SET(CMAKE_CXX_FLAGS "${SMAKE_CXX_FLAGS} -pthread")

# Bibliotecas linkadas externamente
#target_link_libraries(Desespero872 SDL2)
#target_link_libraries(Desespero872 SDL2_image)

#Tentativa do IMG_LoadTexture funcionar no make:
INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})



