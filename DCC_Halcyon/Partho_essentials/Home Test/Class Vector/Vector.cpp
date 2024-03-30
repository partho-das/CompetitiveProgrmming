#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Vector
{

public:
//    Vector(std::initializer_list<T> lst) :elem{new T[lst.size()]}, sz{lst.size()}
//    {
//        copy(lst.begin(),lst.end(),elem);   // constr uct a Vector
//    }
    Vector(int s);
//    Vector(const Vector& a); // copy constr uctor
//    Vector& operator=(const Vector& a); // copy assignment


//    Vector(Vector&& a); // move constr uctor
//    Vector& operator=(Vector&& a); // move assignment
    T& operator[](int i); // element access: subscripting
    int size() const
    {
        return sz;
    }

    T& begin(Vector<T>& x)
    {
        return &x[0]; // pointer to first element
    }
    T& end(Vector<T>& x)
    {
        return x.begin()+x.size(); // pointer to one-past-last element
    }

    ~Vector()
    {
        delete[] elem;
    }
private:
    T* elem; // pointer to the elements
    int sz; // the number of elements
};


//Vector::Vector(Vector&& a)
//:elem{a.elem}, // "grab the elements" from a
//sz{a.sz}
//{
//a.elem = nullptr; // now a has no elements
//a.sz = 0;
//}
template<typename T>
Vector<T>::Vector(int s)
{
    elem = new T[s];
    sz = s;
}
template<typename T> T& Vector<T>::operator[](int i)
{
    if(i < 0 || size() <= i)
        throw out_of_range("out of range");
    return elem[i];
}


//
//void f(Vector &v)
//{
//    try
//    {
//        v[-1] = 7; /// try access beyond the vector capacity.
//
//    }
//    catch(out_of_range)
//    {
//        printf("%d\n",v.size());
//        printf("haha");
//
//    }
//    catch(length_error)
//    {
//
//        printf("negative length\n");
//    }
//    catch(std::bad_alloc)
//    {
//        printf("you are a bad programmer\n");
//    }
//}

//void decl()
//{
//        try
//        {
//            Vector v(-27);
//            cout << v.size() << endl;
//        }
//        catch (std::length_error)
//        {
//// handle negative size
//        }
//        catch (std::bad_alloc)
//        {
//// handle memory exhaustion
//        }
//
//}
constexpr double c = 299792.458;
void tst( int speed)
{
    constexpr double local_max = 14;

    static_assert(c>local_max,"what are you");

    return;
}

class Container
{

public:
    virtual double& operator[](int) = 0; // pure virtual function
    virtual int size() const = 0; // const member function (§3.2.1.1)
    virtual ~Container( ) {}
};

class list_container : public Container   // list_container implements Container
{
    std::list<double> ld; // (standard-librar y) list of doubles (§4.4.2)
public:
    list_container() { } // empty List
    list_container(initializer_list<double> il) : ld{il} { }
    ~list_container() {}

    double& operator[](int i);
    int size() const
    {
        return ld.size();
    }
};

double& list_container::operator[](int i)
{
    cout << "out i = " << i << endl;
    for (auto& x : ld)
    {
        cout << "out i = " << i << endl;
        if (i==0)
            return x;
        --i;
    }
    throw out_of_range("List container");
}


//class vector_container:pubic Container{/// Vector_container implements Container
//    Vector v;
//public:
////     vector_container(int s) :v(s) {}
//    ~vector_container() {}
//
//    double& operator[](int i) { return v[i]; }
//    int size() const{return v.size();}
//};

void use(Container& c)
{
    const int sz = c.size();

    for(int i = 0; i<sz; i++)
    {
        cout << c[i] << endl;

    }
}
void g()
{

    // vector_container vc{2,4,3,4,3,32,54,5,546,5};
    //use(vc);

}

void h()
{

    list_container lc{2,3,3434,45,5};
    use(lc);

}

template<typename container,typename value>
value sum(const container &c,value v)
{
    for(auto x : c)
    {
        v += x;
    }
    return v;
}

template<typename T>
class less_then
{
    const T val; /// value to compare against
public:
    less_then(const T &v) :val(v) {}
    bool operator()(const T& x) const
    {
        return x<val;    /// call operator
    }
};


template<typename C, typename P>
int count(const C& c, P pred)
{
    int cnt = 0;
    for ( auto& x : c)
        if (pred(x))
            ++cnt;
    return cnt;
}


void f(const Vector<int>& vec, const list<string>& lst, int x, const string& s)
{
    cout << "number of values less than " << x
         << ": " << count(vec,[&](int a)
    {
        return a<x;
    })
            << '\n';
    cout << "number of values less than " << s
         << ": " << count(lst,[&](const string& a)
    {
        return a<s;
    })
            << '\n';
}


int main()
{

#ifdef PARTHO
    freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    int start_time = clock();
#endif

    Vector <int> v{5};

    list<string> lst{"HI","there"};
    string str = "GOOD";
    f(v,lst,4,str);

    return 0;
}

