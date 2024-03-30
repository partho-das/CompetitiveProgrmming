#include<bits/stdc++.h>
 
using namespace std;
 
 
 
int arr[200200];


int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif
    	
 	int n = 1;
 	cin >> n;
 	// while(n<1000)
 	// {
 	// 	memset(arr,0,sizeof arr);
 	// 	cout << "N = " << n << endl;
 		int l = 1,u = n*2;

 	int now = 1,p = 1;
 
 	for(int i = 1;i<=n*2;i+=2)
 	{
 		p = p%(2*n);
			if(p==0)
 			p = n*2;
 		//cout << p <<" " <<now << endl;

 		if(!arr[p])
 		{

	 		arr[p] = now;
			now++;

	 		p += n;
 		}
 		else 
 		{
 			cout <<"NO0" << endl;
 			return 0;
 		}
 		
 		p = p%(2*n);

 		if(p==0)
 			p = n*2;

 		//cout << p <<" " <<now << endl;
 		if(!arr[p])
 		{

 			arr[p] = now;

 			p++;
 			now++;
 		}
 		else 
 		{
 			cout <<"NO0" << endl;
 			return 0;
 		}


 	
 	}


 // 	std::vector<int> v;

 // 		int ck = 0,value = 0,value2 = 0 ;
 // 		int cnt  = 0;
 // 	for(int i = 1;i<=2*n;i++)
 // 		{

 // 			//cout << i << endl;
 			
 // 				int x ;
 // 				for(int j = 0;j<n;j++)
 // 				{
 // 					cnt ++;
 // 					x = i+j;

	//  					if(x> 2*n )
	//  				{
	//  					x = x-2*n;
	//  				}
	//  				value +=arr[x];
 // 				}
 // 				//cout << i <<" " <<value << endl; 
 // 				v.push_back(value);
 // 				value = 0;
 // 		}
 // // 		//cout << cnt << endl;
	// // #ifdef PARTHO
	// // 	int end_time = clock();
	// // 	printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
 // //    #endif

 // 		sort(v.begin(), v.end());


 // 		int x = v[0],y = v[v.size()-1];

 		if(n&1)
 		{
		 		cout <<"YES" << endl;
		 	for(int i = 1;i<=2*n;i++)
		 	{
		 		cout << arr[i] <<" ";
		 	}
		 	cout << endl;
 		}
 		else
 		cout << "NO" << endl;
 	
 	n++;

 	//}

 	

    	

       
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
  
 
    return 0;
 
}