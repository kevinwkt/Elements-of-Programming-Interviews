#include <stdio.h>
#include <vector>


using namespace std;

int main(){

  vector<int> v={1,5,7,4,3,6,8,3,2,7};

  for(int i=0;i<v.size();i++) printf("%2d",v[i]);
  printf("\n");

  make_heap(v.begin(),v.end());

  for(int i=0;i<v.size();i++) printf("%2d",v[i]);
  printf("\n");
}
