# Labs
#include <stdio.h>
#define DIM 7
int main(void){
int i, j,tmp=1,length=0,index=0, array[DIM];



for (i=0; i<DIM; i++) {
        printf("Element [%d] ", i);
        scanf("%d", &array[i]);
    }
for(i=0;i<DIM;i++){
    j=i;
    tmp=1;
    while(array[j]<array[j+1]&&j<DIM-1){
        tmp++;
        j++;
        }
    if (length<tmp){
        length=tmp;
        index=i;
    }

}


for (i=index; i<index+length; i++) {
        printf("%d\t ", array[i]);

    }


return 0;

}





