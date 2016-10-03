#include <stdio.h>
#include <stdlib.h>

#define DIM 7
int main(void)
{
    int N1, N2,i,j,sum;
    scanf("%d", &N1);
    scanf("%d", &N2);

    int v1[DIM],v2[DIM];
    for(i=0;i<N1;i++){
        scanf("%d", &v1[i]);
    }
    for(i=0;i<N1;i++){
            sum=0;
            /* start from zero*/
            if(i-N2<=0){
                    /*finish at Dim*/
                    if(i+N2>=DIM){
                            for(j=0;j<DIM;j++){
                                v2[i]+=v1[j];
                                sum++;
                            }
                            v2[i]=v2[i]/sum;
                    }
                    /*finish at i+N2*/
                    else {
                            for(j=0;j<i+N2;j++){
                                v2[i]+=v1[j];
                                sum++;
                            }
                            v2[i]=v2[i]/sum;
                    }
            }
            /*start from i-N2*/
            else {
                    /*finish at Dim*/
                    if(i+N2>=DIM){
                            for(j=i-N2;j<DIM;j++){
                                v2[i]+=v1[j];
                                sum++;
                            }
                            v2[i]=v2[i]/sum;
                    }
                    /*finish at i+N2*/
                    else {
                            for(j=i-N2;j<i+N2;j++){
                                v2[i]+=v1[j];
                                sum++;
                            }
                            v2[i]=v2[i]/sum;
                    }
            }                                                                                                                                                                                                                                                                  )
    }

}
