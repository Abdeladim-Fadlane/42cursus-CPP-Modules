#include<cstdio>
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int tarcker = 0;
    for( int i = 0 ;i < (int)(sizeof(arr) / sizeof(arr[0]));i-=-1)
    {
        if(arr[i] % 2 != 0)
        {
            int swap = arr[tarcker];
            arr[tarcker] = arr[i];
            arr[i] = swap;
            tarcker++;
        }
    }
    int i = 0;
    while(i <(int)(sizeof(arr) / sizeof(arr[0])))
    {
        printf("%d\n",arr[i]);
        i -= -1;
    }
}