#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int ROWS=10000;
const int COLS=10000;
void process2DArray(int **matrix){
    int minElement=matrix[0][0];
    int maxElement=matrix[0][0];
    long long sum=0;
    clock_t start=clock();
    for(int i=0;i<ROWS;++i){
        for(int j=0;j<COLS;++j){
            int element=matrix[i][j];
            if(element<minElement)minElement=element;
            if(element>maxElement)maxElement=element;
            sum+=element;
        }
    }
    clock_t end=clock();
    double time_taken=double(end-start)/CLOCKS_PER_SEC;
    cout<<"Processing time for 2D array: "<<time_taken<<" seconds"<<endl;
    cout<<"Minimum Element: "<<minElement<<endl;
    cout<<"Maximum Element: "<<maxElement<<endl;
    cout<<"Sum of Elements: "<<sum<<endl;
}
void processFlatArray(int *matrix){
    int minElement=matrix[0];
    int maxElement=matrix[0];
    long long sum=0;
    clock_t start=clock();
    for(int i=0;i<ROWS*COLS;++i){
        int element=matrix[i];
        if(element<minElement)minElement=element;
        if(element>maxElement)maxElement=element;
        sum+=element;
    }
    clock_t end=clock();
    double time_taken=double(end-start)/CLOCKS_PER_SEC;
    cout<<"Processing time for flattened array: "<<time_taken<<" seconds"<<endl;
    cout<<"Minimum Element: "<<minElement<<endl;
    cout<<"Maximum Element: "<<maxElement<<endl;
    cout<<"Sum of Elements: "<<sum<<endl;
}
int main(){
    int**matrix2D=new int*[ROWS];
    int*flatMatrix=new int[ROWS*COLS];
    srand(time(NULL));
    for(int i=0;i<ROWS;++i){
        matrix2D[i]=new int[COLS];
        for(int j=0;j<COLS;++j){
            int val=rand()%1000;
            matrix2D[i][j]=val;
            flatMatrix[i*COLS+j]=val;
        }
    }
    process2DArray(matrix2D);
    processFlatArray(flatMatrix);
    for(int i=0;i<ROWS;++i){
        delete[]matrix2D[i];
    }
    delete[]matrix2D;
    delete[]flatMatrix;
    return 0;
}
