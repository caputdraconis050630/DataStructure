// 배열을 이용한 스택 구현

#include <iostream>

using namespace std;

class arrStack{
public:
    int* arr; // 사용할 배열
    int capacity; // 스택의 크기 == 배열의 크기
    int t; // 스택의 Top 인덱스를 저장할 변수
    
    arrStack(int capacity){ // 생성자 함수, 스택의 크기 capacity를 인자로 받음
        this->capacity = capacity; // this를 이용해 class 내의 변수 capacity에 인자로 받은 스택의 크기를 저장
        this->arr = new int[capacity]; // 스택 크기만큼의 배열을 동적할당
        this-> t = -1; // 스택의 top을 가리키는 인덱스 변수. 비어있을 때의 인덱스는 -1. 값이 하나 들어있다면 배열의 첫번째에 저장되어 있을테니 t는 0.
    }
    int size(){ // 스택의 사이즈를 리턴하는 함수
        return t+1; // t에 저장되어 있는 값은 인덱스 값이므로 실제 크기를 리턴하려면 +1
    }
    
    bool empty(){ // 스택이 비어있으면(t는 -1일때) True, 비어있지 않으면(t는 -1이 아닐때) False를 반환
        return t == -1;
    }
    int top(){ // 스택의 top에 저장되어 있는 값을 리턴하는 함수
        if(empty()) return -1; // 스택에 어느 값도 저장되어 있지 않다면(empty()함수 사용), -1을 리턴.
        else return arr[t]; // 그게 아니라면 top에 저장되어 있는 값(가장 마지막으로 들어온 값)을 리턴
    }
    
    void push(int e){ // 스택에 값을 넣는 함수 Push
        if(size() == capacity) cout<<"FULL"<<endl; // 스택이 꽉 차있다면(size == capacity), FULL 이라는 문자열을 출력
        else arr[++t] = e; // 꽉 차있지 않다면, 기존 t에 +1한 값을 인덱스로 가지는 곳에 e 저장.
    }
    
    int pop(){ // 스택의 top에 저장되어 있는 값을 꺼내오는 Pop 함수. top() 함수와 차이점은, pop은 top에 저장되어 있는 값을 가져오고 top이 바뀜.
        if(empty()) return -1; // 가져올 값이 없다면(t == -1) -1 리턴
        return arr[t--]; // 사라질 값을 리턴하고 top을 바로 다음 값으로 이동
    }
};
int main(){
    //pass
}
