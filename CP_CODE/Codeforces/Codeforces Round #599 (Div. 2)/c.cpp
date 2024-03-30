// C++ Program to find largest prime 
// factor of number 
#include <iostream> 
#include<bits/stdc++.h> 
using namespace std; 
set<long long> prdiv;
// A function to find largest prime factor 
long long maxPrimeFactors(long long n) 
{ 
  prdiv.clear();
  // Initialize the maximum prime factor 
  // variable with the lowest one 
 

  // Print the number of 2s that divide n 
  // while (n % 2 == 0) { 
  //   maxPrime = 2; 
  //   n >>= 1; // equivalent to n /= 2 
  // } 

  // n must be odd at this point, thus skip 
  // the even numbers and iterate only for 
  // odd integers 
  long long last = sqrt(n);
  for (int i = 2; i <= sqrt(n); i++) { 
    while (n % i == 0) { 
      //maxPrime = i; 
      n = n / i; 
      //cout << i << endl;
     // cout << n << endl;
      prdiv.insert(i);
      //if(n!=1)
      //prdiv.insert(n);

      // if(prdiv.size() >= 2)

      //   // for(auto it : prdiv)
      //   //   cout << it <<" ";
      if(prdiv.size()>=2)
        return 0;
    } 
  }

  if(n>2)
     prdiv.insert(n);
    if(prdiv.size()>=2)
        return 0;



  // This condition is to handle the case 
  // when n is a prime number greater than 2 


      return 1;
} 

// Driver program to test above function 
int main() 
{ 


   #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
   #endif

  long long n;

while(cin >> n)
{

   // cout << maxPrimeFactors(n) << endl;; 
    if(maxPrimeFactors(n))
    {

      if(prdiv.empty())
      {
       // cout <<"HI" << endl;
        cout << n << endl;
      }
      else
      {

          n = *prdiv.begin(); 
          cout << n << endl;
      }
    }
    else cout << 1 << endl;

  }
return 0;
} 