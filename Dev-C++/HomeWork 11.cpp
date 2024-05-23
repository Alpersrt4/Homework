#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void saveArrayToFile(const vector<double>&array,const string&filename){
    ofstream file(filename.c_str(),ios::binary);
    if(file.is_open()){
        unsigned int length=array.size();
        file.write(reinterpret_cast<const char*>(&length),sizeof(length));
        file.write(reinterpret_cast<const char*>(array.data()),length*sizeof(double));
        file.close();
    }else{
        cerr<<"Unable to open file for writing: "<<filename<<endl;
    }
}
vector<double>readArrayFromFile(const string&filename){
    vector<double>array;
    ifstream file(filename.c_str(),ios::binary);
    if(file.is_open()){
        unsigned int length;
        file.read(reinterpret_cast<char*>(&length),sizeof(length));
        array.resize(length);
        file.read(reinterpret_cast<char*>(array.data()),length*sizeof(double));
        file.close();
    }else{
        cerr<<"Unable to open file for reading: "<<filename<<endl;
    }
    return array;
}
int findFirstOccurrence(const string&filename,double value){
    ifstream file(filename.c_str(),ios::binary);
    if(file.is_open()){
        unsigned int length;
        file.read(reinterpret_cast<char*>(&length),sizeof(length));
        for(unsigned int i=0;i<length;i++){
            double number;
            file.read(reinterpret_cast<char*>(&number),sizeof(number));
            if(number==value){
                file.close();
                return i;
            }
        }
        file.close();
    }else{
        cerr<<"Unable to open file for reading: "<<filename<<endl;
    }
    return -1;
}
int findLastOccurrence(const string&filename,double value){
    int lastIndex=-1;
    ifstream file(filename.c_str(),ios::binary);
    if(file.is_open()){
        unsigned int length;
        file.read(reinterpret_cast<char*>(&length),sizeof(length));
        for(unsigned int i=0;i<length;i++){
            double number;
            file.read(reinterpret_cast<char*>(&number),sizeof(number));
            if(number==value){
                lastIndex=i;
            }
        }
        file.close();
    }else{
        cerr<<"Unable to open file for reading: "<<filename<<endl;
    }
    return lastIndex;
}
void replaceDataByIndex(const string&filename,unsigned int index,double newValue){
    fstream file(filename.c_str(),ios::binary|ios::in|ios::out);
    if(file.is_open()){
        unsigned int length;
        file.read(reinterpret_cast<char*>(&length),sizeof(length));
        if(index<length){
            file.seekp(sizeof(length)+index*sizeof(double));
            file.write(reinterpret_cast<const char*>(&newValue),sizeof(newValue));
        }else{
            cerr<<"Index out of range"<<endl;
        }
        file.close();
    }else{
        cerr<<"Unable to open file for reading/writing: "<< filename<<endl;
    }
}
void replaceDataByValue(const string&filename,double oldValue,double newValue){
    fstream file(filename.c_str(),ios::binary|ios::in|ios::out);
    if(file.is_open()){
        unsigned int length;
        file.read(reinterpret_cast<char*>(&length),sizeof(length));
        for(unsigned int i=0;i<length;i++){
            double number;
            streampos pos=file.tellg();
            file.read(reinterpret_cast<char*>(&number),sizeof(number));
            if(number==oldValue){
                file.seekp(pos);
                file.write(reinterpret_cast<const char*>(&newValue),sizeof(newValue));
            }
        }
        file.close();
    }else{
        cerr<<"Unable to open file for reading/writing: "<<filename<<endl;
    }
}
int main(){
    vector<double>array;
    array.push_back(1.5);
    array.push_back(2.5);
    array.push_back(3.5);
    array.push_back(2.5);
    array.push_back(4.5);
    string filename="array_data.bin";
    saveArrayToFile(array,filename);
    vector<double>readArray=readArrayFromFile(filename);
    cout<<"Array read from file: ";
    for(unsigned int i=0;i<readArray.size();i++){
        cout<<readArray[i]<<" ";
    }
    cout<<endl;
    cout<<"First occurrence of 2.5: "<<findFirstOccurrence(filename,2.5)<<endl;
    cout<<"Last occurrence of 2.5: "<<findLastOccurrence(filename,2.5)<<endl;
    replaceDataByIndex(filename, 1, 9.5);
    readArray=readArrayFromFile(filename);
    cout<<"Array after replacing index 1 with 9.5: ";
    for(unsigned int i=0;i<readArray.size();i++){
        cout<<readArray[i]<<" ";
    }
    cout<<endl;
    replaceDataByValue(filename,2.5,7.5);
    readArray=readArrayFromFile(filename);
    cout<<"Array after replacing 2.5 with 7.5: ";
    for(unsigned int i=0;i<readArray.size();i++){
        cout<<readArray[i]<<" ";
    }
    cout<<endl;
    return 0;
}
