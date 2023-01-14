#include <stdio.h>
#include <stdlib.h>

#include "AbstractFactory.h"

typedef struct LaptopInnerState {
    char* videoCardName;
} LaptopInnerState;

Product LaptopCreate(char* videoCardName);
void LaptopDestroy(Product* product);
void LaptopOperation(Product* product);

typedef struct SmartphoneInnerState {
    int id;
} SmartphoneInnerState;

Product SmartphoneCreate(int numOfCards);
void SmartphoneDestroy(Product* product);
void SmartphoneOperation(Product* product);

Product LaptopCreate(char* videoCardName) {
    LaptopInnerState* state = (LaptopInnerState*) malloc(sizeof(LaptopInnerState));
    state->videoCardName = videoCardName;

    Product product = {state, &LaptopDestroy, &LaptopOperation};
    return product;
}

void LaptopDestroy(Product* product) {
    free(product->innerState);
    printf("Laptop Destroy\n");
}

Product SmartphoneCreate(int id) {
    SmartphoneInnerState* state = (SmartphoneInnerState*) malloc(sizeof(SmartphoneInnerState));
    state->id = id;

    Product product = {state, &SmartphoneDestroy, &SmartphoneOperation};
    return product;
}

void SmartphoneDestroy(Product* product) {
    free(product->innerState);
    printf("Smartphone Destroy\n");
}

void LaptopOperation(Product* product) {
    LaptopInnerState* state = (LaptopInnerState*)(product->innerState);
    printf("Laptop VideoCardName - \"%s\"\n", state->videoCardName);
}

void SmartphoneOperation(Product* product) {
    SmartphoneInnerState* state = (SmartphoneInnerState*)(product->innerState);
    printf("Smartphone ID = %d\n", state->id);
}

Product LaptopFactory_GetNewModel(){
    static char* videoCardName = "Nvidia";
    //Can make some loggic for choosing a card
    return LaptopCreate(videoCardName);
}

Product SmartphoneFactory_GetNewModel(){
    static int id = 0;
    id += 1;
    return SmartphoneCreate(id);
}