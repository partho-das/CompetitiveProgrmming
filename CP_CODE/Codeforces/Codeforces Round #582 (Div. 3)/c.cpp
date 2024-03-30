
#include<bits/stdc++.h>
using namespace std;





int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

   
    	long long arr[20][20] =  {{0,0,0,0,0,0,0,0,0,0},{0,1,3,6,10,15,21,28,36,45,45},
    	{0,2,6,12,20,20,22,26,32,40,40},{0,3,9,18,20,25,33,34,38,45,45},
    	{0,4,12,14,20,20,24,32,34,40,40},{0,5,5,10,10,15,15,20,20,25,25},
    	{0,6,8,16,20,20,26,28,36,40,40},{0,7,11,12,20,25,27,36,42,45,45},
    	{0,8,14,18,20,20,28,34,38,40,40},{0,9,17,24,30,35,39,42,44,45,45},
    	{0,0,0,0,0,0,0,0,0,0}};


    	int q;

    	cin >> q;
    	while(q--)
    	{
    	long long n,m,sum = 0,l,ex,asol;


    	cin >> n >> m;

    	l = m%10;

    	
    	n = n/m;


    	ex = n%10;
    	asol = n/10;
    	
    	sum = (arr[l][ex]+ (asol*arr[l][10]));

    		cout << sum << endl;

    	}
    	

	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
