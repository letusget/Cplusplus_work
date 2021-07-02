#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

void foo(const char** pp) {
	*pp = (char*)malloc(10);
	snprintf(*pp, 10, "hi google!");
}

int main() {
	const char* p = "hello";
	printf("before foo %s\n", p);
	foo(&p);
	printf("after foo %s/n", p);
	p[1] = 'x';
	return 0;
}