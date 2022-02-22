#include<stdlib.h>
#include<stdio.h>

int main()
{
    int *p, *q;
    p = (int *)malloc(5*sizeof(int));
    for (int i = 0; i< 5; i++)
    {
        printf("\n Gia tri %d = ", i);
        scanf("%d", &p[i]);
    }
    int t;
    printf("Muon tang bao nhieu size \n");
    scanf("%d", &t);
    q = (int *)malloc((5+t)*sizeof(int));
    for (int i =0; i<5; i++) q[i]= p[i];
    free(p);
    q[5] = 69;
    for (int i = 0; i<=5; i++) 
        printf("%d ", q[i]);
    return 0;

}