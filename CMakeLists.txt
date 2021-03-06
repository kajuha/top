################################################################################
# CMake
################################################################################
cmake_minimum_required(VERSION 2.8.3)
project(top)

################################################################################
# Packages
################################################################################
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  mecanum
)

################################################################################
# Declare ROS messages, services and actions
################################################################################

################################################################################
# Declare ROS dynamic reconfigure parameters
################################################################################

################################################################################
# Catkin specific configuration
################################################################################
catkin_package(  
  LIBRARIES top
  CATKIN_DEPENDS roscpp std_msgs
  # DEPENDS system_lib
)

################################################################################
# Build
################################################################################
include_directories(  
  ${catkin_INCLUDE_DIRS}
)

add_executable(top src/main.cpp src/AGVCallBack.cpp)
add_dependencies(top ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(top ${catkin_LIBRARIES})

# I knew the REP0003(http://www.ros.org/reps/rep-0003.html#c),
# but the code of "top" must compile with C++11.
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")


################################################################################
# Install
################################################################################
install(TARGETS top
        ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
        DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)

install(DIRECTORY launch
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(DIRECTORY rviz_cfg
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

################################################################################
# Test
#############################################################################