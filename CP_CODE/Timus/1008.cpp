#include<stdio.h>
#include<math.h>


int arr[10][10];
void right(int *i,int *j,int value)
{
	int start = arr[*i][*j]+1,x;
	value += arr[*i][*j];  
	int mid = ( start + value)>>1;
	*j = *j + 1;
	--(*i);
	for(x = start ;x<=mid;x++)
		 arr[++(*i)][(*j)]  = x;
	for(x = mid+1;x<=value;x++)
		arr[(*i)][--(*j)] = x;
}
void down(int *i,int *j,int value)
{
	
	int start = arr[*i][*j]+1,x;
	value += arr[*i][*j];  
	int mid = ( start + value)>>1;

	*i = *i + 1;
	--(*j);
	for(x = start ;x<=mid;x++)
		 arr[*i][++(*j)]  = x;
	for(x = mid+1;x<=value;x++)
		arr[--(*i)][*j] = x;
}

void gen()
{
	int value = 1,n = 1,i = 1,j = 1;
       arr[i][j] = 1;
       int lst = 10; // size of the grid.
      	 while(n<lst)
      	 {
        	n++,value+=2;
	       	if(j==1)
	       		down(&i,&j,value);
	       	else if(i == 1)
       		right(&i,&j,value);
      	 }

      	 for(i = 1;i<=lst;i++)
       	{
       		for(j = 1;j<=lst;j++)
       		{
       			printf("%3d ", arr[i][j]);

       		}
       		puts("");
       	}
}


int main()
{

	 #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       //int start_time = clock();
  	#endif
	
	 //gen(); // generate the sequence;
       /// my main soln: http://www.lightoj.com/volume_showcode.php?sub_id=1644874

     int test,c = 1;
     scanf("%d",&test);
     for( c = 1;c<= test;c++)
     {
     	long long n,start,end,mid,midr,midc,colam,row;
     	scanf("%lld",&n);
     	double dbsqrtvalue = sqrt(n);
     	long long intsqrtvalue = sqrt(n);
     	if(dbsqrtvalue == intsqrtvalue) // if fully squre the
     	{
     		if(intsqrtvalue%2==0) row = 1,colam = intsqrtvalue;
     		else colam = 1,row = intsqrtvalue;
     	}
     	else
     	{
     		start = intsqrtvalue,end = intsqrtvalue + 1 ;
     		midr = midc = end,start*=start,end*=end;start++;
     		mid = (start+end)>>1;
     		if(end%2==0) // even then 
     			if(n <= mid) row = midr,colam = midc - (mid - n);
     			else colam = midc,row = midr - (n-mid);

     		else // if odd
     			if(n<=mid) colam = midc,row = midr - (mid - n);
     			else row = midr,colam = midc - (n - mid);
     	}
     	printf("Case %d: %lld %lld\n",c,colam,row);
     }


  return 0;
  }