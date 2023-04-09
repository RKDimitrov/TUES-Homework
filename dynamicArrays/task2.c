#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char firstname[50];
    struct Node* father;
    struct Node* mother;
    struct Node* marriedto;
};

struct Node* createNode(char* firstname) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node->firstname, firstname);
    node->father = NULL;
    node->mother = NULL;
    node->marriedto = NULL;
    return node;
}

void connectNodes(struct Node* node1, struct Node* node2) {
    node1->marriedto = node2;
    node2->marriedto = node1;
}

void printFamilyTree(struct Node* node, int generation) {
    int i;
    for (i = 0; i < generation; i++) {
        printf("\t");
    }
    printf("%s\n", node->firstname);
    if (node->father != NULL) {
        printFamilyTree(node->father, generation + 1);
    }
    if (node->mother != NULL) {
        printFamilyTree(node->mother, generation + 1);
    }
}

int main() {
    struct Node* adam = createNode("Adam");
    struct Node* eve = createNode("Eve");
    struct Node* cain = createNode("Cain");
    struct Node* abel = createNode("Abel");
    struct Node* seth = createNode("Seth");
    struct Node* enoch = createNode("Enoch");

    connectNodes(adam, eve);
    connectNodes(cain, abel);
    connectNodes(adam, cain);
    connectNodes(adam, abel);
    connectNodes(eve, seth);
    connectNodes(seth, enoch);

    printFamilyTree(adam, 0);

    return 0;
}
