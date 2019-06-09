cmake_minimum_required(VERSION 3.13)
project(cpp-tasks)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp-tasks src/main.cpp src/BoxStruct.cpp headers/BoxStruct.h src/BoxStructProcessor.cpp headers/BoxStructProcessor.h src/BoxClass.cpp headers/BoxClass.h src/Container.cpp headers/Container.h src/BoxClassProcessor.cpp headers/BoxClassProcessor.h src/DynamicArrayInt.cpp headers/DynamicArrayInt.h src/RingBuffer.cpp headers/RingBuffer.h src/RingBufferIterator.cpp headers/RingBufferIterator.h headers/List.h headers/Iterator.h headers/BufferList.h headers/ListElement.h src/HashTable.cpp headers/HashTable.h src/BinaryTree.cpp headers/BinaryTree.h src/BinaryWordTree.cpp headers/BinaryWordTree.h)