#include <stdio.h>

typedef struct Product {
    int id;
    char* name;
} Product;

typedef struct Factory {
    Product (*GetNewModel)();
    //Can be with inner state
} Factory;

Product Laptop_Factory_GetNewModel(){
    static char* name = "Laptop";
   Product product = {1, name}; 
   return product;
}

Product Smartphone_Factory_GetNewModel(){
    static char* name = "Smartphone";
    Product product = {2, name}; 
    return product;
}

void ClientCode(const Factory* creator) {
    Product model = creator->GetNewModel();
    printf("%s with id %d\n", model.name, model.id);
}

int main(int argc, char* argv[]) {
    printf("Give Laptop Creator.\n");
    Factory creator_laptop = {&Laptop_Factory_GetNewModel};
    ClientCode(&creator_laptop);

    printf("Give Smartphone Creator.\n");
    Factory creator_smartphone = {&Smartphone_Factory_GetNewModel};
    ClientCode(&creator_smartphone);

    return 0;
}