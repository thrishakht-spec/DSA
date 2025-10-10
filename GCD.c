#include <stdio.h>
#include <stdlib.h>
int GCD(int a,int b)
{
    if(a=0)
        return b;
    return GCD(b%a,a);
}
int main()
{
    int a,b;
    printf("\nRead values for a and b:\n");
    scanf("%d%d",&a,&b);
    printf("\nGCD of %d and %d is %d",a,b,GCD(a,b));
    return 0;
}
