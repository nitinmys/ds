//There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does matter).


#include <stdio.h>

int numsteps(int steps)
{
    if (steps == 1)
        return 1;
    
    if (steps == 2)
        return 2;
    
    return (numsteps(steps-1) + numsteps(steps-2));


}

int main ()
{
    int n,num;
    printf ("How may steps do you want to climb\n");
    scanf ("%d",&n);
    num = numsteps (n);
    printf ("Number of ways to climb %d steps = %d\n",n,num);
    return 0;
}
