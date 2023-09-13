#include <stdio.h>
#include <stdbool.h>
int check(char *s,char c)
{
    if(s[0] == c)
        return 1;
    return(0);
}
bool isAcronym(char **av, int n, char * s)
{
    int i = 0;
    while(i < n)
    {
        if(check(av[i],s[i]) == 0)
            return(false);
        i++;
    }
    return(true);
}

int main()
{
    char *A[3];
    A[0] = "alice";
    A[1] ="bob";
    A[2] = "charlie";
    printf("%d\n",isAcronym(A,3,"Kbc"));
}