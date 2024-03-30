#include<iostream>
#include<queue>
#include <cstring>

using namespace std;
 int n,m,c = 0;
 char str[200][200];
bool visit[200][200];
void input()
{
    for(int i = 0;i<n;i++)
    {
        cin >> str[i];
    }
    for(int i = 0;i<n;i++)
        cout << str[i] << endl;
}
bool isvalid(int x,int y)
{
    if(x>=0 && y>=0 && x<n && y<m && !visit[x][y] && str[x][y] == 'W' )
        return true;
    else return false;
}


int dirx[] = {0,0,-1,1  ,1,-1,-1,1};
int diry[] = {-1,1,0,0  ,1,-1,1,-1};


int chk(int x,int y)
{
	c = 0;
	int   i = x,j = y+1,ck[4] = {0,0,0,0};
	while(str[i][j] == '*' &&  j < m )
	{
		str[i][j] = '.';
		j++;
		ck[0] = 1;
		c = 1;

	}

	i = x,j = y-1;

	while(str[i][j] == '*' && j >= 0)
	{
		str[i][j] = '.';
		j++;
		ck[1] = 1;
		c = 1;
	}
	i = x+1,j = y;

	while(str[i][j] == '*' && i < n)
	{
		str[i][j] = '.';
		i++;
		ck[2] = 1;
	}
	i = x - 1 ,j = y;

	while(str[i][j] == '*' && i >= 0)
	{
		str[i][j] = '.';
		i++;
		ck[3] = 1;
		c = 1;
	}

	if(ck[0] && ck[1] && ck[2] && ck[3])
	{
		return 1;
	}
	else return 0;
}


int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	
    #endif
   cin >> n >> m;
   input();

   int cnt = 0;
   int x,y;

  int ck = n&1,ck2 = m&1;
 
  x = n/2;
  y = m/2;

  if(ck && ck2)
  {
  	 if(chk(x+1,y+1))
  	 {
  	 	puts("YES");
  	 }
  	 else puts("NO");

  }
  else if(ck && !ck2)
  {
  	if(chk(x+1,y))
  	{
  		if(chk(x+1,y+1 )|| c == 1)
  		{
  			puts("NO");
  		}
  		else puts("YES");
  	}
  	else if(chk(x+1,y+1))
  		{
  			puts("YES");
  		}
  		else  puts("NO");

  
  }
 else if(!ck && ck2)
  {
  	if(chk(x,y+1))
  	{
  		if(chk(x+1,y+1)|| c == 1)
  		{
  			puts("NO");
  		}
  		else puts("YES");
  	}
  	else 
  	{
  		if(chk(x+1,y+1))
  		{
  			puts("YES");
  		}
  		else  puts("NO");

  	}
  
  }
  else if(!ck && !ck2)
  {

  	if(chk(x,y))
  	{
  		if(chk(x+1,y+1) || c == 1 || chk(x,y+1) || c == 1 ||chk(x+1,y) || c == 1)
  		{
  			puts("NO");
  		}
  		else puts("YES");
  	}
  	else if(chk(x+1,y+1) )
  	{
  		if( chk(x,y) || c == 1 || chk(x,y+1) || c == 1 ||chk(x+1,y) || c == 1)
  		{
  			puts("NO");
  		}
  		else puts("YES");
  	}
  	else if(chk(x,y+1))
  	{
  		if( chk(x,y) || c == 1 || chk(x+1,y+1) || c == 1 ||chk(x+1,y) || c == 1)
  		{
  			puts("NO");
  		}
  		else puts("YES");

  	}
  	else if (chk(x+1,y) )
  	{
  		if( chk(x,y) || c == 1 || chk(x+1,y+1) || c == 1 || chk(x,y+1) || c == 1 )
  		{
  			puts("NO");
  		}
  		else puts("YES");

  	}

  }

  

    return 0;
}