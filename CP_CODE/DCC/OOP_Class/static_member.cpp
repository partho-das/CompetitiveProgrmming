#include<bits/stdc++.h>

using namespace std;


class Item
{
    static int cnt;

    int code;
public:
    void get_date(int x)
    {
        code = x;
        cnt++;
    }

    void get_count()
    {
        cout << "Count    " << cnt << endl;
    }

};


int Item::cnt;

int main()
{

    Item a, b, c;


    a.get_date(10);
    a.get_count();

    a.get_date(10);
    a.get_count();

    a.get_date(10);
    a.get_count();





    return 0;
}
