#include <stdio.h>
#include <libuwu.h>
#include "strings.c"
#include "files.c"

char* get_node(char *data, char *path){
    char **p=strsplit(path,".");
    int psize=strcount(path,".");
    char*tmp=data;
    for(int i=0;i<psize;i++){
        tmp=get_area(tmp,p[i]);
    }
    return tmp;
}

char *get_area(char*data,char*name){
    int al=0;
    int count=0;
    char *tag=malloc(sizeof(name)+sizeof(char)*2);
    strcpy(tag,name);
    strcat(tag," {");
    char *ret=malloc(sizeof(char)*sizeof(data));
    strcpy(ret,"");
    char **lines=strsplit(data,"\n");
    int linelen=strcount(data,"\n");
    for(int i=0;i<linelen;i++){
        char *line=lines[i];
        line=trim(line);
        if(al==1){
            for(int j=0;j<strlen(line);j++){
                char c=line[j];
                if (c=='\\'){
                    char cc[2]="\0";
                    cc[0]=line[j+1];
                    j=j+2;
                    c=line[j];
                    strcat(ret,cc);
                }
                if (c=='}'){
                    count--;
                }
                if (c=='{'){
                    count++;
                }
                if (count==0){
                    return ret;
                }else{
                    char cc[2]="\0";
                    cc[0]=c;
                    strcat(ret,cc);
                }
            }
            strcat(ret,"\n");
        }
        if(al==0 && 0==strcmp(line,tag)){
            al=1;
            count=1;
        }
        
    }
    return ret;
}

char* write_area(char*data,char*name){
    char *ret=malloc(sizeof(char)*(5+sizeof(name)+sizeof(data)));
    strcpy(ret,name);
    strcat(ret," {\n");
    strcat(ret,data);
    strcat(ret,"\n}");
    return ret;
}

