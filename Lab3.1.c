#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef word{
    char *word;
    int count;
}INFO;

int main()
{
    FILE * fp1, FILE *fp2;
    fp1=fopen("f1.txt","r");
    fp2=fopen("f2.txt","r");
    INFO * info;
    int n,length;
    int i=0;
    char *tmp;
    
    fscanf(fp1,"%d %*s",n);
    info=malloc(sizeof(INFO)*n);
    while(fscanf(fp1,"%s",tmp)!=EOF){
        length=strlen(tmp);
        info.word=malloc(sizeof(char)*length);
        strcpy(tmp,info[i]);
        i++;
    }
    char line[100];
    while(fscanf(fp2,"%s",tmp)!=EOF){
        for(i=0;i)
            
        }
    }
    
}

int str_cmp(char *s1, char *s2){
    int i=0;
    if(strlen(s1)==strlen(s2)){
        while((s1[i]==s2[i] || s1[i]==s2[i]+32) && s1[i]!='\0'){
            i++;
        }
    }
    if (s1[i]=='\0')
        return 1;
    else
        return 0;
}


