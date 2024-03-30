#include<bits/stdc++.h>

using namespace std;

class Complex{

public:
double re,im;

public:
    Complex(double r,double i):re {r},im {i} {}
    Complex(double r): re {r},im {0} {}
    Complex() : re {0},im {0} {}

    double real() const {return re;}
    double imeg() const {return im;}

    void real(double r) {re = r;}
    void imag(double i) {im = i;}
    Complex& operator =(Complex z) { re = z.re,im = z.im;    return *this;}
    Complex& operator+=(Complex z) { re += z.re,im += z.im ; return *this;}
    Complex& operator-=(Complex z) { re -= z.re,im -= z.im ; return *this;}
    Complex& operator*=(Complex); //defined else were
    Complex& operator/=(Complex); //defined else were

    void print() {cout <<"(" << re << "," << im << ")" << endl; }

};

int main(){

    Complex z(5,8);
    Complex x(2,1);

   z = (x+=x);
   z.print();

   z = {5,4};

   z.print();


    return 0;
}
