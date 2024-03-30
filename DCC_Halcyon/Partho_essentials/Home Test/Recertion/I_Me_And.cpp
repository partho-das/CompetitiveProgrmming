#include <bits/stdc++.h>
using namespace std;

//macros
#define PI  2*acos(0.0)
#define ll  long long
#define pf  printf
#define sc  scanf
#define ff  first
#define ss  second
#define mp  make_pair
#define pb  push_back
#define vi  std::vector<int>
#define pi  pair<int , int>
#define vll vector<long long>
#define pll pair<long long , long long>
#define FOR(i,a,n)    for(int i = a; i < n; i++)
#define TEST(test)  for(int c = 1; c <= test; c++)

void print(int n,int pos,int *arr) // print an array arr[0] arr[n-1]
{
  if(pos > n)
    return;
  cout << arr[pos] << " " << arr[n] << endl;
  print(n-1,pos+1,arr);
  return;

}
 
int rodd(int i,int j,int n,int *arr) /// reomve odd number from an array.
{
    if(i>= n)
    return j;
  if(arr[i] % 2 == 0) arr[j++] = arr[i];
   return rodd(i+1,j,n,arr);
}

void poly(int n,int pos) // pollynomial 1 + x + x^2 + x^3 + x^4 + x^5 + x^6
{ 
  if(pos>=n)
    return;
  if(pos==0)
    printf("1");
  else if(pos==1)
    printf(" + x");
  else printf(" + x^%d",pos);
  poly(n,pos+1);
}

int polycal(int n,int power,int agent,int x) // calcutate pollynomial 
{
    if(power>= n)
      return 0;
      return agent + polycal(n,power+1,agent*x,x);
}

int fact(int n) // calculate factorial
{
    cout << n << endl << endl;
    if(n<=0)
      return 1;
    return n*fact(n-1);
}
int fibo(int n) // calculate fibonacchi
{
  if( n <= 2 ) return 1;
  return fibo(n-1)+fibo(n-2);
}

bool primeck(int n,int pos){
  if(pos>=n) return 0;
  if(n%pos) return 1;
 return primeck(n,pos+1);
}
int gcd(ll a,ll b)
{
    if(a==0) return b;
    return gcd(b%a,a);
}

ll lcm(ll a,ll b)
{
  return a*b/gcd(a,b);
}

ll rlcm(ll a,ll b,ll cnt)
{
  if( (a*cnt)%b == 0 )
    return cnt*a;
  return rlcm(a,b,cnt+1);
}
void rmax(int *arr,int n,int pos){

  if(pos >= n ) return;
  if(arr[pos] >=  arr[n]) arr[n+1] = arr[n],arr[n] = arr[pos];
  else if(arr[pos] >= arr[n+1]) arr[n+1] = arr[pos];
  return rmax(arr,n,pos+1);
}

int lenearsearch(int *arr,int n,int pos,int value)
{
    if(pos>=n || value == arr[pos]) return pos;
   return lenearsearch(arr,n,pos+1,value);
}

int binarysearch(int low,int high,int *arr,int value)
{
  if(low>high) return -1;
  int mid = (low+high) >> 1;
       if(arr[mid]<value) return binarysearch(mid+1,high,arr,value);
  else if(arr[mid]>value) return binarysearch(low,mid-1,arr,value);
  return mid; // if arr[mid] not > value or arr[mid] not < value then arr[mid] == value, thats why i returnd mid.
}

int reviersedigit(int n,int c)
{
  if(n==0) return c;
  c  = c*10 + n%10;
  return reviersedigit(n/10,c);
}

void reversestring()
{
  int ch;
  if(sc("%c",&ch) == 1){ reversestring(); printf("%c",ch); }
  return;
}
string filter(string &str)
{ 
  string cpystr;
  FOR(i,0,str.size())
  if( (str[i] >= 'a' && str[i] <= 'z') ||
      (str[i] >= 'A' && str[i] <= 'Z') || 
      (str[i] >= '0' && str[i] <= '9')) cpystr.pb(str[i]);
    return cpystr;
}

bool ckpalindrome(string &str,int i,int j)
{
    if(i>j) return 1;
    if(str[i] == str[j]) return ckpalindrome(str,i+1,j-1);
    return 0;
}


void inordered(int n)
{
  if(n>2)
  inordered(n-2);
  printf("%d ",n);
  if(n>2)
  inordered(n-1);
  return;
}

void postorder(int n)
{
  if(n>2)
    postorder(n-2);
  if(n>2)
    postorder(n-1);
  printf("%d ",n);
}

void preorder(int n)
{
  printf("%d ",n);
  if(n>2)
    preorder(n-2);

  if(n>2)
    preorder(n-1);
}

int cnt = 0;
void tower(int n, char s, char m, char d)
{
  cout << n <<" "<< s << " " << m << " " << d << endl;
  cnt++;
    if(n>0)
    {
        // first move n-1 disks from source to middle,
        // using destination as middle pillar
        tower(n-1, s, d, m);
        // the only left nth disk can be moved directly from source to destination
        printf("%c -> %c\n", s, d);
        cout << n << endl;
        // on first step we've sent n-1 disks to the middle,
        // and now, from the middle pillar, we'll transfer them back to destination
        // using the source as the middle pillar
        tower(n-1, m, s, d);
    }
}




int main(){

   #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
   #endif

    int n;
    cin >> n;


    tower(n, 'a', 'b', 'c');
    cout << cnt << endl;
      
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}


///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
