#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

ull add(ull a, ull b){
    return a + b;
}

ull reduce(ull *arr, ull len, ull (* pf)(ull, ull), ull sv){
    ull result = sv;
    for(ull i = 0; i < len; i++){
        result = pf(result, arr[i]);
    }

    return result;
}

int main(){
    ull arr[] = {1, 2, 3, 4, 5};
    ull len = sizeof(arr) / sizeof(arr[0]);
    ull sv = 0;
    ull result = reduce(arr, len, add, sv);
    printf("%llu", result);

}