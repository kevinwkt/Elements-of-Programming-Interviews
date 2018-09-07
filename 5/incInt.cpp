#include <stdio.h>
#include <vector>

using namespace std;

void incInt(vector<int>& v) {
	int sum = 0;
	int carry = 1;
	for(int i=v.size()-1;i>=0;i--){
		sum = v[i]+carry;
		v[i] = sum%10;
		carry = sum/10;
	}
	if(carry) v.insert(v.begin(),1);
}

int main() {
	vector<int> v = {1,3,4,6,9};
	incInt(v);
	for(int i=0;i<v.size();i++) printf("%d",v[i]);
	printf("\n");
	return 0;
}
