#include<bits/stdc++.h>
using namespace std;



namespace My_code
{
class complex
{
    int real;
    int imag;
};
complex sqrt(complex);
// ...
int main();
}


int My_code::main()
{
    complex z {1,2};
    auto z2 = sqrt(z);

// ...
};
int main()
{
    cout << My_code::main() << endl;
    return 0;
}
