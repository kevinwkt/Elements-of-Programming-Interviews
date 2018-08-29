#include <stdio.h>

using namespace std;

// O(turned on bits)

unsigned int shortCount(unsigned int n) {
	int count = 0;
	while(n) {
		count++;
		n &= (n-1);
	}
	return count;
}

// O(32)
unsigned int longCount(int n) {
	int count = 0;
	while(n) {
		if(n & 1) count++;
		n >>= 1;
	}
	return count;
}

int main() {
	unsigned int n = 58;

	unsigned int ans = shortCount(n);
	printf("Answer should be 4, we got %u\n",ans);
	
	ans = longCount(n);
	printf("Answer should be 4, we got %u\n",ans);
	
	return 0;
}
