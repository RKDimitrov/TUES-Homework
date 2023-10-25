#include <stdio.h>

struct File
{
    int owner;
    int group;
    int random;
};


int main(){
    struct File file = {owner:1, group: 0, random: 0};
}