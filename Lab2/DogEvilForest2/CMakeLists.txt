cmake_minimum_required(VERSION 3.10)

# Set the project name
project(DogEvilForest)

# Add the executable
add_executable(DogEvilForest mainGame.cpp ../DogEvilForest2/Board.cpp ../DogEvilForest2/Dog.cpp)