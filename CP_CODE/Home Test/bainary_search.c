#include<stdio.h>

int main()
{
    int n;
    printf("How many number do you have in your set : ");
    scanf("%d",&n);
    int a[n],in = 0;
    printf("Please give all your number set by increasing order\n");
    while(in < n) scanf("%d",&a[in++]);

    int lo = 0, hi = n-1, mid,key;
    printf("Which number you want to search : ");
     scanf("%d",&key);
    while(lo <= hi){
        mid = (lo+hi) >> 1; /// (lo+hi)/2
        if(a[mid] == key){
            printf("Found at %d :)\n",mid+1);
            return 0;
        }
        else if(a[mid] > key) hi = mid-1;
        else lo = mid+1;
    }
    puts("Not found :(");

    return 0;
}
