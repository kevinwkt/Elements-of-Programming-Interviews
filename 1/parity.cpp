#include <stdio.h>

using namespace std;

bool parity(unsigned int n) {
	unsigned int p = 0;
	while(n) {
		p^=1;
		n&=(n-1);
	}
	return p;
}

int main() {
	
	printf("%d gave partity of %d\n",1345,parity(1345)? 1:0);
	return 0;
}
