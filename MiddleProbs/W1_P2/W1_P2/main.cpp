#include <iostream>

using namespace std;

class User_Array{
private:
    int size;
    int* arr;
    
public:
    User_Array(int sz){
        this->size = sz;
        arr = new int[sz];
    }
    void right_shift(int D){
        int tmp;
        for(int i=0;i<D;i++){
            tmp = arr[size-1];
            for(int j=size-1;j>0;j--){
                arr[j] = arr[j-1];
            }
            arr[0] = tmp;
        }
        
        print();
    }
    
    void input(int i, int elem){
        arr[i] = elem;
    }
    
    void print(){
        for(int i = 0; i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    int T, N, D, data;
    cin>>T;
    for(int i =0 ;i<T;i++){
        cin>>N>>D;
        User_Array arr(N);
        for(int j=0;j<N;j++){
            cin>>data;
            arr.input(j, data);
        }
        
        arr.right_shift(D);
    }
}
