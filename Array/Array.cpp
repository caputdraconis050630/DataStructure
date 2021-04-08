#include <iostream>

using namespace std;

class Array{
private:
    int *arr;
    int arrSize;
    
public:
    Array(int sz){
        this->arrSize = sz;
        this->arr = new int[arrSize];
        for(int i=0;i<arrSize;i++){
            arr[i] = 0;
        }
        
    }
    
    int at(int idx){
        return arr[idx];
    }
    
    void add(int idx, int value){
        for(int i = arrSize-2;i >= idx; i++){
            arr[i+1] = arr[i]; // idx 인덱스의 값부터 한칸씩 오른쪽으로 이동
        }
        arr[idx] = value;
    }
    
    void set(int idx, int value){
        arr[idx] = value;
    }
    
    void print(){
        for(int i=0;i<arrSize;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    void remove(int idx){
        for(int i = idx;i<arrSize-1;i++){
            arr[i] = arr[i+1];
        }
        arr[arrSize-1] = 0;
    }
};

int main(){
    // pass;
}
