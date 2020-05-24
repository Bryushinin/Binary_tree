#ifndef BINTREE_HEADER_H_INCLUDED
#define BINTREE_HEADER_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

typedef struct link
{
    int id;
    link *left, *right;
    int weight;
    int pos;
}tree;

tree *Make(int n);
void Insertt(int x, tree** A);
void Mmake(int n, tree **A);
void Pop(int x, tree** A);
void show(tree *A, int n);
int Urovni(tree* A, int t);
void IDZ(tree** A, int n);
void WriteRow(tree* A, int u, int t);
void Menu(tree** A);

#endif // BINTREE_HEADER_H_INCLUDED
