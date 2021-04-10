// Stack Using Linked List

#include <iostream>

using namespace std;

class Node{ // 스택에 들어가있는 데이터 하나하나를 담당해줄 노드 클래스
public:
    int data;
    Node* next;
    Node(int e){
        this->data = e;
        this->next = NULL;
    }
};

class linkedStack{ // 링크드리스트로 구성한 스택
public:
    Node* head; // head를 맡아줄 노드
    Node* tail; // tail을 맡아줄 노드
    int n; // 링크드리스트에 포함된 노드의 개수
    
    linkedStack(){ // 생성자 함수. head와 tail, 노드의 개수를 초기화한다.
        this->head = NULL;
        this->tail = NULL;
        this->n = 0;
    }
    
    int size(){ // 사이즈를 출력하는 함수
        return n;
    }
    
    bool empty(){ // 스택이 비어있는지 아닌지 체크하는 함수
        return n == 0; // n이 0인지 아닌지 반환
    }
    
    int top(){ // 스택의 가장 위에 있는 데이터 리턴
        if(empty()) return -1; // 스택이 비어있으면 -1 리턴
        return head->data; // 비어있지 않다면 값 리턴
    }
    
    void push(int e){
        Node* newNode = new Node(e);
        if(empty()){
            head = tail = newNode;
            n++;
        }
        else{
            newNode -> next = head;
            head = newNode;
            n++;
        }
    }
    
    int pop(){
        if(empty()) return -1;
        else{
            Node* temp = head;
            head = head->next;
            n--;
            return temp -> data;
            
        }
    }
};
int main(){
    // pass
}

