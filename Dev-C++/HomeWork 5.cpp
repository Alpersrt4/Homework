#include <iostream>
using namespace std;
int findElementWithLargestDigitSum(const int arr[], int size){
  int maxDigitSum=0;
  int elementWithMaxDigitSum=-1;
  for (int i=0;i<size;++i){
    int currentDigitSum=0;
    int num=arr[i];
    while (num>0){
      currentDigitSum+=num%10;
      num/=10;
    }
    if(currentDigitSum>maxDigitSum){
      maxDigitSum=currentDigitSum;
      elementWithMaxDigitSum=arr[i];
    }
  }
  return elementWithMaxDigitSum;
}
int main(){
  int arr[]={12,99,435,8,716};
  int n=sizeof(arr)/sizeof(arr[0]);
  int element=findElementWithLargestDigitSum(arr,n);
  if (element!=-1){
    cout<< "First element with largest digit sum: "<<element<<endl;
  } else{
    cout<< "No element found in the array." <<endl;
  }
  return 0;
}
