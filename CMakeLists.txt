cmake_minimum_required(VERSION 3.5)
project(DNA_profiler VERSION 0.1 LANGUAGES CXX )


### Executável
# Diretório contendo os .hpp
include_directories( include )

# Cria um executável com nome "dna_profiler", adiciona neste executável os arquivos src/Dados.cpp src/InterfaceUsuario.cpp src/Resultados.cpp
add_executable( dna_profiler
                src/main.cpp
                src/Dados.cpp
                src/InterfaceUsuario.cpp
                src/Perfil.cpp )
# The end
