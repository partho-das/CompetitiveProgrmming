
#include<bits/stdc++.h>
using namespace std;





int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

    std::vector<int> v;

    int bin[12];

    int value,cnt = 1,g = 0,b = 0,c = 0,fix = 1,sum = 0;
    while(scanf("%d",&value) != EOF)
    {
    	bin[cnt++] = value;

    	if(cnt == 10)
    	{
             std::vector<int> v;
            sum = bin[2]+bin[3] + bin[4]+bin[5] + bin[7]+bin[9];
            v.push_back(sum);
            sum = bin[2]+bin[3] + bin[4]+bin[6] + bin[7]+bin[8];
            v.push_back(sum);

            sum = bin[1]+bin[2] + bin[5]+bin[6] + bin[7]+bin[9];
            v.push_back(sum);
            sum = bin[1]+bin[2] + bin[4]+bin[6] + bin[8]+bin[9];
            v.push_back(sum);

            sum = bin[1]+bin[3] + bin[5]+bin[6] + bin[8]+bin[7];
            v.push_back(sum);
            sum = bin[1]+bin[3] + bin[5]+bin[4] + bin[8]+bin[9];
            v.push_back(sum);

            sum = v[5];
            fix = 5;
            for(int i = 5;i>=0;i--)
            {
                if(v[i]<=sum)
                {
                    sum = v[i];
                    fix = i;
                }

            }

            if(fix == 0)
            printf("BCG ");
            else if(fix == 1)
                printf("BGC ");
            else if(fix == 2)
                 printf("CBG ");
             else if(fix == 3)
                printf("CGB ");
            else if(fix == 4)
                printf("GBC ");
            else if(fix == 5)
                printf("GCB ");
            cout << sum << endl;



            // BCG
            // BGC

            // CBG
            // CGB

            // GBC
            // GCB          
 		     cnt = 1;
            
            
            }

    	}

    

   



	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;


}
