cmake_minimum_required(VERSION 3.0.2)
project(image_reader)

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    cv_bridge
)
find_package(exiv2 REQUIRED)
find_package(msgs_and_srvs REQUIRED)
catkin_package(
  CATKIN_DEPENDS 
  std_msgs
  roscpp 
)

include_directories(
  include 
  ${catkin_INCLUDE_DIRS}
  ${PROJECT_INCLUDE_DIR}
  ${msgs_and_srvs_INCLUDE_DIRS}
)

add_executable(image_reader_node src/image_reader_node.cpp src/reader.cpp)
target_link_libraries(image_reader_node ${catkin_LIBRARIES} exiv2)
add_dependencies(image_reader_node ${catkin_EXPORTED_TARGETS})
