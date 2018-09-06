#include <stdio.h>

using namespace std;

unsigned int swapBits(unsigned int n, int i , int j) {
	if(((n>>i)&1) != ((n>>j)&1)) n^=((1<<i)|(1<<j));
	return n;
}

int main() {
	
	printf("%d turns into %d\n",1<<8,swapBits(1<<8,0,8));
	
	return 0;
}
