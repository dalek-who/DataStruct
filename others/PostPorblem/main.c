#include <stdio.h>
#include "Queue.h"
#include <string.h>

//波斯特对应问题，求匹配块

typedef struct block{
    char up[5];
    char down[6];
}block;



int main() {
//    printf("Hello, World!\n");

    block BlockArray[4];
    strcpy(BlockArray[0].up,  "ab");
    strcpy(BlockArray[0].down,"abab");
    strcpy(BlockArray[1].up,  "b");
    strcpy(BlockArray[1].down,"a");
    strcpy(BlockArray[2].up,  "aba");
    strcpy(BlockArray[2].down,"b");
    strcpy(BlockArray[3].up,  "aa");
    strcpy(BlockArray[3].down,"a");

    makeup out,in;//InitStack(&in.stack);
    Queue queue; InitQueue(&queue);

    int i;
    i=0;
    strcpy(in.up,BlockArray[i].up);
    strcpy(in.down,BlockArray[i].down);
    strcpy(in.block,"0");
    EnQueue(&queue,in);

    i=3;
    strcpy(in.up,BlockArray[i].up);
    strcpy(in.down,BlockArray[i].down);
    strcpy(in.block,"3");
    EnQueue(&queue,in);

    int result,number=0;
    char c[2];
    do{
        out=DeQueue(&queue);
//        puts(out.block);

        result= strcmp(out.up,out.down);

            for(i=0;i<4;++i){
                in=out;
                c[0]='0'+(char )i;
                strcat(in.up,BlockArray[i].up);
                strcat(in.down,BlockArray[i].down);
                strcat(in.block,c);
                EnQueue(&queue,in);
            }

        if( result==0 ) {
            puts(out.up);
            puts(out.block);
            printf("%d\n",queue.len);
            ++number;
            continue;
        }

    }while ((0 != result) || number<10 );

    puts(out.up);
    puts(out.block);

    return 0;
}