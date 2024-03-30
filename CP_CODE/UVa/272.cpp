#include<bits/stdc++.h>


using namespace std;


int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif
	char str;


	int ck = 0;
	while(scanf("%c",&str) !=EOF)
	{
		if(str == '"' && !ck)
		{
			ck = 1;

			printf("``");

		}
		else if(str == '"' && ck )
		{
			ck = 0;
			printf("''");
		}
		else printf("%c",str);
		
	}

	return 0;
}