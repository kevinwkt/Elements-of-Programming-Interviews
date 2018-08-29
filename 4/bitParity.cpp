#include <stdio.h>

using namespace std;

unsigned int shortPar(unsigned int n) {
	unsigned int par = 0;
	while(n) {
		par ^= 1;
		n &= (n-1);
	}
	return par;
}

unsigned int longPar(unsigned int n) {
	unsigned int par = 0;
	while(n) {
		par ^= (n & 1);
		n >>= 1;
	}
	return par;
}

int main() {
	unsigned int n = 59;

	unsigned int ans = shortPar(n);
	printf("Expected Answer is 1, we got %u\n",ans);

	ans = longPar(n-1);
	printf("Expected Answer is 0, we got %u\n",ans);
	return 0;
}
