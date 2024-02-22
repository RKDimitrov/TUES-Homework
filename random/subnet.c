#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char octet1;
    unsigned char octet2;
    unsigned char octet3;
    unsigned char octet4;
} subnet;

unsigned int get_net_size(subnet mask){
    int net_mask = (mask.octet1 << 24) + (mask.octet2 << 16) + (mask.octet3 << 8) + mask.octet4;
    return (~net_mask) - 1;
}

int main(){
    subnet mask = {255, 255, 255, 128};
    unsigned int net_size = get_net_size(mask);
    printf("Size: %u\n", net_size);
}