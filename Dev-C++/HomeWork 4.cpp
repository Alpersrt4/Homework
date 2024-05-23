#include <iostream>
using namespace std;
int sumOfTwoDigitNumbers(const int arr[],int size){
  int sum=0;
  for(int i=0;i<size;++i){
    if (arr[i]>=10&&arr[i]<=99){
      sum+=arr[i];
    }
  }
  return sum;
}
int main(){
  int arr[]={1,12,34,56,9,100};
  int n=sizeof(arr)/sizeof(arr[0]);
  int sum=sumOfTwoDigitNumbers(arr,n);
  cout<< "Sum of two-digit numbers in the array: "<<sum<<endl;
  return 0;
}

