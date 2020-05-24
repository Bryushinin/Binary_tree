#include "bintree_header.h"

tree* Make(int n)
{
    tree* B=(tree*)malloc(sizeof(tree));
    B->id=n;
    B->left=NULL;
    B->right=NULL;
    B->weight=rand()%3-1;
    B->pos=0;
    return(B);
}

void Insertt(int x, tree** A)
{
    tree* C=*A;
    tree* t=C;
        while(C)
        {
            t=C;
            if(x<=(C->id))
                C=C->left;
            else
                C=C->right;
        }
        if(t)
        {
            if(x<=(t->id))
                t->left=Make(x);
            else
                t->right=Make(x);
        }
        else
            t=Make(x);
}

void Mmake(int n, tree **A)
{
    int i,k;
    for(i=0;i<n;++i)
    {
        k=rand()%101;
        Insertt(k,A);
    }
}



void show(tree *t, int n)
{
  if (t)
  {
    show(t->left, n + 1);
    cout << setw(n * 3)<< t->id <<"("<<t->weight<<")"<< endl;
    show(t->right, n + 1);
  }
}

void PrisheiKobileHvost(tree** Ll)
{
    tree* L=*Ll;
    int x=L->left->id,y=L->left->weight;
    tree *l=L->left->left, *r=L->left->right;
    //free(L->left);
    L->id=x;
    L->left=l;
    L->right=r;
    L->weight=y;
}

void PrisheiKozeBayan(tree** Rr)
{
    tree* R=*Rr;
    int x=R->right->id,y=R->right->weight;
    tree *l=R->right->left, *r=R->right->right;
    //free(R->right);
    R->id=x;
    R->right=r;
    R->left=l;
    R->weight=y;
}

void Pop(int x, tree** A)
{
    tree* C=*A;
    tree* t=C;
    int route=2;
    while(C->id != x)
    {

        t=C;
        if(x<=(C->id))
                {C=C->left;route=0;}
            else
                {C=C->right;route=1;}
        if(!C)
        {
            cout<<"Net takogo";
            exit(88);
        }
    }
    if(!((C->right)||(C->left)))
    {
        if(route!=2)
            {
                if(route)
                    t->right=NULL;
                else
                    t->left=NULL;
                free(C);
            }
        else
        {
            //cout<<"ZH";
            *A=NULL;
            free(*A);
        }
    }
    else
    {
        if(C->left && C->right)
        {
            ///seek and destroy
            tree* S=C->left,*te=NULL;//cout<<"|"<<S->id<<"|";
            while(S->right)
                {te=S;S=S->right;}
            int y=S->id,z=S->weight;
            if(S->left)
                PrisheiKobileHvost(&S);
            else
            {
                if(te)
                    te->right=NULL;
                else
                    C->left=NULL;
                S=NULL;
            }
            C->id=y;
            C->weight=z;
        }
        else
        {
            if(C->left)
                PrisheiKobileHvost(&C);
            else
                PrisheiKozeBayan(&C);
        }
    }
}


int Urovni(tree* A, int n)
{
    if(!((A->left)||(A->right)))
        return(n+1);
    else
        if((A->left)&&(A->right))
            return(max(Urovni(A->left,n+1),Urovni(A->right,n+1)));
        else
            if(A->left)
                return(Urovni(A->left,n+1));
            else
                return(Urovni(A->right,n+1));
}

void WriteRow(tree* A,int u,int t)
{
    if(u==1)
        cout<<A->id;
    else
    {
        int f1=0,f2=0;
        if(A->left)
            f1=1;
        if(A->right)
            f2=1;
        if(t!=(u-1))
        {
            if(f1)
                WriteRow(A->left,u,t+1);
            if(f2)
                WriteRow(A->right,u,t+1);
        }
        else
        {
            if(f1)
                cout<<A->left->id<<" ";
            if(f2)
                cout<<A->right->id<<" ";
        }
    }
}

void IDZ(tree** A, int n)
{
    int u=1,a[n+2],f=1,i;
    for(i=1;i<n+1;++i)
        a[i]=0;
    tree* C=*A;
    while(f)
    {
        f=0;
        if((C->left)&&(! C->left->pos))
            {C=C->left;++u;f=1;}
        else
            if((C->right)&&(! C->right->pos))
                {C=C->right;++u;f=1;}
            else
                {
                    a[u]+=C->weight;
                    if(C!=*A)
                        f=1;
                    C->pos=1;
                    C=*A;
                    u=1;
                }
    }
    int ma=-1;
    for(i=1;i<n+1;++i)
        if(a[i]>ma)
            ma=a[i];
    for(i=1;i<n+1;++i)
    {
        cout<<endl;
        if(a[i]==ma)
            WriteRow(*A,i,1);
    }


    C=*A;
    u=1;f=1;
    while(f)
    {
        f=0;
        if((C->left)&&( C->left->pos))
            {C=C->left;++u;f=1;}
        else
            if((C->right)&&( C->right->pos))
                {C=C->right;++u;f=1;}
            else
                {
                    if(C!=*A)
                        f=1;
                    C->pos=0;
                    C=*A;
                    u=1;
                }
    }
}

void Menu(tree** A)
{
    int k;
    cout<<endl;
    cout<<"Add a number - 1"<<endl;
    cout<<"Delete a number - 2"<<endl;
    cout<<"Print the tree - 3"<<endl;
    cout<<"Print the heaviest row - 4"<<endl;
    cout<<"Enough - 0"<<endl;
    cin>>k;
    if(k)
    {
        if(k==1)
        {
            cout<<"Enter a number for program to add:"<<endl;
            int x;
            cin>>x;
            Insertt(x,A);
            Menu(A);
        }
        if(k==2)
        {
            cout<<"Enter a number for program to delete:"<<endl;
            int x;
            cin>>x;
            Pop(x,A);
            Menu(A);
        }
        if(k==3)
        {
            show(*A,5);
            Menu(A);
        }
        if(k==4)
        {
            IDZ(A,Urovni(*A,0));
            Menu(A);
        }
    }
}
