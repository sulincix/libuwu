#include <stdio.h>
#include <libuwu.h>

int main(int argc,char *argv[]){
    char*data=readlines(argv[1]);
    char *v;
    if(argc>2)
        v=get_node(data,argv[2]);
    else
        v=get_node(data,"");
    if(v){
        puts(v);
    }else{
        fputs("Error: Node not found.\n",stderr);
        return 1;
    }
}
