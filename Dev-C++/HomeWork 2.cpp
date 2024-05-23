#include <iostream>
#include <cmath>
using namespace std;
double calculateTotalAmount(double initialAmount, double interestRate, int years){
    double rateDecimal=interestRate/100.0;
    double totalAmount=initialAmount*pow(1+rateDecimal,years);
    return totalAmount;
}
int main(){
    double initialAmount;
    double interestRate;
    int years;
    cout<< "Enter the initial amount of the deposit: ";
    cin>>initialAmount;
    cout<< "Enter the annual interest rate (in percentage): ";
    cin>>interestRate;
    cout<< "Enter the number of years: ";
    cin>>years;
    double totalAmount=calculateTotalAmount(initialAmount,interestRate,years);
    cout<< "Total amount after " <<years<< " years: " <<totalAmount<<endl;
    return 0;
}
