/*
 * Given a non-negative number N and two values L and R. The problem is to toggle the bits in the range L to R in the binary representation of N, i.e, to toggle bits from the rightmost Lth bit to the rightmost Rth bit. A toggle operation flips a bit 0 to 1 and a bit 1 to 0. Print N after the bits are toggled.



Example 1:

Input:
N = 17 , L = 2 , R = 3
Output:
23
Explanation:
(17)10 = (10001)2.  After toggling all
the bits from 2nd to 3rd position we get
(10111)2 = (23)10
*/
#include <stdio.h>
int toggle (int x, int l, int r)
{
    unsigned int num= 1UL;
    int i;
    for (i = 0; i <r-l; i++ )
    {
       num =  num  << 1 | 1UL;
    }
    num = num << l-1;
    printf ("%d\n",num);
    x = x ^ num;
    printf ("%d\n",x);
}

int swap_even_odd_bits (int num)
{
    int oddbits = num & 0x5555;
    int evenbits = num & 0xaaaa;
    oddbits <<=1;
    evenbits >>=1;
    return (evenbits | oddbits);
}

// reverse bits in even and odd places
int main()
{
    int x = 2;
    toggle (50,2,5);
    printf ("swap even odd for x = %d is %d\n",x, swap_even_odd_bits(x));
    return 0;
}
