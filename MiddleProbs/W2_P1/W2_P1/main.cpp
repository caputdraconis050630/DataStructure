#include <iostream>

using namespace std;

class Node{
private:
    
    int elem;
    Node* next;
    friend class LinkedList;

};

class LinkedList{
private:
    Node* head;
    Node* tail;
public:
    LinkedList(){
        head = new Node();
        tail = new Node();
        
        head = NULL;
        tail = NULL;
    }
    
    bool Empty(){
        return (head==NULL&&tail==NULL);
    }
    
    int List_size(){
        int list_size = 0;
        if(Empty())
            return list_size;
        else{
            Node* cur_node = head;
            while(cur_node -> next != NULL){
                list_size++;
                cur_node = cur_node->next;
            }
            list_size++;
            return list_size;
        }
    }
    
    void Print(){
        if(Empty())
            cout<<"empty"<<endl;
        else{
            Node* cur_node = head;
            while(cur_node->next != NULL){
                cout<<cur_node->elem<<" ";
                cur_node = cur_node->next;
            }
            cout<<cur_node->elem<<endl;
        }
        
    }
    
    void Append(int value){
        Node* new_node = new Node();
        new_node -> elem = value;
        
        if(Empty()){
            head = new_node;
            tail = new_node;
        }
        else{
            tail->next = new_node;
            tail = new_node;
        }
        
        Print();
    }
    
    void Delete(int index){
        int removeNum;
        Node* cur_node;
        Node* pre_node;
        if(Empty() || List_size() <= index){
            removeNum = -1;
        }
        else if(index == 0){
            if(List_size() == 1){
                removeNum = head->elem;
                head = NULL;
                tail = NULL;
            }
            else{
                cur_node = head;
                removeNum = cur_node->elem;
                head = cur_node -> next;
            }
        }
        else{
            cur_node = pre_node =  head;
            for(int i=0;i<index;i++){
                pre_node = cur_node;
                cur_node = cur_node->next;
            }
            
            removeNum = cur_node -> elem;
            pre_node -> next = cur_node->next;
            
            if(cur_node == tail){
                tail = pre_node;
            }
            
            
            
        }
        cout<<removeNum<<endl;
    }
    
    void Sum(){
        int sum{0};
        if(Empty())
            cout<<sum<<endl;
        else{
            Node* cur_node = new Node();
            cur_node = head;
            while(cur_node->next != NULL){
                sum += cur_node->elem;
                cur_node = cur_node -> next;
            }
            sum += cur_node->elem;
            cout<<sum<<endl;
        }
    }
    
    void Insert(int index, int value){
        Node* new_node = new Node;
        new_node -> elem = value;
        
        Node* pre_node;
        Node* cur_node;
        int cur_idx = 0;
        if(index>List_size() || index<0)
            cout<<"Index Error"<<endl;
        else{
            if(index == 0){
                if(Empty()){
                    head = new_node;
                    tail = new_node;
                }
                else{
                    new_node -> next = head;
                    head = new_node;
                }
            }
            else if(index == List_size())
                Append(value);
            else{
                pre_node = cur_node = head;
                while(cur_idx != index){
                    pre_node = cur_node;
                    cur_node = cur_node->next;
                    cur_idx++;
                }
                
                pre_node->next = new_node;
                new_node->next = cur_node;
            }
            Print();
        }
    }
    
};

int main(){
    int M, t, k;
    LinkedList* list = new LinkedList();
    string command;
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>command;
        if(command=="Print"){
            list->Print();
        }
        else if(command=="Sum"){
            list->Sum();
        }
        else if(command=="Delete"){
            cin>>t;
            list->Delete(t);
        }
        else if(command=="Append"){
            cin>>t;
            list->Append(t);
        }
        else if(command=="Insert"){
            cin>>t>>k;
            list->Insert(t,k);
            
        }
        else{
            cout<<"Input error"<<endl;
            i--;
        }
    }
}
