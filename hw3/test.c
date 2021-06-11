#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *itostr(int num)
{
    char *str = (char *)calloc(4, sizeof(char));
    int tmp = num, div = 1000, top = -1;
    while(tmp)
    {
        if(top > -1 || tmp / div)
        {
            int cur = tmp/div;
            str[++top] = cur + 48;
            tmp -= tmp / div * div;
        }
        div /= 10;
    }
    return str;
}

char *ftostr(float fnum)
{
    char *str = (char *)calloc(10, sizeof(char));
    int integer = fnum;
    char *istr = itostr(integer);
    strcpy(str, istr);
    strcat(str, ".");
    float remain = 10 * (fnum - integer);
    int rem = remain, top = strlen(str) - 1;
    //do { }while(remain > 0);
    for(int i = 0; i < 2; i++)
    {
        str[++top] = rem + 48;
        remain -= rem;
        remain *= 10;
        rem = remain;
    }

    return str;
}

int main()
{
    printf("%s\n", ftostr(3.0));
}
