cmake_minimum_required(VERSION 3.0.0)
project(Paterns C)

set(C_STANDARD C17)

set(FACTORY_SOURCES Factory.c)
set(ABSTRACT_FACTORY_SOURCES AbstractFactoryUse.c AbstractFactory.c)
set(DECORATOR_SOURCES Decorator.c)

add_executable(Paterns 
    #${FACTORY_SOURCES}
    #${ABSTRACT_FACTORY_SOURCES}
    #${DECORATOR_SOURCES}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
