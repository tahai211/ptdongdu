#include <stdio.h>
#include<stdlib.h>
#include <math.h>
int UCLN(int a,int m )
{
   if(m==0)
   {
       return a;
   }
   return UCLN(m,a%m);
}
int timT (int a,int b,int m)
{
    int x,z,t;
    z=m%a;
    int c = UCLN (z,b);
    if (UCLN(c,a)==1)
    {
        z=z/c;
        b=b/c;

            b = -1 * b;
            while (b < 0)
            {
                b = b + a;
            }
        if (b % z == 0)
        {
            t = b/z;
            return t;
        }
        else
        {
            for(int k = 1 ; k < z ; k++)
            {
                if((b+k*a) % z == 0)
                {
                    t = (b+k*a)/z;
                    return t;
                }
            }
        }
    }
}
int main()
{
    int a,b,m;
    printf("phuong trinh co dang ax = b (mod m)\n");
    printf("nhap a: ");
    scanf("%d",&a);
    printf("\nnhap b: ");
    scanf("%d",&b);
    printf("\nnhap m: ");
    scanf("%d",&m);
    if (UCLN(a,m)==1)
    {
        if(m <= 7)
        {
            if ( b % a == 0 )
            {
                int c=b/a;
                printf("nghiem cua phuong trinh la x = %d (mod %d)",c,m);
            }
            else
            {
                for(int i = 1 ; i < a ; i++)
                {
                    if((b+i*m) % a == 0)
                    {
                        int c = (b+i*m)/a;
                        printf("nghiem cua phuong trinh la x = %d (mod %d)",c,m);
                        break ;
                    }
                }
            }
        }
        else
        {
            if ( b % a == 0 )
            {
                int c=b/a;
                printf("nghiem cua phuong trinh la x = %d (mod %d)",c,m);
            }
            else
            {
                if(a>m)
                {
                    a = a%m;
        
                }
                if (b>m)
                {
                     a = b%m;
                }  
                int x = (b+m*timT(a,b,m))/a;
                printf("nghiem cua phuong trinh la x = %d (mod %d)",x,m);
            }
        }
    }
    else if (UCLN(a,m)>1)
    {
        int d = UCLN (a,m);
        int c;
        int a1=a/d;
        int b1=b/d;
        int m1=m/d;
        if ( b1 % a1 == 0 )
        {
            c=b1/a1;
            printf("nghiem cua phuong trinh la x = {");
            for (int i = 0; i<d; i++)
            { 
                printf("%d , ",c+m1*i);
            }
            printf("} (mod %d)",m);
        }
        else
        {
            if(a>m)
            {
                 a = a%m;
        
            }
            if (b>m)
            {
                 a = b%m;
            }  
            c=(b1+m1*timT(a1,b1,m1))/a1;
             printf("nghiem cua phuong trinh la x = {");
                    for (int i = 0; i<d; i++)
                    {
                        printf("%d , ",c+m1*i);
                    }
                    printf("} (mod %d)",m);
        }
    }
    else
    {
        printf("phuong trinh vo nghiem");
    }
    return 0;
}
