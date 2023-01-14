#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H

typedef struct Product {
    void* innerState; // private fields

    void (*Destroy)(struct Product* product);
    void (*Operation)(struct Product* product); //virtual function
} Product;

typedef struct Factory {
    Product (*GetNewModel)();
    // Can be with inner state
} Factory;

Product LaptopFactory_GetNewModel();
Product SmartphoneFactory_GetNewModel();

#endif