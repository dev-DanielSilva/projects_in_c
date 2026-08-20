cmake_minimum_required(VERSION 4.3)
project(01_ponto_tad C)

set(C_STANDARD 11)

add_executable(01_ponto_tad main.c Ponto.c Ponto.h)

# Adicione esta linha para vincular a biblioteca matemática:
target_link_libraries(01_ponto_tad m)