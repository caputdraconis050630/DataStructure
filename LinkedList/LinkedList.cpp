#include <iostream>

using namespace std;

class Node{
    int elem; // element 데이터를 저장하는 변수
    Node* next; // Next Node 를 가리키는 포인터 변수
    
    friend class S_LinkedList; // freind : head와 tail에 접근을 제공하기 위해 선언
};

class S_LinkedList{
private:
    Node* head; // head 노드를 가리키는 포인터
    Node* tail; // tail 노드를 가리키는 포인터
    
public:
    S_LinkedList();
    int List_size();
    bool Empty();
    void Print();
    void Append(int elem);
    int Delete(int idx);
    void Insert(int idx, int elem);
};

S_LinkedList::S_LinkedList(){
    head = new Node();
    tail = new Node();
    
    head = NULL;
    tail = NULL;
    
}

bool S_LinkedList::Empty(){
    return (head == NULL && tail == NULL); // head하고 tail이 널이면 링크드리스트가 비어있다고 True를 변환
}

int S_LinkedList::List_size(){
    int list_size = 0; //리스트 사이즈를 저장할 변수
    
    if(Empty()){
        return list_size; // list_size 는 아직 0
    }
    else{
        Node* cur_node = head; // 카운트를 시작할 head 부터 시작
        while(cur_node -> next != NULL){ // 여기서 False가 되는 경우는 cur_node가 Tail 일때
            list_size++;
            cur_node = cur_node -> next;
        }
        
        list_size++; //Tail도 링크드리스트의 일부이므로 사이즈++
        return list_size;
    }
}

void S_LinkedList::Print(){
    if(Empty()){
        cout<<"Empty"<<endl;
    }
    else{
        Node* cur_node = head;
        while(cur_node->next != NULL){ // cur_node가 tail일때 걸림
            cout<<cur_node->elem<<' ';
            cur_node = cur_node->next;
        }
        
        cout<<cur_node -> elem <<endl; // tail의 elem을 출력
    }
}

void S_LinkedList::Append(int elem){
    Node* new_node = new Node;
    new_node->elem = elem;
    new_node->next = NULL;
    
    if(Empty()){ // 비어있을 때 새로 만든 노드를 head와 tail로
        head = new_node;
        tail = new_node;
    }
    else{
        tail->next = new_node;
        tail = tail->next;
    }
}

int S_LinkedList::Delete(int idx){
    int removeNum = 0;
    int cnt = 0;
    Node* cur_node;
    Node* pre_node;
    
    if(Empty() || List_size() <= idx){ // 잘못된 입력 혹은 빈 리스트
        return -1; // 예외처리
    }
    else if(idx==0){ //첫번째 head를 지우는 경우
        if(List_size() == 1){ // 한 개의 노드로 이루어진 리스트에서 그 나머지 하나를 없앨 때!
            removeNum = head -> elem;
            tail = NULL;
            head = NULL;
        }
        else{
            cur_node = head;
            removeNum = cur_node -> elem;
            head = cur_node -> next;
        }
    }
    else{
        pre_node = cur_node  = head; // pre_node와 cur_node 모두 head를 가리킴
        while(cnt != idx){
            pre_node = cur_node;
            cur_node = cur_node -> next;
            cnt++;
        }
        // cur_node가 사라질 node
        removeNum = cur_node -> elem;
        pre_node->next = cur_node->next;
        
        if(cur_node == tail){
            tail = pre_node;
        }
    }
    return removeNum;
}

void S_LinkedList::Insert(int idx, int elem){
    Node* new_node = new Node;
    new_node -> elem = elem;
    
    Node* pre_node;
    Node* cur_node;
    int cur_idx = 0;
    
    
    if(idx == 0){
        if(Empty()){
            head = new_node;
            tail = new_node;
        }
        else{
            new_node -> next = head;;
            head = new_node;
        }
    }
    else if(idx<0 || idx> List_size()){
        cout<<"Index Error"<<endl;
    }
    else if(idx == List_size()){
        Append(elem);
    }
    else{
        pre_node = cur_node = head;
        while(cur_idx != idx){
            pre_node = cur_node;
            cur_node = cur_node -> next;
            cur_idx++;
        }
        pre_node -> next = new_node;
        new_node -> next = cur_node;
    }
}


int main(){
    //pass
}
