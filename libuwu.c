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
    return del_areas(tmp);
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
    for(int i=0;i<strlen(data);i++){
       if(al==0 && 0==strpos(strcut(i,data),tag) && (i == 0 || data[i-1] == ' ' || data[i-1] == '\n' || data[i-1] == '\t')){
            al=1;
            count=1;
            i=i+strlen(tag);
        }
        if(al==1){
            char c=data[i];
            if (c=='\\'){
                char cc[3]="\0";
                cc[0]='\\';
                cc[1]=data[i+1];
                i=i+2;
                c=data[i];
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
    }
    return ret;
}

char *del_areas(char *data){
    char *ret=malloc(sizeof(char)*(strlen(data)+1));
    strcpy(ret,"");
    int count=0;
    for(int i=0;i<strlen(data);i++){
        char c=data[i];
        if(c == '\\' && count==0){
            char cc[2] = "\0";
            c=data[i+1];
            cc[0] = c;
            i=i+2;
            c=data[i];
            strcat(ret,cc);
        }
        if(c == '{'){
            count++;
        }
        if(count==0){
            char cc[2] = "\0";
            cc[0] = c;
            strcat(ret,cc);
        }
        if(c == '}'){
            count--;
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

