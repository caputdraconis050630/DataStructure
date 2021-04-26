#include <iostream>

using namespace std;

class Node{
    int elem;
    Node* next;
    friend class linkedStack;
    
    Node(int e){
        this->elem = e;
        this->next =NULL;
    }
};

class linkedStack{
    Node* head;
    Node* tail;
    int n; // 스택의 크기 저장 변수
    
public:
    linkedStack(){
        this->head = NULL;
        this->tail = NULL;
        
        this->n = 0;
    }
    
    bool empty(){
        return n==0;
    }
    
    int top(){
        if(empty())
            return -1;
        else{
            return head->elem;
        }
    }
    
    void push(int e){
        Node* newNode = new Node(e);
        if(empty()){
            head = newNode;
            tail = newNode;
            n++;
        }
        else{
            newNode->next = head;
            head = newNode;
            n++;
        }
    }
    int pop(){
        if(empty()){
            return -1;
        }
        else{
            int num = head->elem;
            head = head->next;
            n--;
            return num;
        }
    }
};

int main(){
    string command;
    int k, N;
    cin>>N;
    linkedStack* stack = new linkedStack();
    for(int i=0;i<N;i++){
        cin>>command;
        if(command=="empty"){
            if(stack -> empty())
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
        else if(command=="top"){
            cout<<stack->top()<<endl;
        }
        else if(command == "push"){
            cin>>k;
            stack->push(k);
        }
        else if(command == "pop"){
            cout<<stack->pop()<<endl;
        }
        else{
            cout<<"Input Error"<<endl;
            i--;
        }
    }
    
}

