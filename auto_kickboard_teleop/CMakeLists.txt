cmake_minimum_required(VERSION 3.0.2)
project(auto_kickboard_teleop)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
  ssing_msgs
)

#add_message_file(FILES Ssing.msg)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
  #INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp message_runtime
)


include_directories(${catkin_INCLUDE_DIRS})

add_executable(ssing_keyboard src/ssing_keyboard.cpp)
target_link_libraries(ssing_keyboard ${catkin_LIBRARIES})
