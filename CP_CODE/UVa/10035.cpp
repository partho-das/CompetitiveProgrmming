
#include<bits/stdc++.h>
using namespace std;

int cnt;
string bigintAdd(string x, string y){
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    while(x.size() < y.size()) x.push_back('0');
	while(x.size() > y.size()) y.push_back('0');
    
    x.push_back('0');
    y.push_back('0');

    string sum;
    int carry = 0;
    cnt = 0;

    for(int i = 0; i < x.size(); i++){
    	if(carry>0)cnt++;
        carry += x[i]+y[i]-2*'0';
        sum.push_back(carry%10 + '0');
        carry /= 10;
    }
    if(carry>0)cnt++;
    while(carry) sum.push_back(carry%10 + '0'), carry /= 10;
    while(sum.size() > 1 && sum.back() == '0') sum.pop_back();
    reverse(sum.begin(), sum.end());
  
    return sum;
}


int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

    	string str,str2;


    	while(1)
    	{
    		cin >> str >> str2;
    		if(str[0] == '0' && str.size() == 1 && str2[0]=='0' && str2.size() == 1)
    			return 0;

    		bigintAdd(str,str2); 
    		
    		if(cnt>0)
    		{
    			if(cnt == 1)
    			{
    				printf("1 carry operation.\n");
    			}
    			else
    			printf("%d carry operations.\n",cnt );
    		}
    		
    		else
    		printf("No carry operation.\n");	

    	}
   



	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
