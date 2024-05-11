#include <iostream>
using namespace std;

void print(const char *s) {
    printf(s);
}

int main() {
    char* charArray = new char[12]{"Hello World"};
    print(charArray);
    return 0;
}