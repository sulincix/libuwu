#include <stdio.h>
#include <libuwu.h>

int main(int angc,char *argv[]){
    char*data=readlines(argv[1]);
    char *v=get_node(data,argv[2]);
    puts(v);
}
