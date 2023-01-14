cmake_minimum_required(VERSION 3.0.0)
project(Paterns CXX)

set(CXX_STANDARD C20)

set(FACTORY_SOURCES Factory.cpp)
set(ABSTRACT_FACTORY_SOURCES AbstractFactoryUse.cpp AbstractFactory.cpp)
set(ADAPTER_SOURCES Adapter.cpp)
set(PROTOTYPE_SOURCES Prototype.cpp)

# Uncomment to try
add_executable(Paterns 
    #${FACTORY_SOURCES}
    #${ABSTRACT_FACTORY_SOURCES}
    #${ADAPTER_SOURCES}
    #${PROTOTYPE_SOURCES}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
