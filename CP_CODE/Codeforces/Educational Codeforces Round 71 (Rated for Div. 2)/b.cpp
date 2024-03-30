
#include<bits/stdc++.h>
using namespace std;



bool A[60][60],B[60][60];
int dirx[] = {0,0,1,1};
int diry[] = {0,1,0,1};


std::vector<pair <int ,int> > vec;



bool isval(int i,int j,int n,int m)
{
	
	if(i <= n && i>=1 && j>=1 && j<= m &&
	 A[i][j] == 1 && A[i][j+1] == 1 && A[i+1][j] == 1 && A[i+1][j+1] == 1   )
		return 1;


		else return 0;
}

int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

    	int n,m;
    	cin >> n >> m;


    	for(int i = 1;i<=n;i++)
    	{
    		for(int j = 1;j<=m;j++)
    		{
    			cin >> A[i][j];

    			//cout << A[i][j];
    		}
    		//cout << endl;
    	}

    	for(int i = 1;i<=n;i++)
    	{
    		for(int j = 1;j<=m;j++)
    		{


    			 int ck = isval(i,j,n,m);



    			 if(ck)
    			 {
    			 	vec.push_back({i,j});

    			 	for(int k = 0;k<4;k++)
					{
						int x = i + dirx[k] , y = j + diry[k];
						B[x][y]= A[x][y];
					}
    			 }
    			 // else
    			 // {
    			 // 	cout << i <<" " <<j << endl;
    			 // }
    		}
    	}


    	for(int i = 1;i<=n;i++)
    	{
    		for(int j = 1;j<=m;j++)
    		{

    			 if(A[i][j] == B[i][j])
    			 	continue;
    			 else
    			 {
    			 	printf("-1\n");
    			 	return 0;
    			 }

    			 //cout << B[i][j];
    			 	
    		}
    		//cout << endl;
    	}

    	cout << vec.size() << endl;

    	for(auto  it : vec )
    	{
    		cout << it.first << " " << it.second << endl;
    	}


   



	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
