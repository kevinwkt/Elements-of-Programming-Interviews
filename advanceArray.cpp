#include <stdio.h>
#include <vector>

using namespace std;

bool advance(vector<int> &steps){
  int soFar=0;
  for(int i=0;i<=soFar&&soFar<steps.size()-1;i++){
    if(i+steps[i]>soFar) soFar=i+steps[i];
  }
  return soFar>steps.size();
}

int main(){
  vector<int> steps={3,3,1,0,2,0,1};
  if(advance(steps)) printf("YES WE CAN\n");
  else printf("NO WE CAN NOT\n");
}
