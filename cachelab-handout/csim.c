#include "cachelab.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

// 定义 cache_line 结构
typedef struct {
    int valid_bits; // 有效位 valid_bits bit
    unsigned tag; // 标记位 t_address
    int stamp; // 时间戳 LRU counter (only if you're not using a queue)
}cache_line;
cache_line** cache = NULL;

char* filepath =NULL;
int s, E, b, S;
int hit = 0, miss = 0, eviction = 0;

// 定义 cache[S][E] 为一个二维结构体数组 2D array
void init(){
    // malloc 得到的指针定义成 cache_line**
    // malloc cache[S][E]
    cache = (cache_line**)malloc(sizeof(cache_line*) * S);
    for(int i = 0; i < S; i++){
        *(cache + i) = (cache_line*)malloc(sizeof(cache_line) * E);
    }
    for(int i = 0; i < S; i++){
        for(int j = 0; j < E; j++){
            cache[i][j].valid_bits = 0;
            cache[i][j].tag = 0xffffffff; // no address
            cache[i][j].stamp = 0; // time is 0
        }
    }
}


/*
    | t_address | set index | block offset
 */

void update(unsigned address){
    unsigned s_address = (address>>b) & ((0xffffffff)>>(32 - s));
    unsigned t_address = address>>(s + b);
    // 命中 hit
    for(int i = 0; i < E; i++){
        if((*(cache + s_address) + i)->tag == t_address){
            cache[s_address][i].stamp = 0; // now, this is used
            hit++;
            return;
        }
    }

    // 有效位 valid_bits == 0, miss
    for(int i = 0; i < E; i++){
        if(cache[s_address][i].valid_bits == 0){
            cache[s_address][i].tag = t_address;
            cache[s_address][i].valid_bits = 1;
            cache[s_address][i].stamp = 0; // now, this is load
            miss++;
            return;
        }
    }

    // valide_bits == 1, 但 miss, LRU替换
    int max_stamp = 0;
    int max_i;
    for(int i = 0; i < E; i++){
        if(cache[s_address][i].stamp > max_stamp){
            max_stamp = cache[s_address][i].stamp;
            max_i = i;
        }
    }
    eviction++;
    miss++;
    cache[s_address][max_i].tag = t_address; // LRU 替换
    cache[s_address][max_i].stamp = 0;
}

void time(){
    for(int i = 0; i < S; i++){
        for(int j = 0; j < E; j++){
            if(cache[i][j].valid_bits == 1){
                cache[i][j].stamp++;
            }
        }
    }
}


int main(int argc, char *argv[]){
    int opt;
    // parse command line arguments
    while((opt = getopt(argc, argv,"s:E:b:t:")) != -1){
        switch (opt){
        case 's':
            s = atoi(optarg);
            break;
        case 'E':
            E = atoi(optarg);
            break;
        case 'b':
            b = atoi(optarg);
            break;
        case 't':
            filepath = optarg;
            break;
        }
    }
    S = 1 << s;


    init();
    FILE* file = fopen(filepath,"r");
    // read trace file
    if(file == NULL){
        printf("Open file wrong");
        exit(-1);
    }


    // cache 运行模拟 
    // L : data load
    // S : data store
    // M : date modify
    // 只设计了一类 update 操作, 因为 Load 和 Store 都只访问一次 cache
    // Modify 先读再写, 访问 cache 两次, 所以 M 直接 fall through
    char operation;
    unsigned address;
    int size;
    while(fscanf(file," %c %x,%d", &operation, &address, &size) > 0){
        switch(operation){
            case 'L':
                update(address);
                break;
            case 'M':
                update(address);
            case 'S':
                update(address);
                break;
        }
        time();
    }

    // free cache[S][E]
    // 先按行释放, 再释放二级指针
    for(int i = 0; i < S; i++){
        free(*(cache + i));
    }
    free(cache);

    // close file
    fclose(file);
    printSummary(hit, miss, eviction);
    return 0;
}
