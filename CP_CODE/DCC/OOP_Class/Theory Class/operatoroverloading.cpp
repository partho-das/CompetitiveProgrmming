#include<bits/stdc++.h>


class item{

int x;


public:

item(){ x = 0;}
item (int a)
{
    x = a;
}

void getdata(){
    scanf("%d", &x);
}
void show_data(){
    printf("%d", x);
}

item operator +(item b)
{
    item temp;

    temp.x = x + b.x;
    return temp;
}

item operator +(int b)
{
    item temp;
    temp.x = x + b;
    return temp;
}

friend item operator +(int m, item a)
{
    item temp;
    temp.x = m + a.x;

    return temp;
}

item operator -()
{
    item temp;
    temp.x = -x;
    return temp;
}




};

int main()
{

    item a, b, c;

    c = a + b;

    c.show_data();


    return 0;
}
