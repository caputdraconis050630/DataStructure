#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
    int data;
    Node* par;
    vector<Node*> chi_v;
    
    Node(int data){
        this->data = data;
        this->par = NULL;
    }
};

class Tree{
public:
    Node* root;
    vector<Node*> node_v;
    
    Tree(int);
    void insertNode(int, int);
    void delNode(int);
    void printChi(int);
    void printPar(int);
    void printDepth(int);
    void printLevel(int);
};

Tree::Tree(int data){
    Node* node = new Node(data);
    this->root = node;
    this->node_v.push_back(node);
}

void Tree::insertNode(int par_data, int data){
    Node* node = new Node(data);
    for(int i = 0;i<node_v.size();i++){
        if(node_v[i]->data == par_data){
            node_v[i]->chi_v.push_back(node);
            node->par = node_v[i];
            node_v.push_back(node);
            return;
        }
    }
    cout<<-1<<endl;
}

void Tree::delNode(int data){
    Node* curNode;
    Node* parNode;
    
    for(int i =0;i<node_v.size();i++){
        if(node_v[i]->data == data){
            //지우려고 하는 노드가 루트 노드이면 문제가 있음,,
            if(node_v[i] == root){
                cout<<-1<<endl;
                return;
            }
            
            curNode = node_v[i];
            parNode = curNode->par;
            
            for(Node* child : curNode->chi_v){
                parNode->chi_v.push_back(child);
                child->par = parNode;
            }
            
            for(int j =0;j<parNode->chi_v.size();j++){
                if(parNode->chi_v[j]->data == data){
                    parNode->chi_v.erase(parNode->chi_v.begin()+j);
                }
            }
            
            node_v.erase(node_v.begin()+i);
            delete curNode;
            return;
            
            
        }
    }
    cout<<-1<<endl;
}

void Tree::printChi(int data){
    for(int i=0;i<node_v.size();i++){
        if(node_v[i]->data == data){
            if(node_v[i]->chi_v.empty() ){
                cout<<-1<<endl;
                return;
            }
            for(Node* child:node_v[i]->chi_v){
                cout<<child->data<<" ";
            }
            cout<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

void Tree::printPar(int data){
    for(int i=0;i<node_v.size();i++){
        if(node_v[i]->data == data){
            if(node_v[i]==root){
                cout<<-1<<endl;
                return;
            }
            cout<<node_v[i]->par->data<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

void Tree::printDepth(int data){
    int depth=0;
    Node* temp;
    for(int i=0;i<node_v.size();i++){
        if(node_v[i]->data == data){
            temp = node_v[i];
            
            while(temp != root){
                temp = temp->par;
                depth++;
            }
            
            cout<<depth<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
    return;
}
void printLevel(int data){
    
}


int main(){
    int N; // 트리의 노드 입력 개수
    int M; // 질문 수
    int par, chi;
    cin>>N>>M;
    Tree* myTree = new Tree(1);
    for(int i = 0;i<N;i++){
        cin>>par>>chi;
        myTree->insertNode(par, chi);
    }
    
    for(int i=0;i<M;i++){
        cin>>chi;
        myTree->printDepth(chi);
    }
}
