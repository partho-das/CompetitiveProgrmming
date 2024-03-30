#include<bits/stdc++.h>

using namespace std;

class sample{
int a;
int b;


public:
    void set_value(){
        a = 20; b = 30;
    }
    friend float mean (sample s);

};


float mean(sample s){

    float m;
    m = (s.a + s.b) / 2;

    return m;
}


class xyz;
class abc
{
    int a;

public:
    void setValue(int i) { a = i;}

    friend void maximum(xyz, abc);
};

class xyz
{
    int a;

public:
    void setValue( int i ){ a = i;}

    friend void maximum(xyz, abc);


};


void maximum(xyz p ,abc q)
{
if(p.a > q.a) cout << " Max is = " << p.a << endl;
else cout << " Max is = " << q.a << endl;

return;
}
int main()
{

//    sample x;
//
//    x.set_value();
//
//    cout << "mean = " << mean(x) << endl;


    abc a1;
    a1.setValue(25);

    xyz x1;

    x1.setValue(28);


    maximum(x1, a1);
    return 0;
}
