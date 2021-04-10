//
//  main.cpp
//  prob_W3_1_Array
//
//  Created by caputdraconis on 2021/04/11.
//

#include <iostream>
#include <string>

using namespace std;

class Stack{
private:
    int* arr; // 배열
    int t; // 탑 인덱스를 저장
    int capacity; // size
public:
    Stack(int t){
        this -> capacity = t;
        this -> arr = new int[t];
        this -> t = -1;
    }
    
    bool empty(){
        return t == -1;
    }
    
    int size(){
        return t + 1;
    }
    
    int top(){
        if(t == -1) return -1;
        else{
            return arr[t];
        }
    }
    
    void push(int elem){
        if(size() == capacity){
            cout<<"FULL"<<endl;
        }
        else{
            arr[++t] = elem;
        }
    }
    
    int pop(){
        if(empty()) return -1;
        else{
            return arr[t--];
        }
    }
};

int main(){
    string input;
    int t, N, elem;
    
    cin>>t>>N; // 스택의 수용 가능한 크기수 t와 명령어 수 N
    Stack stack(t);
    for(int i=0;i<N;i++){
        cin>>input;
        if(input == "empty"){
            if(stack.empty()) cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
        else if(input == "top"){
            cout<<stack.top()<<endl;
        }
        else if(input == "push"){
            cin>> elem;
            stack.push(elem);
        }
        else if(input == "pop"){
            cout<<stack.pop()<<endl;
        }
        else{
            cout<<"Input Error"<<endl;
        }
    }
    
    return 0;
}
