#include <stdio.h>
#include <vector>

using namespace std;

void swap(int* a,int* b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

int partition(vector<int> &v,int low, int high){
  int piv=v[high];
  int i=low-1;
  for(int j=low;j<high;j++){
    if(v[j]<=piv){
      i++;
      swap(&v[j],&v[i]);
    }
  }
  swap(&v[i+1],&v[high]);
  return i+1;
}

void quickSort(vector<int> &v,int low, int high){
  if(low<high){
    int piv=partition(v,low,high);
    quickSort(v,low,piv-1);
    quickSort(v,piv+1,high);
  }
}

int main(){
  vector<int> v={1,6,3,7,9,7,4,43,2,1};
  quickSort(v,0,v.size()-1);

  for(int i=0;i<v.size();i++) printf("%3d",v[i]);
  printf("\n");
}
