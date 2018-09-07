#include <stdio.h>
#include <vector>

using namespace std;

void evenOdd(vector<int>* in) {
	vector<int>& v = *in;
	int nextE = 0, nextO = v.size()-1;
	int temp = 0;
	while(nextE<nextO) {
		if(v[nextE]%2) {
			temp = v[nextE];
			v[nextE] = v[nextO];
			v[nextO] = temp;
			nextO--;
		}else nextE++;
	}
}

int main() {
	vector<int> v = {1,2,3,4,5};
	evenOdd(&v);
	for(int i=0;i<v.size();i++) printf("%3d",v[i]);
	printf("\n");
	return 0;
}
