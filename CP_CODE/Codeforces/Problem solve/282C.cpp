#include<bits/stdc++.h>
using namespace std;

char str[1000006],str2[1000009];
int main()
{
   	 //freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
   	 //freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
 
    
   	gets(str);
   	gets(str2);
    int aln = strlen(str);
    int bln = strlen(str2);
 
  	if(aln != bln)
  	{
  		cout << "NO" <<endl;
  		return 0;
  	}
 	int ck = 0,oneckf = 0,onecks = 0;
  	for(int i = 0;i<aln;i++)
  	{
  		if(str[i] == '1')
  			oneckf = 1;
  		if(str2[i] == '1')
  			onecks = 1; 

  		if(oneckf && onecks)
  			break;

  	}


  	if(onecks == oneckf)
  	printf("YES\n");
  else
  	puts("NO");
 
    return 0;
}