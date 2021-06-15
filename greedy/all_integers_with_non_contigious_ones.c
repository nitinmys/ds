#include <stdio.h>
#include <stdlib.h>

find_all_non_cont(int number, int length, int index, int * result)
{
    int odd_bits = number & 0x5555;
    int even_bits =  number & 0xaaaa;
    odd_bits <<= 1;
    int tmp;
    if (index == length)
        return;
    
    if (!(odd_bits & even_bits))
    {
        *result = *result + 1;
         printf ("%d\n",number);
        return 0;
    }

    find_all_non_cont ( number , length, index, result);
    index++;
    tmp = 1 << index;
    number |= tmp;
    find_all_non_cont ( number , length, index, result);
}


     



int main ()
{
    int num = 1, length, result = 0;
    int index = 1;
    printf ("Provide the length of the number\n");
    scanf("%d",&length);
    find_all_non_cont(num, length, 1, &result); 
    printf (" Numbers of integers with non contigious 1's of length %d = %d\n",length, result); 
    return 0;
}
