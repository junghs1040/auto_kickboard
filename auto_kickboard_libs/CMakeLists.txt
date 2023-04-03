cmake_minimum_required(VERSION 3.0.2)
project(auto_kickboard_libs)


find_package(catkin REQUIRED COMPONENTS
  message_generation
  geometry_msgs
  roscpp
  std_msgs
)

add_message_files(DIRECTORY /home/mincho/ros_ws/src/auto_kickboard/ssing_msgs/msg FILES Ssing.msg)

generate_messages(DEPENDENCIES std_msgs ssing_msgs)

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
    src/auto_kickboard.cpp
    src/controller.cpp
)


#add_dependencies(auto_kickboard ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(auto_kickboard ${catkin_LIBRARIES} )
add_dependencies(auto_kickboard ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
