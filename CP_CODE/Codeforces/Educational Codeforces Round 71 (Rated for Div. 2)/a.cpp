#include<bits/stdc++.h>
using namespace std;
int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif
    int i,j,k,l,m,n;
    cin>>n>>m;
    vector<pair<int,int> >vec;
    int ara[n+1][m+1],b[n+1][m+1];
    for(i=0; i<=n; i++)
        for(j=0; j<=m; j++)
            b[i][j]=0;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            cin>>ara[i][j];
    for(i=1; i<n; i++)
    {
        for(j=1; j<m; j++)
        {
            if(ara[i][j]==1 && ara[i][j+1]==1 && ara[i+1][j]==1 && ara[i+1][j+1]==1)
            {
                b[i][j]=b[i][j+1]=b[i+1][j]=b[i+1][j+1]=1;
                vec.push_back(make_pair(i,j));
            }
        }
    }
    for(i=1; i<n; i++)
    {
        for(j=1; j<m; j++)
        {
            if(ara[i][j]!=b[i][j])
            {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    cout<<vec.size()<<endl;
    for(i=0; i<vec.size(); i++)
    {
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }
    return 0;
}