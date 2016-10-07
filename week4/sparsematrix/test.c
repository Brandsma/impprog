#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>

int main() {
	char ch[5];
	int i = 0;
	do {
		scanf("%c", &ch[i]);
		i++;
	} while(ch == '\n');

	for(i=0; i<5; i++) {
		printf("%d\n", atoi(&ch));
	}
	return 0;
}