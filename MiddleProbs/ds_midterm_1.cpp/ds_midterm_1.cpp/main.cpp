#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    
    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }
    Node(){
        this-> next = NULL;
    }
    
};

class LinkedList{
public:
    Node* head;
    Node* tail;
    
    LinkedList(){
        head = new Node();
        tail = new Node();
        
        this-> head = NULL;
        this-> tail = NULL;
    }
    
    void Append(int x){
        Node* node = new Node(x);
        if(head==NULL){
            
            
            head = node;
            tail = node;
        }
        else{
            tail-> next = node;
            tail = node;
        }
    }
    
    void Delete(int index){
        int removeNum;
        if(Empty()){
            cout<<-1<<endl;
            return;
        }
        if(index >= ListSize()){
            cout<<-1<<endl;
            return;
        }
        else if(index == 0){
            removeNum = head->data;
            if(ListSize() == 1){
                
                head = NULL;
                tail = NULL;
            }
            else{
                head = head->next;
            }
            
            cout<<removeNum<<endl;
        }
        else{
            int cnt = 0;
            Node* cur = head;
            Node* prev = head;
            while(cnt != index){
                prev = cur;
                cur = cur->next;
                cnt++;
            }
            
            Node* tmp = cur;
            
            prev->next = cur->next;
            if(cur == tail){
                tail = prev;
            }
            cout<<tmp->data<<endl;
            return;
            
            
            
        }
    }
    
    void Insert(int index, int elem){
        if(index<0)
            return;
        if(index>ListSize()){
            return;
        }
        else if(index == 0){
            
            if(ListSize() == 0){
                Node* node = new Node(elem);
                head = node;
                tail = node;
            }
            else{
                Node* node = new Node(elem);
                node -> next = head;
                head = node;
            }
        }
        else if(index == ListSize()){
            Append(elem);
        }
        
        else{
            int cnt = 0;
            Node* node = new Node(elem);
            Node* cur = head;
            Node* prev = head;
            
            while(cnt!=index){
                prev = cur;
                cur = cur->next;
                cnt++;
                
            }
            
            prev-> next = node;
            node->next = cur;
        }
        
        Print();
    }
    
    void Print(){
        if(Empty()){
            
            return;
        }
        Node* cur = head;
        while(cur->next !=NULL){
            cout<<cur->data<<" ";
            cur = cur->next;
        }
        cout<<cur->data<<endl;
        return;
    }
    
    bool Empty(){
        return (head==NULL);
    }
    
    int ListSize(){
        if(Empty())
            return 0;
        Node* tmp = head;
        int count = 0;
        while(tmp->next != NULL){
            count++;
            tmp = tmp->next;
        }
        return count+1;
    }
    
    
};


int main(){
    int M;
    int t, l;
    string oper;
    LinkedList* list = new LinkedList();
    cin>>M;
    for(int i = 0;i<M;i++){
        cin>>oper;
        if(oper == "Delete"){
            cin>>t;
            list->Delete(t);
        }
        else if(oper == "Append"){
            cin>>t;
            list->Append(t);
        }
        else if(oper == "Print"){
            list->Print();
        }
        else if(oper == "Insert"){
            cin>>t>>l;
            list->Insert(t, l);
        }
    }
}


