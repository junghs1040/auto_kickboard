cmake_minimum_required(VERSION 3.0.2)
project(auto_kickboard_libs)


find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES auto_kickboard_libs
  CATKIN_DEPENDS roscpp
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(auto_kickboard 
    src/auto_kickboard.cpp)
#add_dependencies(auto_kickboard ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(auto_kickboard ${catkin_LIBRARIES} )
add_dependencies(auto_kickboard ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
