#include <stdio.h>
#include <vector>

using namespace std;

void swap(int* a, int* b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

void dutchNational(vector<int> &v){
  int zeros=0;
  int ones=0;
  int twos=v.size()-1;
  for(int i=0;i<v.size();i++){
    if(v[i]==0&&i<twos){
      swap(&v[i],&v[zeros]);
      zeros++;
    }else if(v[i]==2&&i<twos){
      swap(&v[i],&v[twos]);
      twos--;
      i--;
    }
  }
}

int main(){

  vector<int> v={1,0,2,2,1,0,2,1,2};

  dutchNational(v);

  for(int i=0;i<v.size();i++) printf("%2d",v[i]);
  printf("\n");

}
