#include <iostream>
using namespace std;
int sumOfDigits(int number){
    int sum=0;
    while(number!=0){
        sum+=number%10;
        number/=10;
    }
    return sum;
}
int main(){
    int count=0;
    for(int i=1000;i<=9999;i++){
        int firstTwoDigits=i/100;
        int lastTwoDigits=i%100; 
        if(sumOfDigits(firstTwoDigits)==sumOfDigits(lastTwoDigits)){
            count++;
        }
    }
    cout<< "Number of lucky tickets: " <<count<<endl;
    return 0;
}
