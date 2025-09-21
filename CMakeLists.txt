cmake_minimum_required(VERSION 3.16)
project(my_app LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Drogon REQUIRED)
find_package(Jsoncpp REQUIRED)

# Файлы находятся в папке myapp/
add_executable(${PROJECT_NAME}
    myapp/main.cc
    myapp/Controller/ClickController.cc
    myapp/Service/ClickService.cc
    myapp/Repository/ClickRepository.cc
)

# Include пути с учетом папки myapp/
target_include_directories(${PROJECT_NAME} PRIVATE
    .
    myapp
    myapp/Controller
    myapp/Service
    myapp/Repository
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Drogon::Drogon
    Jsoncpp_lib
)