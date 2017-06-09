cmake_minimum_required(VERSION 2.8)

project("ros_music_adapters")

# add modules for finding JSONCPP, ZMQ and MUSIC
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

find_package(MUSIC REQUIRED)
find_package(JSONCPP REQUIRED)
find_package(MPI REQUIRED)
find_package(ZMQ REQUIRED)

include_directories(
    include
    ${MUSIC_INCLUDE_DIRS}
    ${JSONCPP_INCLUDE_DIRS}
    ${MPI_INCLUDE_PATH}
    ${ZMQ_INCLUDE_DIRS}
)


set(CMAKE_CXX_COMPILE_FLAGS ${CMAKE_CXX_COMPILE_FLAGS} ${MPI_COMPILE_FLAGS})
set(CMAKE_CXX_LINK_FLAGS ${CMAKE_CXX_LINK_FLAGS} ${MPI_LINK_FLAGS})
set(CMAKE_CXX_FLAGS "-O3 -g -Wall")

find_library(GSL gsl REQUIRED)
find_library(BLAS gslcblas REQUIRED)
find_library(PTHREAD pthread REQUIRED)

add_library(rtclock STATIC lib/rtclock.cpp)
include_directories(lib/)

add_library(musicadapter STATIC base/Port.cpp
                                base/InPort.cpp
                                base/OutPort.cpp
                                base/ContInPort.cpp 
                                base/ContOutPort.cpp
                                base/EventInPort.cpp 
                                base/EventOutPort.cpp
                                base/ZMQInPort.cpp
                                base/ZMQOutPort.cpp
                                base/Adapter.cpp)
include_directories(base/)


# Adapters
add_executable(zmq_cont_adapter adapters/ZMQContAdapter.cpp)
add_executable(cont_zmq_adapter adapters/ContZMQAdapter.cpp)
add_executable(discretize_adapter adapters/DiscretizeAdapter.cpp)
add_executable(argmax_adapter adapters/ArgmaxAdapter.cpp)
add_executable(cont_cont_adapter adapters/ContContAdapter.cpp)
add_executable(threshold_adapter adapters/ThresholdAdapter.cpp)

target_link_libraries(zmq_cont_adapter musicadapter ${ZMQ_LIBRARIES} ${MUSIC_LIBRARIES} ${PTHREAD} ${MPI_LIBRARIES} ${JSONCPP_LIBRARY} rtclock)
target_link_libraries(cont_zmq_adapter musicadapter ${ZMQ_LIBRARIES} ${MUSIC_LIBRARIES} ${PTHREAD} ${MPI_LIBRARIES} ${JSONCPP_LIBRARY} rtclock)
target_link_libraries(discretize_adapter musicadapter ${ZMQ_LIBRARIES} ${MUSIC_LIBRARIES} ${PTHREAD} ${MPI_LIBRARIES} ${JSONCPP_LIBRARY} rtclock)
target_link_libraries(argmax_adapter musicadapter ${ZMQ_LIBRARIES} ${MUSIC_LIBRARIES} ${PTHREAD} ${MPI_LIBRARIES} ${JSONCPP_LIBRARY} rtclock)
target_link_libraries(cont_cont_adapter musicadapter ${ZMQ_LIBRARIES} ${MUSIC_LIBRARIES} ${PTHREAD} ${MPI_LIBRARIES} ${JSONCPP_LIBRARY} ${GSL} ${BLAS} rtclock)
target_link_libraries(threshold_adapter musicadapter ${ZMQ_LIBRARIES} ${MUSIC_LIBRARIES} ${PTHREAD} ${MPI_LIBRARIES} ${JSONCPP_LIBRARY} ${GSL} ${BLAS} rtclock)


# Encoders
add_executable(rate_encoder encoder/RateEncoder.cpp)

target_link_libraries(rate_encoder musicadapter ${MUSIC_LIBRARIES} ${PTHREAD} ${MPI_LIBRARIES} rtclock)



# Decoders 
add_executable(linear_decoder decoder/LinearDecoder.cpp)

target_link_libraries(linear_decoder musicadapter ${MUSIC_LIBRARIES} ${PTHREAD} ${MPI_LIBRARIES} rtclock)


#add_executable(zmq_in_adapter adapters/zmq_in_adapter.cpp)
#add_executable(zmq_out_adapter adapters/zmq_out_adapter.cpp)
#add_executable(ros_command_adapter adapters/ros_command_adapter.cpp)
#add_executable(ros_sensor_adapter adapters/ros_sensor_adapter.cpp)
#add_executable(ros_event_sensor_adapter adapters/ros_event_sensor_adapter.cpp)
#add_executable(linear_readout_decoder decoder/linear_readout.cpp)
#add_executable(nef_encoder encoder/nef_encoder.cpp)
#add_executable(connect_adapter adapters/connect.cpp)
#add_executable(discretize_adapter adapters/discretize.cpp)
#add_executable(argmax_adapter adapters/argmax_adapter.cpp)
#add_executable(round_adapter adapters/round_adapter.cpp)
#add_executable(rate_encoder encoder/rate_encoder.cpp)
#add_executable(poisson_encoder encoder/poisson_encoder.cpp)
#
#target_link_libraries(zmq_in_adapter ${ZMQ_LIBRARIES} ${MUSIC_LIBRARIES} ${PTHREAD} ${MPI_LIBRARIES} ${JSONCPP_LIBRARY} rtclock)
#target_link_libraries(zmq_out_adapter ${ZMQ_LIBRARIES} ${MUSIC_LIBRARIES} ${PTHREAD} ${MPI_LIBRARIES} ${JSONCPP_LIBRARY} rtclock)
#target_link_libraries(ros_command_adapter ${catkin_LIBRARIES} ${MUSIC_LIBRARIES} ${PTHREAD} ${MPI_LIBRARIES} ${JSONCPP_LIBRARY} rtclock)
#target_link_libraries(ros_sensor_adapter ${catkin_LIBRARIES} ${MUSIC_LIBRARIES} ${PTHREAD} ${MPI_LIBRARIES} ${JSONCPP_LIBRARY} rtclock)
#target_link_libraries(ros_event_sensor_adapter ${catkin_LIBRARIES} ${MUSIC_LIBRARIES} ${PTHREAD} ${MPI_LIBRARIES} rtclock)
#target_link_libraries(linear_readout_decoder ${MUSIC_LIBRARIES} ${MPI_LIBRARIES} ${JSONCPP_LIBRARY} ${GSL} ${BLAS})
#target_link_libraries(nef_encoder ${MUSIC_LIBRARIES} ${MPI_LIBRARIES})
#target_link_libraries(rate_encoder ${MUSIC_LIBRARIES} ${MPI_LIBRARIES}) 
#target_link_libraries(poisson_encoder ${MUSIC_LIBRARIES} ${MPI_LIBRARIES})
#target_link_libraries(argmax_adapter ${MUSIC_LIBRARIES} ${MPI_LIBRARIES})
#target_link_libraries(round_adapter ${MUSIC_LIBRARIES} ${MPI_LIBRARIES})
#target_link_libraries(connect_adapter ${MUSIC_LIBRARIES} ${MPI_LIBRARIES} ${JSONCPP_LIBRARY} ${GSL} ${BLAS})
#target_link_libraries(discretize_adapter ${MUSIC_LIBRARIES} ${MPI_LIBRARIES} ${JSONCPP_LIBRARY})

# COPY PYTHON FILES TO ROOT DIRECTORY
# TODO what for?
# file(COPY "adapters/pca.py" DESTINATION "./")

#install(TARGETS
#    zmq_in_adapter
#    zmq_out_adapter
#    ros_command_adapter
#    ros_sensor_adapter
#    ros_event_sensor_adapter
#    linear_readout_decoder
#    nef_encoder
#    rate_encoder
#    poisson_encoder
#    connect_adapter
#    discretize_adapter
#    argmax_adapter
#    round_adapter
#    RUNTIME DESTINATION bin
#)



