#include<bits/stdc++.h>

using namespace std;



bool ckbit(int n,int pos)
{
    return (n&1<<pos);
}

void bin(int n)
{
    for(int i = (log2(n));i>=0;i--)
    {
        cout <<ckbit(n,i);
    }
}

int setbeat(int n,int pos)
{
    return (n|1<<pos);
}

// int And(int a,int b)
// {
//     return a&b;
// }
// int Or(int a,int b)
// {
//     return a|b;
// }
// int XOR(int a,int b)

// {
//   return a^b;
// }


// int main()
// {
    
//     freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
//     freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);

//     // int n;

//     // cin >> n;
//     // bin(n);
//     int a, b;
//     cin >> a >> b;

//     bin(a);
//     puts("");
//     bin(b);
//     puts("");

//     // int value  = And(a,b);
//    // cout<<"AND"<<endl<<value<<endl;

//    // value = Or(a,b);
//    // cout << "OR" << endl << value << endl;
//    // value = XOR(a,b);
//    // cout << "XOR" << endl << value << endl;





//    // // int value = setbeat(n,pos);
//     int value = XOR(a,b);
//     bin(value);
//     puts("");
//    cout << "XOR" << endl << value << endl;
   


//    printf("%lf\n",900719925474099.254);
//    printf("%f\n",9099.254);
//    printf("%d\n",sizeof(float));

//    // cout << (2 and 9) << endl;

//     return 0;
// }

 
#include<stdio.h>

int main()
{
  freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
  freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
  int t;
  unsigned long long i, a, b, c;
 

 for(int i = 1;i<=1000000;i++)
  cout << i << endl;

  return 0;
}


