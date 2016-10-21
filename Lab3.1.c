#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int str_cmp(char *, char *);

typedef struct word{
    char word[20];
    int count;
}INFO;


int main()
{
    FILE * fp1;
    FILE * fp2;
    fp1=fopen("f1.txt","r");
    fp2=fopen("f2.txt","r");
    INFO * info;
    int n,length;
    int i=0;
    char *tmp;

    fscanf(fp1,"%d",&n);
    info=malloc(sizeof(INFO)*n);
    while(fscanf(fp1,"%s",tmp)!=EOF){
        length=strlen(tmp);
        //info[i].word=malloc(sizeof(char)*length);
        strcpy(info[i].word,tmp);
        i++;
    }
    while(fscanf(fp2,"%s",tmp)!=EOF){
        for(i=0;i<n;i++){
            if(str_cmp(info[i].word,tmp)){
                info[i].count++;
            }
        }
    }

    for(i=0;i<n;i++){
        if(info[i].count>1){
            fprintf(stdout,"%s - %d occurrence(s)\n", info[i].word, info[i].count);
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
