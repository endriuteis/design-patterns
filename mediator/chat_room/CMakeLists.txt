cmake_minimum_required(VERSION 3.6)
project(ChatRoom)

set(SOURCE_FILES main.cpp person.cpp person.h chat_room.cpp chat_room.h)
add_executable(ChatRoom ${SOURCE_FILES})