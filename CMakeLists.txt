cmake_minimum_required(VERSION 4.3)
project(Clion_Lab)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab1 "Lab1/Lab 1 N6.cpp"
        main/main.cpp
        "Lab4/Lab 4.cpp")
add_executable(Lab2 "Lab2/Lab 2 .cpp")
add_executable(Lab3 "Lab3/Lab 3.cpp")
add_executable(Lab4 "Lab4/Lab 4.cpp"
        "Lab4/functions.h")
add_executable(Lab5 "Lab5/Lab 5.cpp"
        Lab5/stb_image.h
        Lab5/stb_image_write.h)
add_executable(Modular_V3_1 "Modular 1/modular V3 1.cpp")
add_executable(Modular_V3_2 "Modular 1/modular V3 2.cpp")
add_executable(Modular_V3_3 "Modular 1/modular V3 3.cpp")
add_executable(Modular_V3_4 "Modular 1/modular V3 4.cpp")
add_executable(Modular_V3_5 "Modular 1/modular V3 5.cpp")
add_executable(main  "main/main.cpp")
add_executable(Modular_2_V3_1 "Modular 2/modular 2 V3 1.cpp")
add_executable(Modular_2_V3_2 "Modular 2/modular 2 V3 2.cpp")
add_executable(Modular_2_V3_3 "Modular 2/modular 2 V3 3.cpp")
add_executable(Modular_2_V3_4 "Modular 2/modular 2 V3 4.cpp")
