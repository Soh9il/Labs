#include <stdio.h>
#include <stdlib.h>
#define R 3
#define C 3
int power_ten(int n);
int factorial(int n);
void print_matrix(int M[R][C]);

int main()
{
  int i,j,a=0;
  int M1[R][C];
  int M2[R][C];
  for(i=0;i<R;i++){
    for(j=0;j<C;j++){
        printf("index[%d,%d]:", i, j);
        scanf("%d", &M1[i][j]);
    }
  }
  for(i=0;i<R;i++){
    for(j=0;j<C;j++){
        if(M1[i][j]==0)
            M2[i][j]=0;
        if(M1[i][j]<0)
            M2[i][j]=factorial(-M1[i][j]);
        if(M1[i][j]>0){
            while(power_ten(a)<M1[i][j]){
                a++;
            }
            M2[i][j]=power_ten(a);
        }
    }
  }
  print_matrix(M1[R][C]);
  print_matrix(M2[R][C]);



  }



int power_ten(int n){
    int i,x=1;
    for(i=0;i<n;i++){
        x*=10;
        }
    return x;
}

int factorial(int n){
    int x=n-1;
    while(n>1){

       n=n*x;
       x--;
    }
    return n;
}

void print_matrix(int M[R][C]){
    int i,j;
    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            printf("%d\t",M[i][j]);
        }
        printf("\n");
  }
}
