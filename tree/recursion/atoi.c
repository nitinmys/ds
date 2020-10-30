#include<stdio.h>
#include <string.h>
int atoi(char *str,int result);
int main(int argc, char *argv[])
{
    int val;
    char str[20]; 
    strcpy(&str[0],argv[1]);
    val = atoi (str,0);
    printf ("atoi(%s) = %d\n",str,val);
}

int atoi (char *str,int result)
{
    char ch;
    int value;
    if (*str == '\0')
        return result;
    ch = str[0];
    value = (int) (ch - '0');
    return (atoi((char *)(++str), (result*10) + value));
}
