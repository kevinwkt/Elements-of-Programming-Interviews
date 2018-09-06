#include <stdio.h>

using namespace std;

unsigned add(unsigned a, unsigned b);

unsigned xy(unsigned x, unsigned y) {
	unsigned sum = 0;
	while(x) {
		if(x&1) sum = add(sum,y);
		x>>=1, y<<=1;
	}
	return sum;
}

unsigned add(unsigned a, unsigned b) {
	unsigned sum = 0, carryin = 0, k = 1, aa = a, bb = b;
	while(aa || bb) {
		unsigned aval = (a&k), bval = (b&k);
		unsigned carryout = (aval&bval) | (aval&carryin) | (bval&carryin);
		sum |= (aval^bval^carryin);
		carryin = carryout<<1, aa>>=1, bb>>=1, k<<=1;
	}

	return sum|=carryin;

}

int main() {
	printf("%d x %d = %d\n",2,3,xy(2,3));
	return 0;
}
