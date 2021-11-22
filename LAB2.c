#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>

float func(float x)
{
    return sin(x);
}
float Left_rect(float a,float b, int n)
{
    float h;
    h=(b-a)/n;
    float sum=0;
    for(int i=0; i<=n-1; i++)
        {
        //sum+=h*func(a+i*h);
          sum+=h*func(a+i*h)+func(sqrt(1+a+i*h)+i);
        }
    return sum;
}

float Right_rect(float a,float b, int n)
{
    float h;
    h=(b-a)/n;
    float sum=0;
    for(int i=1; i<=n; i++)
        {
            sum+=h*func(a+i*h)+func(sqrt(1+a+i*h)+i);
        }
    return sum;
}

float Trapeze(float a,float b, int n)
{
    float h;
    h=(b-a)/n;
    float sum=func(a)+func(b);
    for(int i=1; i<=n; i++)
        {
            sum+=h*func(a)+func(sqrt(1+a)+i);
        }
        sum*= h/2;
    return sum;
}

float Sympson(float a,float b, int n)
{
    float h;
    h=(b-a)/n;
    float sum=func(a)+func(b);
    int k;
    for(int i=1; i<=n; i++)
        {
            k=2+2*(i%2);
            sum+=k*func(a*h)+func(sqrt(1+a*h)+i);
        }
        sum*= h/3;
    return sum;
}

void var1(float a, float b, float q, unsigned int n)
{
    unsigned int i=0;
    float riz;
    do
    {
     i+2;
        riz=fabs(Left_rect(a,b,i)-Left_rect(a,b,i+2));
    }while(riz>q);
    printf("%.6f %.6f %.6f %.6f %u \n",Left_rect(a,b,i), Left_rect(a,b,10), Left_rect(a,b,100), Left_rect(a,b,1000), i);

}

void var2(float a, float b, float q, unsigned int n)
{
    unsigned int i=0;
    float riz;
    do
    {
     i+2;
        riz=fabs(Right_rect(a,b,i)-Right_rect(a,b,i+2));
    }while(riz>q);
    printf("%.6f %.6f %.6f %.6f %u \n",Right_rect(a,b,i), Right_rect(a,b,10), Right_rect(a,b,100), Right_rect(a,b,1000), i);

}

void var3(float a, float b, float q, unsigned int n)
{
    unsigned int i=0;
    float riz;
    do
    {
     i+2;
        riz=fabs(Trapeze(a,b,i)-Trapeze(a,b,i+2));
    }while(riz<q);
    printf("%.6f %.6f %.6f %.6f %u \n",Trapeze(a,b,i), Trapeze(a,b,10), Trapeze(a,b,100), Trapeze(a,b,1000), i);

}

void var4(float a, float b, float q, unsigned int n)
{
    unsigned int i=0;
    float riz;
    do
    {
     i+2;
        riz=fabs(Sympson(a,b,i)-Sympson(a,b,i+2));
    }while(riz<q);
    printf("%.6f %.6f %.6f %.6f %u \n",Sympson(a,b,i), Sympson(a,b,10), Sympson(a,b,100), Sympson(a,b,1000), i);

}



int main(){
   float a,b,q;
   unsigned int n, variant;

   do{
    printf("Choise variant metod (1:Left_rect, 2:Right_rect, 3:Trapez, 4:Sympson) \n");
   scanf("%u",&variant);


   }while(variant>4 || variant<1);

   printf("1-Choise lover limit \n");
   scanf("%f",&a);
   printf("2-Choise upper limit \n");
   scanf("%f",&b);
   printf("3-Choise allowed error \n");
   scanf("%f",&q);

   printf("|N| --- |N=10| --- |N=100| --- |N=1000| --- |n|\n");
   printf("4-Choise number od points \n");
   scanf("%f",&n);

    if(variant==1) var1 (a,b,q,n);
    else if(variant==2) var2 (a,b,q,n);
    else if(variant==3) var3 (a,b,q,n);
    else if(variant==4) var4 (a,b,q,n);

return 0;
}
