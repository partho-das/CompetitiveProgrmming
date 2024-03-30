#include<bits/stdc++.h>
using namespace std;

const long long maxn = 1e5+7;
const long long MOD = 1e9+7;
int n;
int print[20] = {0 ,4, 3, 7, 8, 1, 9, 5, 12, 13, 29, 27};
char  indx[20] = "sos";
bool take[20];

void subset(int current)
{

	for(int i = 1;i<=n;i++)
	{
		if(take[i])
			cout <<i << " ";
	}
	cout << endl;
	for(int i = current;i<=n;i++)
	{
		if(!take[i])
		{
			take[i] = 1;
			subset(i);
			take[i] = 0;

		}
	}
}

bool sub[100];
void div(int current)
{


	if(current>n)
	{
		cout << "{ ";
		for(int i = 1;i<=n;i++)
		{
			if(sub[i])
			{
				cout << i << " ";
			}
		}
		cout << "}"<< endl;
		return;

	}

	sub[current] = 1;
	div(current+1);
	sub[current] = 0;
	div(current+1);


}




int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

    	memset(take,0,sizeof take);
    	n = 4;


    	subset(1);
    	//cout << endl;
    	///div(1);
    	cout << "hi" << endl;






	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
// 123
// 12
// 13
// 23
// 1
// 2
// 3

