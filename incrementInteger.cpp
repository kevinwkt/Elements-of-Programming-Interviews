#include <stdio.h>
#include <vector>

using namespace std;

void increment(vector<int> &v){
  int carry=0;
  if(v[v.size()-1]!=9) v[v.size()-1]++;
  else{
    v[v.size()-1]=0;
    int carry=1;
    for(int i=v.size()-2;i>=0;i--){
      if(v[i]==9) v[i]=0;
      else{
        v[i]++;
        carry=0;
        break;
      }
    }
    if(carry) v.insert(v.begin(),1);
  }
}

int main(){
  vector<int> v={6,4,2,5,9,9};
  increment(v);
  for(int i=0;i<v.size();i++) printf("%2d",v[i]);
  printf("\n");
}
