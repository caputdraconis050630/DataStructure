#include <iostream>
#include <string>

using namespace std;


class Node{
public:
    Node* next;
    char data;
    
    Node(){
        this->next = NULL;
    }
    Node(int data){
        this->next = NULL;
        this->data = data;
    }
};

class Stack{
public:
    Node* head;
    Node* tail;
    int n; // 자료개수
    
    Stack(){
        n = 0;
        head = NULL;
        tail = NULL;
    }
    
    bool Empty(){
        return n == 0;
    }
    
    void enqueue(char elem){
        Node* node = new Node(elem);
        if(Empty()){
            head = node;
            tail = node;
            n++;
        }
        else{
            tail->next = node;
            tail = node;
            n++;
        }
    }
    
    void dequeue(){
        
        if(n ==1){
            head = NULL;
            tail = NULL;
            n--;
        }
        else{
           
            head = head-> next;
            n--;
            
        }
            
        
    }
    
    
    int Size(){
        return n;
    }
    
    void Print(){
        if(Empty()){
            cout<<0<<endl;
        }
        else{
            Node* cur = head;
            while(cur->next != NULL){
                cout<<cur->data;
                cur = cur->next;
            }
            cout<<cur->data<<endl;
        }
    }
    
    void Sort(){
        if(Empty()){
            return;
        }
        else if(Size()<3){
            return;
        }
        else{
            Node* cur = head;
            int cnt = 0;
            char tmp = 'Q';
            while(cur->next != NULL){
                if(cnt==2){
                    dequeue();
                    dequeue();
                    dequeue();
                    cnt=0;
                    return;
                    
                }
                
                
                if(cur->data == tmp){
                    cnt++;
                }
                else{
                    cnt = 0;
                    tmp = cur->data;
                }
                cur = cur->next;
            }
            if(cnt==2){
                dequeue();
                dequeue();
                dequeue();
                cnt=0;
                return;
            }
            
        }
        
        
    }
    
};


int main(){
    string input;
    int N;
    cin>> N;
    
    
    for(int i = 0;i<N;i++){
        Stack* stack = new Stack();
        cin>>input;
        
       
        for(int j = 0; j<int(input.length());j++){
            stack->enqueue(input.at(j));
            
        }
        
        
        stack->Sort();
        stack->Sort();
        stack->Sort();
        stack->Sort();
        stack->Sort();
        stack->Sort();
        stack->Sort();
        stack->Sort();
        stack->Sort();
        stack->Sort();stack->Sort();stack->Sort();stack->Sort();
        stack->Print();
        
        
        
        
    }
}





