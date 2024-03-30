#include<bits/stdc++.h>
using namespace std;



int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif



    	string s;

    	cin >> s;
    	int ck = 0;
		int value = s.size();
		for(int i = 1;i<value;i++)
		{
			if(s[i] == '1')
				ck = 1;
		}
		value--;
		//cout << value << endl;
		int ex = value%2;	
		value  = value/2;
		//cout << value << endl;
		value++;

    		if(ck==1 || ex)
    		cout << value << endl;
    	else
				cout << value-1 << endl;   

		int main(return) 	

	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
