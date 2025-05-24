#include <stdio.h>
int main()
{
    int n,alloc[20][20],max[20][20],avail[20],m;
    printf("Enter the number of Procsses: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    
    printf("Enter the Allocation Matrix: \n");
    for(int i =0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    
    printf("Enter the Max Matrix: \n");
    for(int i =0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    
    printf("Enter the Available Matrix: \n");
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }

    int finish[n] 
    ,safeSeq[n]  
    ,need[n][m]   
    ,work[m];     

    for(int i=0;i<m;i++)
    {
        work[i] = avail[i];
    }
    
    for(int i=0;i<n;i++)
    {
        finish[i] = 0;
    }

    
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    
    printf("The need matrix is : \n");
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
     int ind=0;

    
    for(int k =0;k<n;k++)
    {
        for(int i =0;i<n;i++)
        {
            if(finish[i]==0)
            {
                int flag=0;
                for(int j=0;j<m;j++)
                {
                    if(need[i][j]>work[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag==0)
                {
                    safeSeq[ind++]=i;

                    for(int k =0;k<m;k++)
                    {
                        work[k] += alloc[i][k];
                        finish[i] = 1;
                    }
                }
            }
        }
    }

    printf("The Safe Sequence is : ");
    for(int i =0;i<=n-1;i++)
    {
        printf("P%d -> ",safeSeq[i]);
    }
}