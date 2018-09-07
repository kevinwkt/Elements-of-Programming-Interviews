#include <stdio.h>

using namespace std;

unsigned int badCountBits(unsigned int n) {
	unsigned int count = 0;
	while(n) {
		if(n&1) count++;
		n>>=1;
	}
	return count;
}

unsigned int countBits(unsigned int n) {
	unsigned int count = 0;
	while(n) {
		count++;
		n&=(n-1);
	}
	return count;
}

int main() {
	
	printf("%d gave slowCount: %d, fastCount: %d\n", 25134, badCountBits(25134), countBits(25134));
	
	return 0;
}
