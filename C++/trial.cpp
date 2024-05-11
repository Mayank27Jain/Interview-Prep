#include <iostream>
using namespace std;

void f(int * const arr) {
    printf("Const");
}

void f(const int *arr) {
    printf("Arr");
}

int main() {
    f(new const int[12]{0});
}