
#include<bits/stdc++.h>
using namespace std;





int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif



    	int n,arr[100][100];


  		cin >> n;

  		for(int i = 0;i<n;i++)
  		{
  			for(int j = 0;j<n;j++)
  				{
  					cin >> arr[i][j];
  				}
  		}
  		int sum = 0,mx = -100000;

  		for(int i = 0;i<n;i++)
  		{
  			for(int j = 0;j<n;j++)
  			{
  				for(int k = i;k<n;k++)
  				{
  					for(int l = j;l<n;l++)
  					{

  						for(int x = i;x<=k;x++)
  						{
  							for(int y = j;y<=l;y++)
  							{
  								sum+=arr[x][y];
  								//printf("%3d",arr[x][y] );
  							}
  							
  							//cout << endl;

  						}
  						mx = max(mx,sum);
  							sum = 0;
  						//cout << endl;

  					}
  					//cout << endl;

  				}
  				//cout << endl;

  				

  			}
  			//cout << endl;
  		}

  		cout << mx << endl;


   



	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
