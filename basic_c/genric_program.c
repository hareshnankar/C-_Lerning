#include <stdio.h>
#include <string.h>
char name[7] = "HARESH";
int arry[10]={1,2,3,4,5,6,7,8,9,10};

reverse_string(char *ptr)
{
    int len = strlen(ptr);
    int j = len-1;
    for(int i = 0; i<len/2;i++)
    {
        char tmp = ptr[j];
        ptr[j] = ptr[i];
        ptr[i] = tmp;
        j--;
    }

    printf("%s",ptr);
}

dessending_order(int *prt)
{
    for(int i= 0;i<=9;i++)
    {
        for(int j=i+1;j<=9;j++)
        {
            if(prt[j] > prt[i])
            {
                int tmp = prt[j];
                prt[j] = prt[i];
                prt[i] = tmp;
            }
        }
    }
}

assending_order(int *ptr)
{
    for(int i= 0;i<=9;i++)
    {
        for(int j=i+1;j<=9;j++)
        {
            if(ptr[j] < ptr[i])
            {
                int tmp = ptr[j];
                ptr[j] = ptr[i];
                ptr[i] = tmp;
            }
        }
    }

}

int main()
{
//  dessending_order(arry);
// for(int i= 0;i<=9;i++)
// {
//     printf("%d\n",arry[i]);
// }
// printf(".................\n");
// assending_order(arry);

// for(int i= 0;i<=9;i++)
// {
//     printf("%d\n",arry[i]);
// }
reverse_string(name);

}