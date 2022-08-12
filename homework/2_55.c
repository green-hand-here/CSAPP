#include <stdio.h>
#include <string.h>
typedef unsigned char *byte_pointer;

// size_t 表示C中任何对象所能达到的最大长度, 是无符号整数
// 它是为了方便系统之间的移植而定义的
// 32位系统 : unsigned int
// 64位系统 : unsigned long
// size_t 的目的是提供一种可移植方法来声明与系统中可寻址的内存区域一致的长度
void show_bytes(byte_pointer start, size_t len){
	size_t i;
	for(int i = 0; i < len; i++){
		printf("%.2x ", start[i]);
	}
	printf("\n");
}

void show_int(int x){
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x){
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x){
	show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val){
	int ival = val;
	float fval = (float) ival;
	int *pval = &ival;
	show_int(ival);
	show_float(fval);
	show_pointer(pval);
}

int main(){
	const char *s = "abcdef";
	show_bytes((byte_pointer) s, strlen(s));
}