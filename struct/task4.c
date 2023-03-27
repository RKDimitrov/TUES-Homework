#include <stdio.h>
#include <stdlib.h>

typedef union{
    long odd;
    short even;
}complex;

int main() {
    complex arr[10];

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            arr[i].even = i;
        }
        else {
            arr[i].odd = i;
        }
    }

    for (int i = 1; i < 10; i += 2) {
        printf("%d\n", arr[i].odd);
    }

    for (int i = 0; i < 10; i += 2) {
        printf("%d\n", arr[i].even);
    }

    return 0;
}
