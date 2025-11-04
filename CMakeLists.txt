cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

project(Sensor_Control)

add_executable(sensor_control 
  src/main.cpp
  src/sw420_vibration_sensor.cpp
)
target_link_libraries(sensor_control PRIVATE wiringPi)
include_directories(include src tests)

#enable_testing()

