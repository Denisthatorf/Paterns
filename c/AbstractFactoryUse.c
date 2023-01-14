#include <stdio.h>

#include "AbstractFactory.h"

void ClientCode(const Factory* factory) {
    Product model = factory->GetNewModel();
    model.Operation(&model);
    model.Destroy(&model);
}

int main(int argc, char* argv[]) {
    printf("Give Laptop Creator.\n");
    Factory creator_laptop = {&LaptopFactory_GetNewModel};
    ClientCode(&creator_laptop);

    printf("Give Smartphone Creator.\n");
    Factory creator_smartphone = {&SmartphoneFactory_GetNewModel};
    ClientCode(&creator_smartphone);
    ClientCode(&creator_smartphone);
    ClientCode(&creator_smartphone);

    return 0;
}