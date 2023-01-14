#include <stdio.h>

typedef int (* const decorableFnType)(int paramOne, int paramTwo);

int functionOne(int paramOne, int paramTwo) {
	printf("functionOne: %d, %dn", paramOne, paramTwo);
	return 0;
}

int functionTwo(int paramOne, int paramTwo) {
	printf("functionTwo: %d, %dn", paramOne, paramTwo);
	return 0;
}

int functionThree(int paramOne, int paramTwo) {
	printf("functionThree: %d, %dn", paramOne, paramTwo);
	return 0;
}

int decorator(int paramOne, int paramTwo, decorableFnType originalFn) {
	printf("decorator precondition!n");
	originalFn(paramOne, paramTwo);

	return 0;
}

int main(int argc, char **argv) {
	printf("hello, C decorators!n");
	functionOne(1, 2);

	decorator(1, 2, functionOne);
	decorator(1, 2, functionTwo);
	decorator(1, 2, functionThree);

	return 0;
}