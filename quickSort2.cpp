#include <stdio.h>
#include <vector>

using namespace std;

void swap(int* a, int*b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

int partition(vector<int> &v, int low, int high){
  int pivVal=v[high];
  int i=-1;
  for(int j=0;j<high;j++){
    if(v[j]<=pivVal){
      i++;
      swap(&v[j],&v[i]);
    }
  }
  swap(&v[i+1],&v[high]);
  return i+1;
}

void quicksort(vector<int> &v,int low, int high){
  if(low<high){
    int index=partition(v,low,high);
    quicksort(v,low,index-1);
    quicksort(v,index+1,high);
  }
}

int main(){
  vector<int> v={1,6,3,6,8,4,3,9};
  quicksort(v,0,v.size()-1);

  for(int i=0;i<v.size();i++) printf("%2d",v[i]);
  printf("\n");
}
