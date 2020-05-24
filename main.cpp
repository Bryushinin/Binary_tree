#include "bintree_header.h"


int main()
{
    int n;
    cout<<"Enter the number of nodes in the base tree:"<<endl;
    cin>>n;
    tree *A=Make(rand()%51);
    Mmake(n-1,&A);
    show(A,5);
    Menu(&A);
    /*Insertt(43,&A);
    Insertt(68,&A);
    Insertt(67,&A);
    show(A,5);
    Pop(72,&A);
    show(A,5);
    Pop(100,&A);
    WriteRow(A, 5, 1);*/
    //IDZ(&A, Urovni(A,0));
    return 0;
}
