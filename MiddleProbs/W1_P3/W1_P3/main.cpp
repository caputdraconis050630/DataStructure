#include <iostream>

using namespace std;

class UserArray{
private:
    int size;
    int* arr;
    
public:
    UserArray(int sz){
        this->size = sz;
        arr = new int[size];
        for(int i=0;i<sz;i++){
            arr[i] = 0; // 초기화
        }
    }
    
    void at(int l){
        cout<<arr[l]<<endl;
    }
    
    void print(){
        for(int i=0;i<size-1;i++){
            cout<<arr[i]<<" ";
        }
        cout<<arr[size-1]<<endl;
    }
    
    void set(int i, int value){
        arr[i] = value;
        cout<<value<<endl;
    }
    
    void find_min(){
        int min = arr[0];
        for(int i=1;i<size;i++){
            if(min > arr[i])
                min = arr[i];
        }
        cout<<min<<endl;
    }
    
    void add(int l, int value){
        for(int i = size-1;i>l;i--){
            arr[i] = arr[i-1];
        }
        arr[l] = value;
    }
    
    void remove(int l){
       
        for(int i = l; i<size-1;i++){
            arr[i] = arr[i+1];
        }
        arr[size-1] = 0;
        
    }
    
    
};


int main(){
    int N, T, l, t;
    string command = "";
    cin >> N >> T; // 배열의 크기랑 테스트 케이스 수
    UserArray arr(N);
    
    
    for(int i=0;i<T;i++){
        cin>> command;
        if(command == "at"){
            cin>>l;
            arr.at(l);
            
        }
        else if(command == "add"){
            cin>>l>>t;
            arr.add(l, t);
        }
        else if(command == "remove"){
            cin>>l;
            arr.remove(l);
        }
        else if(command == "set"){
            cin>>l>>t;
            arr.set(l, t);
        }
        else if(command == "print"){
            arr.print();
        }
        else if(command == "find_min"){
            arr.find_min();
        }
        else{
            cout<<"WHAT!?"<<endl;
        }
    }
}
