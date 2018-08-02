#include<iostream>
#include<graphics.h>
#include<fstream>
using namespace std;
//char colors[]={'r','g','y','b','o','v'};
char colors[]={'m','t','w','T','f','s'};



struct edgenode
{
    int src,dest;
    struct edgenode * edgelink;
};
struct edgenode * edgestart=NULL;
struct edgenode * createedgenode(int s,int d)
{
    struct edgenode *temp;
    temp=new edgenode;
    temp->dest=d;
    temp->src=s;
    temp->edgelink=NULL;
    return temp;
};
void insertedgenode(int s,int d )
{
    struct edgenode *t,*p;
    t=createedgenode(s,d);
    if(edgestart==NULL)
    {
        edgestart=t;
    }
    else{
        p=edgestart;
        while(p->edgelink!=NULL)
        {
            p=p->edgelink;
        }
        p->edgelink=t;
       // cout<<"Edge inserted";
    }
}
/*int getadjno(int a,struct edgenode *start)
{
    int n=0;

    struct edgenode *p;
    p=start;
    while(p!=NULL)
    {
        if(p->dest==a || p->src==a)
            n++;
            p=p->edgelink;
    }
    return n;
}*/
struct adjarray
{

};
void getadjacent(int a,struct edgenode *start,int m[7])
{


    int c=0;
  //  static int ar[7]={0,0,0,0,0,0,0};
    struct edgenode *p;
    p=start;
  /*  while(p!=NULL)
    {
        if(p->dest==a || p->src==a)
            n++;
            p=p->edgelink;
    }
    p=start;*/

   while(p!=NULL)
   {
       if(p->src==a)
       {
           m[c]=p->dest;
           c++;
       }
       if(p->dest==a)
       {
           m[c]=p->src;
           c++;
       }
       p=p->edgelink;
       for(int i=c;i<7;i++)
        m[i]=0;
   }
   //return ar;
}
struct vertex
{
    int vrt;
    char color;
    int  *arr;
    struct vertex *vlink;
};
struct vertex * vrtstart=NULL;
struct vertex * createvertex(int v,struct edgenode *start)
{
    struct vertex *t;
    t=new struct vertex;
    t->vrt=v;
   // t->arr=va;
    t->color='a';
    t->vlink=NULL;
   //cout<<t->vrt<<"->";
   t->arr=new int[7];
   getadjacent(v,start,t->arr);
   // t->arr=getadjacent(v,start);
    /*for(int i=0;i<7;i++)
    cout<<t->arr[i]<<"\n";*/
    return t;
};
void vertlist(int v,struct edgenode *start)
{
    struct vertex *t,*p;
    t=createvertex(v,start);
    p=vrtstart;
    if(p==NULL)
    {
//        t->arr=getadjacent(v,start);
                vrtstart=t;
                }
    else
    {
        while(p->vlink!=NULL)
            p=p->vlink;
  //          p->arr=getadjacent(v,start);
        p->vlink=t;
    }
}
void traverse(struct vertex *start)
{
    struct vertex *p,*t;
    p=start;
    while(p!=NULL)
    {
        cout<<p->vrt<<"->";
        for(int i=0;i<7;i++)
            cout<<p->arr[i]<<"\n";
        p=p->vlink;
    }
}
char getcolor1(int d,struct vertex *start)
{
    struct vertex *p;
    p=start;
    while(p!=NULL)
    {
        if(p->vrt==d)
            return p->color;
        p=p->vlink;
    }

}
void graphcoloring(struct vertex *start)
{
    struct vertex *p;
    int i,j;
   start->color='m';
    p=start->vlink;
    while(p!=NULL)
    {
        p->color='m';
         i=0;
         j=1;
        while(p->arr[i]!=0)
        {
                    if(p->color==getcolor1(p->arr[i],start))
        {
            p->color=colors[j];
            //i++;
            j++;
        }
        else
        j++;
        i++;
        }
        p=p->vlink;
    }

}

/*void circle1(int x,int y,int radius)
{
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
    circle(x,y,radius);
    getch();
    closegraph();
}*/
void printcolors(struct vertex *start)
{
    struct vertex *p;
    p=start;
    while(p!=NULL)
    {
        cout<<p->vrt<<"->"<<p->color<<"\n";
        p=p->vlink;
    }
}
int getno(ifstream& f)
{
    int c=0;
    string s;
    while(!f.eof())
    {
        getline(f,s);
        c++;
    }
    return c;
}
void createarrays1(fstream& f,string *s)
{
string st;
int i=0;
while(!f.eof())
{
    getline(f,st);
    s[i]=st;
    i++;
}
}
void createdges()
{
     ifstream f1;
    f1.open("s1.txt");
    ifstream f2,f3,f4,f5,f6;
    int i=0,j=0,x=0,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0;;
    //f1.open("s1.txt");
    f2.open("s2.txt");
    f3.open("s3.txt");
    f4.open("s4.txt");
    f5.open("s5.txt");
    f6.open("s6.txt");
    string st;
    char ch;
    //int f=getno(f1);
  //  cout<<f;
  //  string st2[getno(f2)],st3[getno(f3)],st4[getno(f4)],st5[getno(f5)],st6[getno(f6)];
    string st1[100],st2[100],st3[100],st4[100],st5[100],st6[100];
    for(i=0;i<100;i++)
    {
        st1[i]="d";
        st2[i]="d";
        st3[i]="d";
        st4[i]="d";
        st5[i]="d";
        st6[i]="d";
    }
   // createarrays1(f1,st1);
//cout<<st1[1];
//f1>>ch;
i=0;
while(!f1.eof())
{
    getline(f1,st1[i]);
//cout<<st1[i]<<"\n";
      i++;

    }
   // cout<<"///////";
i=0;
while(!f2.eof())
{
    getline(f2,st);
    st2[i]=st;
  //  cout<<st<<"\n";
    i++;
}
i=0;
//cout<<"///////";
while(!f3.eof())
{
    getline(f3,st);
    st3[i]=st;
  //  cout<<st<<"\n";
    i++;
}
i=0;
//cout<<"///////";
while(!f4.eof())
{
    getline(f4,st);
    st4[i]=st;
    //cout<<st<<"\n";
    i++;
}
i=0;
//cout<<"///////";
while(!f5.eof())
{
    getline(f5,st);
    st5[i]=st;
  //  cout<<st<<"\n";
    i++;
}
i=0;
//cout<<"///////";
while(!f6.eof())
{
    getline(f6,st);
    st6[i]=st;
  //  cout<<st<<"\n";
    i++;
}
while(!(st1[j]=="d"))
{
    x=0;
    while(!(st2[x]=="d"&&st3[x]=="d"&&st4[x]=="d"&&st5[x]=="d"&&st6[x]=="d"))
    {
            if((st1[j].compare(st2[x]))==0&&c1<2)
            {
                insertedgenode(1,2);
                c1++;}
                if((st1[j].compare(st3[x]))==0&&c2<2)
            {
                insertedgenode(1,3);
                c2++;}
                if((st1[j].compare(st4[x]))==0&&c3<2)
            {
                insertedgenode(1,4);
                c3++;}
                if((st1[j].compare(st5[x]))==0&&c4<2)
            {
                insertedgenode(1,5);
                c4++;}
                if((st1[j].compare(st6[x]))==0&&c5<2)
            {
                insertedgenode(1,6);
                c5++;}


        x++;
        }
        j++;
        }
        j=0;
        x=0;
        c1=0;
        c2=0;
        c3=0;
        c4=0;
        c5=0;

       while(!(st2[j]=="d"))
{
    x=0;
    while(!(st3[x]=="d"&&st4[x]=="d"&&st5[x]=="d"&&st6[x]=="d"))
    {
            if((st2[j].compare(st3[x]))==0&&c1<2)
            {
                insertedgenode(2,3);
                c1++;}
                if((st2[j].compare(st4[x]))==0&&c2<2)
            {
                insertedgenode(2,4);
                c2++;}
                if((st2[j].compare(st5[x]))==0&&c3<2)
            {
                insertedgenode(2,5);
                c3++;}
                if((st2[j].compare(st6[x]))==0&&c4<2)
            {
                insertedgenode(2,6);
                c4++;}

        x++;
        }
        j++;
        }
        j=0;
        x=0;
        c1=0;
        c2=0;
        c3=0;
        c4=0;
        c5=0;
        while(!(st3[j]=="d"))
{
    x=0;
    while(!(st4[x]=="d"&&st5[x]=="d"&&st6[x]=="d"))
    {
            if((st3[j].compare(st4[x]))==0&&c1<2)
            {
                insertedgenode(3,4);
                c1++;}
                if((st3[j].compare(st5[x]))==0&&c2<2)
            {
                insertedgenode(3,5);
                c2++;}
                if((st3[j].compare(st6[x]))==0&&c3<2)
            {
                insertedgenode(3,6);
                c3++;}


        x++;
        }
        j++;
        }
        j=0;
        x=0;
        c1=0;
        c2=0;
        c3=0;
        c4=0;
        c5=0;
       while(!(st4[j]=="d"))
{
    x=0;
    while(!(st5[x]=="d"&&st6[x]=="d"))
    {
            if((st4[j].compare(st5[x]))==0&&c1<2)
            {
                insertedgenode(4,5);
                c1++;}
                if((st4[j].compare(st6[x]))==0&&c2<2)
            {
                insertedgenode(4,6);
                c2++;}


        x++;
        }
        j++;
        }
        j=0;
        x=0;
        c1=0;

       while(!(st5[j]=="d"))
{
    x=0;
    while(!(st6[x]=="d"))
    {
            if((st5[j].compare(st6[x]))==0&&c1<2)
            {
                insertedgenode(5,6);
                c1++;}

        x++;
        }
        j++;
        }
         vertlist(1,edgestart);
    vertlist(2,edgestart);
    vertlist(3,edgestart);
    vertlist(4,edgestart);
     vertlist(5,edgestart);
      vertlist(6,edgestart);
    //traverse(vrtstart);
   // cout<<"///////////\n";
    graphcoloring(vrtstart);


}
int main()
{
   /*int *p;
  insertedgenode(1,3);
 // insertedgenode(2,5);
  insertedgenode(1,2);
  //insertedgenode(2,5);
  insertedgenode(2,6);
  //insertedgenode(3,5);
  insertedgenode(6,4);
  insertedgenode(6,5);

/*p=getadjacent(1,edgestart);
for(int i=0;i<4;i++)
    cout<<p[i]<<"\n";
    vertlist(1,edgestart);
    vertlist(2,edgestart);
    vertlist(3,edgestart);
    vertlist(4,edgestart);
     vertlist(5,edgestart);
      vertlist(6,edgestart);
    //traverse(vrtstart);
    cout<<"///////////\n";
    graphcoloring(vrtstart);*/
    createdges();
    printcolors(vrtstart);
  /* for(int i=0;i<6;i++)
   cout<<colors[i]<<"\n";*/

}
