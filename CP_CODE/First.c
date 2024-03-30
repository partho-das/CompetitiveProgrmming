#include <bits/stdc++.h>
using namespace std;
std::vector<vector<bool>> resut;
std::vector<bool> v(5);
void gen(int pos,int cnt)
{
	if(pos>=5)
	{
		if(cnt==3)
			resut.push_back(v);
		return;
	}
	if(cnt<=3)
	{
		v[pos] = 1;
		gen(pos+1,cnt+1);
	}
	v[pos] = 0;
	gen(pos+1,cnt);
}

int Diff(std::vector<bool> x, std::vector<bool> y){
	int cnt = 0;
	for(int i = 0; i < 5; i++) cnt += x[i] != y[i];
	return cnt;
}

int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    #endif
    	
   

 	gen(0,0); 

 	for(auto it : resut)
 	{
 		for(auto it2 : resut)
 		{
 			cout << (Diff(it,it2) & 1) << endl;
 		}
 	}


 	char str[maxn][maxn];


void input(int n,int m)
{
	for(int i = 0;i<n;i++)
	{
		 getchar();

		for(int j = 0;j<m;j++)
		{
			str[i][j] = getchar();
		}
	
	}


	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			cout << str[i][j];
		}
		puts("");
	}
}

pair<int , int > now , s,dis; 
void bfs(char x,char y)
{


}
    

	#ifdef PARTHO
		int end_time = clock();
		//printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
