#include<stdio.h>
int main()
{
    float a,b,c,d,x1,x2,x3,disc;
int i;
float expr;
clrscr();
printf("ax^3 + bx^2 + cx + d = 0\n Enter a,b,c,d : \n");
scanf("%f,%f,%f,%f",&a,&b,&c,&d);
i = 0;
while(i<abs(d))
{
expr = a*pow(i,3)+b*pow(i,2)+c*i+d;
if(expr==0)
{
x1=i;
break;
}
expr = a*pow(-i,3)+b*pow(-i,2)+c*(-i)+d;
if(expr==0)
{
x1=-i;
break;
}
i++;
}
printf("Root 1 = %f",x1);
b = b + (a*(x1));
c = c + (b*(x1));
disc = (b*b)-(4*a*c);
if(disc>=0)
{
x2 = (-b+sqrt(disc))/(2*a);
x3 = (-b-sqrt(disc))/(2*a);
printf("\nRoot 2 = %f\nRoot 3 = %f",x2,x3);
}
else
{
disc = ((4*a*c)-pow(b,2))/(2*a);
printf("\nRoot 2 : %f+%fi",((-b)/(2*a)),disc);
printf("\nRoot 3 : %f-%fi",((-b)/(2*a)),disc);
}
    return 0;
}
