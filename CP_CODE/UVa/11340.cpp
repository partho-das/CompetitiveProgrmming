
#include<bits/stdc++.h>
using namespace std;

int main()
{

	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

    int t,v,n;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        char c[n];
        int b[n];
        for(int i=0;i<n;i++){
            cin>>c[i]>>b[i];
        }
        double sum=0;
        cin>>v;
        getline(cin,s);
        for(int j=0;j<v;j++){
        getline(cin,s);
            for(int k=0;k<s.size();k++){
                for(int l=0;l<n;l++){
                    if(s[k]==c[l]){
                        sum+=(double)b[l];
                    }
                }
            }
        }
       printf("%.2lf",sum/100.00);
       cout<<"$"<<endl;
    }

    #ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}

