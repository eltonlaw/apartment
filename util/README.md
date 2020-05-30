# utils

## Setup

Intall Unity (testing framework)

    git clone git@github.com:ThrowTheSwitch/Unity.git
    cd Unity
    mkdir build/
    cd build
    cmake ..
    make
    sudo cp libunity.a /usr/local/lib
    sudo cp ../src/unity.h /usr/local/include
    sudo cp ../src/unity_internals.h /usr/local/include
