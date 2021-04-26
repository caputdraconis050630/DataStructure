#include <iostream>

using namespace std;

class Node{
    int elem;
    Node* next;
    Node* prev;
    friend class DoublyLinkedList;
    
    Node(){
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList{
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList(){
        head = new Node();
        tail = new Node();
        
        head = NULL;
        tail = NULL;
    }
    
    bool Empty(){
        return (head == NULL&&tail == NULL);
    }
    
    int List_size(){
        int size{0};
        Node* cur_node;
        if(Empty()){
            return size;
        }
        else{
            cur_node = head;
            while(cur_node->next != NULL){
                cur_node = cur_node->next;
                size++;
            }
            size++;
            return size;
        }
    }
    
    void Print(){
        Node* cur_node = head;
        if(Empty())
            cout<<"empty"<<endl;
        else{
            while(cur_node->next != NULL){
                cout<<cur_node->elem<<" ";
                cur_node = cur_node -> next;
            }
            cout<<cur_node->elem<<endl;
        }
    }
    
    void Print_reverse(){
        Node* cur_node = tail;
        if(Empty())
            cout<<"empty"<<endl;
        else{
            while(cur_node->prev != NULL){
                cout<<cur_node->elem<<" ";
                cur_node = cur_node -> prev;
            }
            cout<<cur_node->elem<<endl;
        }
    }
    
    void Max(){
        int Max;
        Node* cur_node = head;
        if(Empty())
            cout<<"empty"<<endl;
        else{
            Max = cur_node ->elem;
            while(cur_node->next != NULL){
                cur_node = cur_node->next;
                if(Max < cur_node->elem)
                    Max = cur_node->elem;
            }
            cout<<Max<<endl;
        }
    }
    
    void Append(int value){
        Node* new_node = new Node;
        new_node -> elem = value;
        if(Empty()){
            head = new_node;
            tail = new_node;
            
        }else{
            tail -> next = new_node;
            new_node -> prev = tail;
            tail = new_node;
        }
        
        Print();
    }
    
    void Delete(int index){
        int removeNum;
        Node* pre_node;
        Node* cur_node;
        Node* temp;
        int cnt = 0;
        if(Empty() || index>= List_size()){
            cout<<"-1"<<endl;
        }
        else if(index == 0){
            if(List_size() == 1){
                removeNum = head->elem;
                head = NULL;
                tail = NULL;
                
            }
            else{
                removeNum = head->elem;
                head = head->next;
                
            }
            cout<<removeNum<<endl;
        }
        else{
            cur_node = pre_node = head;
            while(cnt != index){
                pre_node = cur_node;
                cur_node = cur_node->next;
                cnt++;
            }
            removeNum = cur_node->elem;
            temp = cur_node->next;
            pre_node->next = temp;
            if(cur_node == tail){
                tail = pre_node;
                pre_node -> next = NULL;
            }
            else{
                temp->prev = pre_node;
            }
            
            
            
            cout<<removeNum<<endl;
        }
    }
   
    
    
    
};

int main(){
    string command;
    int k, M;
    cin>>M;
    DoublyLinkedList* list = new DoublyLinkedList;
    for(int i = 0; i<M;i++){
        cin>>command;
        if(command=="Print")
            list->Print();
        else if(command=="Append"){
            cin>>k;
            list->Append(k);
        }
        else if(command=="Delete"){
            cin>>k;
            list->Delete(k);
        }
        else if(command=="Print_reverse"){
            list->Print_reverse();
        }
        else if(command=="Max")
            list->Max();
        else{
            cout<<"Input Error"<<endl;
            i--;
        }
    }
}
