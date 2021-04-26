#include <iostream>
#include <string>
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
    int sz;
public:
    linkedStack(int size){
        this->head = NULL;
        this->tail = NULL;
        this -> sz = size;
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
        else if(n == sz)
            cout<<"FULL"<<endl;
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
    int t;
    int elem1, elem2, result;
    string usr_input;
    linkedStack* stack = new linkedStack(99);
    cin>>t;
    for(int i = 0; i<t;i++){
        cin>>usr_input;
        for(int j = 0; j < usr_input.size(); j++){
            if(usr_input[j]>='0' && usr_input[j]<= '9'){
                stack->push(usr_input[j]-'0');
            }
            else if(usr_input[j] == '+'){
                elem1 = stack->pop();
                elem2 = stack->pop();
                stack->push(elem1+elem2);
            }
            else if(usr_input[j] == '-'){
                elem1 = stack->pop();
                elem2 = stack->pop();
                stack->push(elem2-elem1);
            }
            else if(usr_input[j] == '*'){
                elem1 = stack->pop();
                elem2 = stack->pop();
                stack->push(elem1*elem2);
            }
            
        }
        result = stack->pop();
        cout<<result%10<<endl;
        
    }
    
    
    
    
}
