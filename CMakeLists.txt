cmake_minimum_required(VERSION 3.0.2)
project(cpp_ros_package_starter)

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
)
catkin_package(
  CATKIN_DEPENDS 
  std_msgs
  roscpp 
)

include_directories(
  include 
  ${catkin_INCLUDE_DIRS}
  ${PROJECT_INCLUDE_DIR}
)

add_executable(counter_node src/counter_node.cpp src/counter.cpp)
target_link_libraries(counter_node ${catkin_LIBRARIES})
add_dependencies(counter_node ${catkin_EXPORTED_TARGETS})
