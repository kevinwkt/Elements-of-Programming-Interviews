//GIVEN SORTED ARRAY, DELETE DUPLICATES

#include <stdio.h>
#include <vector>

using namespace std;

void swap(int* a,int* b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

void delet(vector<int> &v){
  int last=v.size()-1;
  int prev=v[0];
  for(int i=1;i<v.size()-1;i++){
    if(i>=last) break;
    if(v[i]==prev){
      swap(&v[i],&v[last]);
      v[last]=0;
      last--;
      i--;
    }else prev=v[i];
  }
}

int main(){
  vector<int> v={1,1,1,1,3,5,6,7,8,8}; //should give 1,3,5,6,7,8 ,0,0,0,0
  delet(v);
  for(int i=0;i<v.size();i++) printf("%2d",v[i]);
  printf("\n");
}
