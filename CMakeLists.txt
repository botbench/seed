cmake_minimum_required(VERSION 3.10)

# set the project name
project(seed)

file(GLOB seed_SRC
    "*.h"
    "*.c"
)


# add the executable
add_executable(seed ${seed_SRC})
