#include <stdbool.h>
#include <stdlib.h>

typedef struct Singleton {
    int id;
    int other;
} Singleton;

Singleton* Singleton_Get() {
    static Singleton singleton = {1, 1};
    return &singleton;
}

static Singleton* singleton = NULL;
static bool isInitialized = false;

Singleton* Singleton_GetOnHeapWithLazyEvaluation() {

    if(!isInitialized) {
        singleton = (Singleton*)malloc(sizeof(Singleton));
        singleton->id = 0;
        singleton->other = 0;

        isInitialized = true;
    }

    return singleton;
}

void Singleton_Destroy() {
    if(isInitialized) {
        free(singleton);
    }
}