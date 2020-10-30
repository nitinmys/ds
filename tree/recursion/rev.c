#include<stdio.h>
void reverse(char *str)
{
    char *ptr;
     if (*str != '\0')
     {
         ptr = str + 1;
         reverse(ptr);
     }
     printf ("%c",*str);

}
int main ()
{
    char *mystr="ABCDEFGHIJH";
    printf("reverse of string:");
    reverse(mystr);
}


