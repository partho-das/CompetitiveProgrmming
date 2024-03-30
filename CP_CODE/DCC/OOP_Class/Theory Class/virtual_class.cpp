#include<bits/stdc++.h>

using namespace std;


class A{
    public:
    void show(){
        cout << "hello In A" << endl;
    }
};

class B : public virtual A{
};
class C : public virtual A{
};

class D : public B, public C{
};

int main(){


D d;
d.show();

return 0;
}
