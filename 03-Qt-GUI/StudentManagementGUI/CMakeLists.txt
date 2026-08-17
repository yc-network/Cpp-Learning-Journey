cmake_minimum_required(VERSION 3.19)
project(StudentManagementGUI LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(StudentManagementGUI
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    teacherwindow.h teacherwindow.cpp teacherwindow.ui
    studentwindow.h studentwindow.cpp studentwindow.ui
    studentdata.h studentdata.cpp studentdata.ui
    addstu.h addstu.cpp addstu.ui
    delstu.h delstu.cpp delstu.ui
    showstu.h showstu.cpp showstu.ui
Student.cpp
Student.h
StudentManager.cpp
StudentManager.h
chanstu.h chanstu.cpp chanstu.ui
)

target_link_libraries(StudentManagementGUI
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS StudentManagementGUI
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET StudentManagementGUI
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
