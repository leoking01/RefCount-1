cmake_policy(VERSION 3.9)
cmake_minimum_required(VERSION 3.9)

project( refcount_1 VERSION 1.202006261423 )
#<major>[.<minor>[.<patch>[.<tweak>

if(1)
    set (PclVision_VERSION_MAJOR 2)
    set (PclVision_VERSION_MINOR 202006261423)
endif()

#set(CMAKE_CXX_STANDARD  17 )
#set(CMAKE_CXX_STANDARD  11 )
set(CMAKE_CXX_STANDARD_REQUIRED True)

#------------------qt5 must --------------------
#注意，在一个大工程里，这几个开关一定要尽量放在前面打开，否则有可能会报无法生成ui文件的错误
set(CMAKE_AUTOMOC ON)#自动翻译信号与槽
set(CMAKE_AUTORCC ON)#自动翻译资源文件为cpp文件
set(CMAKE_AUTOUIC ON)#自动翻译界面文件为cpp文件
set(CMAKE_INCLUDE_CURRENT_DIR ON)

##-------------- 自己的库libHello -------------

include_directories(${PROJECT_SOURCE_DIR}/libHello)
#target_link_libraries(hello libhello)
#link_directories(${PROJECT_SOURCE_DIR})
link_directories( "${PROJECT_BINARY_DIR}/lib"  )
link_directories( "${PROJECT_BINARY_DIR}/lib"  )
message( "(lk)___________show: PROJECT_SOURCE_DIR____________________  ")
message( ${PROJECT_SOURCE_DIR})
message( "(lk)___________show: PROJECT_SOURCE_DIR finish ____________  ")

#----------------------------------------version------------------------------
############################################
option(USE_MYMATH "Use tutorial provided math implementation" ON)
#configure_file(TutorialConfig.h.in TutorialConfig.h)
#Since the configured file will be written into the binary tree, we must add that directory to the list of paths to search for include files. Add the following lines to the end of the CMakeLists.txt file:


##-----------------------------------------qt5-------------------------------
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)
message( "(0)(lk)________ Qt5 _______:  ")
#FIND_PACKAGE (QT5 REQUIRED)
#INCLUDE(${QT_USE_FILE})
INCLUDE_DIRECTORIES (${CMAKE_CURRENT_BINARY_DIR})
ADD_DEFINITIONS (${QT_DEFINITIONS})

find_package(Qt5Widgets)
set(CMAKE_PREFIX_PATH $ENV{QTDIR594})
#find_package(Qt5 COMPONENTS Widgets    Core Gui Qml Quick REQUIRED)
find_package(Qt5 COMPONENTS Core Gui  Widgets Qml Quick REQUIRED)
#message(${Qt5Widgets})

INCLUDE_DIRECTORIES ("F:/win10/Qt5.12.3/5.12.3/msvc2017/include/QtWidgets")
find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Gui)
find_package(Qt5OpenGL)
find_package(Qt5Xml)
message( "  find   qt5   finish.\n\n")


#----------------------------------------header soruces -------------------------------
set(HEADERS
  Ptr.h
  )

#set(SOURCES
#    main.cpp    mainwindow.cpp    test.h
#    commonfunc.h    mainapp.h    mainwindow.h
#    )

#set(RESOURCES
#    pro.qrc    #  tools/ToolBase.cpp
#    )

#set(QMLS
#    main.qml
#)


# 搜集指定目录 . 和./MyClass 下的源文件，将输出结果列表储存到变量ALL_SOURCE中
aux_source_directory(. ALL_SOURCE)
aux_source_directory(${PROJECT_SOURCE_DIR}/src  ALL_SOURCE)
aux_source_directory(./  ALL_SOURCE)
aux_source_directory(./common  ALL_SOURCE)
aux_source_directory(./tools  ALL_SOURCE)
aux_source_directory(./ui  ALL_SOURCE)

# 包含进目录 gen_pcd/
#include_directories("${PROJECT_SOURCE_DIR}/gen_pcd")
include_directories("${PROJECT_BINARY_DIR}")
#ui_mainwindow.h
link_directories("${PROJECT_BINARY_DIR}/lib")

include_directories("${PROJECT_SOURCE_DIR}/libHello")
include_directories("./" ./common  ./tools   ./ui  )


message( “\n\n\n __________________PROJECT_SOURCE_DIR____________________” )
message(  ${PROJECT_SOURCE_DIR}  )
message( “\n\n\n ” )

message( “\n\n\n _________________ PROJECT_BINARY_DIR  __________________” )
message(  ${PROJECT_BINARY_DIR}  )
message( “\n\n\n ” )

#--------------------------------------------qt5 relate-------------------------------------------------
#add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${RESOURCES} ${QMLS})
#qt5_wrap_ui(ui_FILES mainwindow.ui   )
qt5_wrap_ui(ui_FILES *.ui   )
file(GLOB_RECURSE FORMS "*.ui")

#D:\awsPcl\AppPclVision\pcl191X64\thirdpartx64
set( Lib_dep_root    "F:/win10/pcl191X64/thirdpartx64")



#D:\win10\cv310Vs2015DebugReleaseNoCaffe\x64\vc14\lib
if( MSVC )
    set(dep_lib_path  "d:\\win10")
    if(  1 )
        set(OPencv_base_dir  "${dep_lib_path}\\cv341Vs2015Cuda8")
        set(OPencv_base_dir  "${dep_lib_path}\\cv310Vs2015DebugReleaseNoCaffePlus")
        # set(OPencv_base_dir  "${dep_lib_path}\\Cv451OpenCLVs2015")
        set(OPencv_base_dir  "${dep_lib_path}\\cv3413")
        #    set(OpenCV_DIR  "${OPencv_base_dir}/x64/vc14/lib"  )
        set(OpenCV_DIR  "${OPencv_base_dir}/build/x64/vc15/lib"  )
        set(OpenCV_DIR  "${OPencv_base_dir}/build/x64/vc14/lib"  )
        find_package(OpenCV
            #                EXACT 4.5.1
            #        EXACT 3.4.1
            #        EXACT 3.1.0
            EXACT 3.4.13
            #    EXACT 2.4.13.6
            REQUIRED  PATHS "${OPencv_base_dir}"
            NO_DEFAULT_PATH
            NO_PACKAGE_ROOT_PATH
            NO_CMAKE_PATH
            NO_CMAKE_ENVIRONMENT_PATH
            NO_SYSTEM_ENVIRONMENT_PATH
            NO_CMAKE_PACKAGE_REGISTRY
            NO_CMAKE_BUILDS_PATH  # Deprecated; does nothing.
            NO_CMAKE_SYSTEM_PATH
            )
        LINK_DIRECTORIES( "${OPencv_base_dir}/x64/vc14/lib" )
        INCLUDE_DIRECTORIES("${OPencv_base_dir}/include")
    endif()
    message( "\n\n")
    message( "__________________________________________________________________")
    message( "opencv info(lk):  ")
    message( "___________________OpenCV_INCLUDE_DIRS____________________________")
    message( ${OpenCV_INCLUDE_DIRS})
    message( "___________________ OpenCV_CONFIG_PATH ___________________________")
    message( ${OpenCV_CONFIG_PATH})
    message( "___________________ OpenCV_SHARED ________________________________")
    message( ${OpenCV_SHARED})
    message( "___________________ OpenCV_USE_MANGLED_PATHS _____________________")
    message( ${OpenCV_USE_MANGLED_PATHS})
    #message( "___________________ OpenCV_COMPUTE_CAPABILITIES _________________")
    #message( ${OpenCV_COMPUTE_CAPABILITIES})
    message( "___________________OpenCV_LIBRARIES_______________________________")
    message( ${OpenCV_LIBRARIES})
    message( "___________________ OpenCV_LIBS __________________________________")
    message( ${OpenCV_LIBS})
    message( "___________________ OpenCV_VERSION _______________________________")
    message( ${OpenCV_VERSION})
    message( "___________________ OpenCV_LIB_COMPONENTS ________________________")
    message( ${OpenCV_LIB_COMPONENTS})
    message( "___________________var in  OpenCV_LIBRARIES ______________________")
    foreach( var ${OpenCV_LIBRARIES} )
        message( ${var} )
    endforeach()
    message( "\n\n")

    if(  1  )
        set(eigen_dir "${dep_lib_path}\\DepBundleCVBaseCV451/eigen-3.3.7\\x64\\share\\eigen3\\cmake")
        find_package(  EIGEN3 REQUIRED PATHS  "${dep_lib_path}\\DepBundleCVBaseCV451/eigen-3.3.7/x64" )
        INCLUDE_DIRECTORIES (${EIGEN3_INCLUDE_DIRS})
        INCLUDE_DIRECTORIES ( "${dep_lib_path}\\DepBundleCVBaseCV451/eigen-3.3.7\\x64\\include\\eigen3")
        add_definitions( ${EIGEN3_DEFINITIONS})
    endif()

elseif(UNIX )
    #REQUIRED
    #set(OpenCV_DIR     ~/installCv3414Ubun2104FullNew/share/OpenCV     )
    #set(Opencv_rot_my   ~/cv3414Bundle/installCv3414Ubun2104FullNew  )
    set(Opencv_rot_my   /home/alex/installCv3414Ubun2104FullNew  )
    set(OpenCV_DIR     ${Opencv_rot_my}/share/OpenCV     )
    find_package(   opencv    PATHS    ${Opencv_rot_my}/share/OpenCV    )
    include_directories(   ${Opencv_rot_my}/include
        ${Opencv_rot_my}/include/opencv
        ${Opencv_rot_my}/include/opencv2
        )
    link_directories( ${Opencv_rot_my}/lib )

    include_directories(     "/home/alex/halcon-19.11.0.0-linux/include/halconcpp"
        "/home/alex/halcon-19.11.0.0-linux/include"  )
    link_directories(   "/home/alex/halcon-19.11.0.0-linux/lib/x64-linux"  )

endif()



#-----------------------------------------添加子文件夹，不添加子库--------------------------------------------------
# 用include 和 aux_source_directory allsource
link_directories("${PROJECT_BINARY_DIR}/lib")

#--------------------------------------------project------------------------------------------------------
#####################################做成动态库########################################################
#----------------------------------------------
if(0)
    #add_library( aa.lib   SHARED   ${HEADERS} ${SOURCES} ${FORMS} )  # ALL_SOURCE
    add_library( aa.lib   SHARED   ${HEADERS} ${ALL_SOURCE} ${FORMS} )  # ALL_SOURCE
    target_link_libraries( aa.lib PUBLIC  Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Qml Qt5::Quick
        ${PCL_LIBRARIES}   ${BOOST_LIBRARIES} ${VTK_LIBRARIES}
        libboost_atomic-vc141-mt-gd-x32-1_68
        ${EXTRA_LIBS}
        ${OpenCL_LIBRARIES}
        ${GLFW3_LIBRARIES}
        ${CUDA_LIBRARIES}
        OpenCL  cuda cudadevrt cudart
        ${VULKAN_LIBRARIES}
        #  ${glew_LIBRARIES}
        ${freeglut_LIBRARIES}
        glew32d
        )
endif()

if(UNIX )
    set(LIBS_RELATED       ${OpenCV_LIBS}
        libopencv_core.so   libopencv_highgui.so  libopencv_imgcodecs.so
        libopencv_imgproc.so   libopencv_videoio.so     libopencv_ml.so
        libopencv_features2d.so  libopencv_flann.so  libopencv_objdetect.so
        #    -lpng  -lthread -ljpeg  -lpng16
        #     nlohmann_json::nlohmann_json
        #     tinyxml2::tinyxml2
        #     glog::glog
        -lhalconcpp -lhalcon -lXext -lX11 -ldl -lpthread   )
elseif(MSVC )
    set(LIBS_RELATED       ${OpenCV_LIBS}
        libopencv_core.so   libopencv_highgui.so  libopencv_imgcodecs.so
        libopencv_imgproc.so   libopencv_videoio.so     libopencv_ml.so
        libopencv_features2d.so  libopencv_flann.so  libopencv_objdetect.so
        #    -lpng  -lthread -ljpeg  -lpng16
        #     nlohmann_json::nlohmann_json
        #     tinyxml2::tinyxml2
        #     glog::glog
        -lhalconcpp -lhalcon -lXext -lX11 -ldl -lpthread   )
endif()

######################################生成exe#######################################################
#set(EXECUTABLE_OUTPUT_PATH   ${PROJECT_BINARY_DIR}/../bin)
#set(LIBARARY_OUTPUT_PATH   ${PROJECT_BINARY_DIR}/../lib )
set(LIBRARY_OUTPUT_PATH   ${CMAKE_BINARY_DIR}/../bin   )
set(EXECUTABLE_OUTPUT_PATH   ${CMAKE_BINARY_DIR}/../bin   )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY   ${CMAKE_BINARY_DIR}/../bin   )
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY      ${CMAKE_BINARY_DIR}/../lib   )



add_executable(refcount_1   MACOSX_BUNDLE    ${SOURCES}   ${ALL_SOURCE} ${FORMS}  ${RESOURCES}    ${HEADERS}   )

# ${EXTRA_LIBS}
if(  1 )
    target_link_libraries(refcount_1
        Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Qml Qt5::Quick
        #        pcl_common_debug  pcl_features_debug pcl_filters_debug pcl_io_debug pcl_io_ply_debug
        # pcl_kdtree_debug  pcl_keypoints_debug pcl_octree_debug pcl_outofcore_debug pcl_recognition_debug
        #        pcl_registration_debug  pcl_sample_consensus_debug pcl_search_debug
        #        pcl_segmentation_debug pcl_stereo_debug pcl_surface_debug pcl_tracking_debug
        ##                pcl_visualization_debug
        #        ${PCL_LIBRARIES}
        # ${VTK_LIBRARIES}
        #  ${BOOST_LIBRARIES}
        ${EXTRA_LIBS}
        #        ${OpenCL_LIBRARIES}
        #        ${GLFW3_LIBRARIES}
        #   ${CUDA_LIBRARIES}
        #  ${VULKAN_LIBRARIES}
        #  ${glew_LIBRARIES}
        #        ${freeglut_LIBRARIES}
        #        ${GLFW3_LIBRARIES}
        ${OpenCV_LIBRARIES}    ${LIBS_RELATED}
        # ${jsoncpp_LIBRARIES}
        ##        hello
        #        MathFunctions
        #        jsoncpp
        # ${tinyxml2_LIBRARIES}
        #        ${log4cplus_LIBRARIES}
        #        PRIVATE nlohmann_json::nlohmann_json
        )
endif()


message( "(6)(lk)__________ project ___________:  ")
message( "project info(lk):  ")
message( ${PROJECT_NAME})
#message( ${HEADERS})
#message( ${SOURCES})
#message( ${ALL_SOURCE})
#message( ${FORMS} )


#------------------------------------------- version ------------------------------------------------
include_directories(${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/MathFunctions
    ${PROJECT_SOURCE_DIR}/gen_kcd
    ${PROJECT_SOURCE_DIR}/usages
    ${OpenCL_INCLUDE_DIRS}

    )
#PclVision
target_include_directories( ${PROJECT_NAME} PUBLIC
    ${PROJECT_BINARY_DIR}
    ${EXTRA_INCLUDES}        )






#-------------------install  destation ---------------------------
#set( DESTINATION  "../install/")
set( CMAKE_INSTALL_PREFIX  "../install/")
#          And to the end of the top-level CMakeLists.txt we add:
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
#install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"  DESTINATION include  )


if( 0 )
    #
    # Format the project using the `clang-format` target (i.e: cmake --build build --target clang-format)
    #
    #add_clang_format_target()
    #
    # Install library for easy downstream inclusion
    #
    include(GNUInstallDirs)
    install(
        TARGETS
        ${PROJECT_NAME}
        EXPORT
        ${PROJECT_NAME}Targets
        LIBRARY DESTINATION
        ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION
        ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION
        ${CMAKE_INSTALL_LIBDIR}
        INCLUDES DESTINATION
        include
        PUBLIC_HEADER DESTINATION
        include
        )

    install(
        EXPORT
        ${PROJECT_NAME}Targets
        FILE
        ${PROJECT_NAME}Targets.cmake
        NAMESPACE
        ${PROJECT_NAME}::
        DESTINATION
        ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
        )

    #
    # Add version header
    #

    configure_file(
        ${CMAKE_CURRENT_LIST_DIR}/cmake/version.hpp.in
        include/${PROJECT_NAME_LOWERCASE}/version.hpp
        @ONLY
        )

    install(
        FILES
        ${CMAKE_CURRENT_BINARY_DIR}/include/${PROJECT_NAME_LOWERCASE}/version.hpp
        DESTINATION
        include/${PROJECT_NAME_LOWERCASE}
        )

    #
    # Install the `include` directory
    #

    install(
        DIRECTORY
        #    include/${PROJECT_NAME_LOWERCASE}
        interfaceA/${PROJECT_NAME_LOWERCASE}
        DESTINATION
        include
        )

    #verbose_message("Install targets succesfully build. Install with `cmake --build <build_directory> --target install --config <build_config>`.")

    #
    # Quick `ConfigVersion.cmake` creation
    #

    include(CMakePackageConfigHelpers)
    write_basic_package_version_file(
        ${PROJECT_NAME}ConfigVersion.cmake
        VERSION
        ${PROJECT_VERSION}
        COMPATIBILITY
        SameMajorVersion
        )

    configure_package_config_file(
        ${CMAKE_CURRENT_LIST_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
        INSTALL_DESTINATION
        ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
        )

    install(
        FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION
        ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
        )

    #
    # Generate export header if specified
    #

    if(${PROJECT_NAME}_GENERATE_EXPORT_HEADER)
        include(GenerateExportHeader)
        generate_export_header(${PROJECT_NAME})
        install(
            FILES
            ${PROJECT_BINARY_DIR}/${PROJECT_NAME_LOWERCASE}_export.h
            DESTINATION
            include

            )

        message(STATUS "Generated the export header `${PROJECT_NAME_LOWERCASE}_export.h` and installed it.")
    endif()

    message(STATUS "Finished building requirements for installing the package.\n")

    #
    # Unit testing setup
    #
    if(  0 )
        if(${PROJECT_NAME}_ENABLE_UNIT_TESTING)
            enable_testing()
            message(STATUS "Build unit tests for the project. Tests should always be found in the test folder\n")
            add_subdirectory(test)
        endif()
    endif()
endif()


