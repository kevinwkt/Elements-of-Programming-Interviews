#include <stdio.h>
#include <vector>

using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void dutchIt(vector<int>& v) {
	int zero = 0, two = v.size(), i = 0;
	while(i<two){
		if(v[i]==0) swap(&v[zero++],&v[i++]);
		else if(v[i]==2) swap(&v[i],&v[--two]);
		else i++;
	}
}

int main() {
	vector<int> v = {1,0,1,0,2,1,2,2,0};
	dutchIt(v);

	for(int i=0;i<v.size();i++) printf("%3d",v[i]);
	printf("\n");
	return 0;
}
