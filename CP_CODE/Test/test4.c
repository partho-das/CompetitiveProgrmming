///(using structure members)
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define NEW (list*)malloc(sizeof(list))

struct LIST {
    int id;
    double cgpa;
    struct LIST *next;
};
typedef struct LIST list;

void Add(list **root, int id, double cgpa){
    list *nw = NEW;
    nw->cgpa = cgpa;
    nw->id = id;
    nw->next = NULL;

    if(*root == NULL){
        *root = nw;
        return;
    }
    list *curr = *root;
    while(curr->next != NULL) curr = curr->next;
    curr->next = nw;
}

void Print(list *root){
    if(root == NULL) return;
    printf("%d %lf\n", root->id, root->cgpa);
    Print(root->next);
}

int main()
{
    list *root = NULL;

    Add(&root,7609,3.50);
    Add(&root,7610,3.46);
    Add(&root,7611,3.68);
    Add(&root,7612,3.74);
    Add(&root,7613,3.01);

    Print(root);
    Print(root);

    return 0;
}
