CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

SET(CMAKE_CXX_STANDARD 11)

INCLUDE_DIRECTORIES(src/ include/)
ADD_LIBRARY(Catch INTERFACE)
target_include_directories(Catch INTERFACE include/)

ADD_LIBRARY(ContaBancaria INTERFACE)
target_include_directories(ContaBancaria INTERFACE include/)

ADD_LIBRARY(Operacoes INTERFACE)
target_include_directories(Operacoes INTERFACE include/)


ADD_EXECUTABLE(programa src/main.cpp src/ContaBancaria.cpp src/Operacoes.cpp)

ADD_EXECUTABLE(tests tests/all.cpp src/ContaBancaria.cpp src/Operacoes.cpp)
TARGET_LINK_LIBRARIES(tests Catch)
ENABLE_TESTING()
ADD_TEST(NAME ContaBancariaTest COMMAND tests)
