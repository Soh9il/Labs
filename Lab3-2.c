#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct coordinates{
    char vrt[4+1];
    float x;
    float y;
} coo;

typedef struct rectangle{
    char vrt[4+1];
    float perimeter;
    float area;
}RCT;


float perimeter(float x1, float x2,float y1, float y2);
float area(float x1, float x2,float y1, float y2);

int main(int argc, char * argv[])
{
    FILE *f1;
    FILE *f2;
    FILE *f3;
    int n,i=0,j=0,k=0;
    coo *data;

    f1=fopen("fileIn.txt", "r");
    f2=fopen("fileArea.txt","w");
    f3=fopen("filePerimeter.txt","w");

    fscanf(f1,"%d", &n);
    data=malloc(sizeof(coo)*n);
    while(fscanf(f1,"%s%f%f", data[i].vrt, &data[i].x,&data[i].y)!=EOF){
        i++;
    }
    i=0;
    int flag[10]={0};
    RCT * rct ;
    rct=malloc(sizeof(RCT)*(n/2));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if (strcmp(data[i].vrt,data[j].vrt)==0 && i!=j && flag[i]!=1 && flag[j]!=1 ){
                strcpy(rct[k].vrt,data[i].vrt);
                rct[k].area=area(data[i].x, data[j].x, data[i].y, data[j].y);
                rct[k].perimeter=perimeter(data[i].x, data[j].x, data[i].y, data[j].y);
                printf("%.2f perimeter    %.2f area\n", rct[k].perimeter, rct[k].area);
                k++;
                flag[i]=1;
            }
        }
    }
    RCT tmp;
    for(i=0;i<n/2-1;i++){
        if (rct[i].perimeter<rct[i+1].perimeter){

            strcpy(tmp.vrt,rct[i].vrt);
            tmp.perimeter=rct[i].perimeter;
            tmp.area=rct[i].area;

            strcpy(rct[i].vrt,rct[i+1].vrt);
            rct[i].perimeter=rct[i+1].perimeter;
            rct[i].area=rct[i+1].area;

            strcpy(rct[i+1].vrt,tmp.vrt);
            rct[i+1].perimeter=tmp.perimeter;
            rct[i+1].area=tmp.area;

            i=0;
        }
    }

    for(i=0;i<n/2;i++){
        fprintf(f3,"%s\n",rct[i].vrt);
    }

    for(i=0;i<n/2-1;i++){
        if (rct[i].area<rct[i+1].area){

            strcpy(tmp.vrt,rct[i].vrt);
            tmp.perimeter=rct[i].perimeter;
            tmp.area=rct[i].area;

            strcpy(rct[i].vrt,rct[i+1].vrt);
            rct[i].perimeter=rct[i+1].perimeter;
            rct[i].area=rct[i+1].area;

            strcpy(rct[i+1].vrt,tmp.vrt);
            rct[i+1].perimeter=tmp.perimeter;
            rct[i+1].area=tmp.area;

            i=0;
        }
    }

    for(i=0;i<n/2;i++){
        fprintf(f2,"%s\n",rct[i].vrt);
    }

}

float area(float x1, float x2,float y1, float y2){
    float tmp;
    tmp=(x2-x1)*(y2-y1);
    if (tmp<0)
        tmp=tmp*-1;
    return tmp;
}

float perimeter(float x1, float x2,float y1, float y2){
    float tmp1,tmp2;
    tmp1=(x2-x1)*2;
    tmp2=(y2-y1)*2;
    if (tmp1<0)
        tmp1=tmp1*-1;
    if (tmp2<0)
        tmp2=tmp2*-1;

    return tmp1+tmp2;
}
