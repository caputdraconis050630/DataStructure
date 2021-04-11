// using stack
// create stack with array

#include <iostream>
#include <string>

using namespace std;

class Stack{
private:
    int* arr;
    int t;
    int capacity;
public:
    Stack(int capacity){
        this -> capacity = capacity;
        this -> arr = new int[this->capacity];
        t = -1; // 초기 인덱스.
    }
    
    bool empty(){
        return t == -1;
    }
    
    int top(){
        if(t==-1) return -1;
        else{
            return arr[t];
        }
    }
    
    void push(int elem){
        if(t == capacity-1) cout<<"FULL"<<endl;
        else{
            arr[++t] = elem;
        }
    }
    
    int pop(){
        if(empty()) return -1;
        else{
            return arr[t--];
        }
    }
    
    
};

int main(){
    string input; // 연산식을 입력받은 문자열 변수
    int t; // 입력받을 수식의 수를 저장할 변수
    cin>>t; // 수식의 수 입력받음
    int elem1, elem2;
    int result;
    Stack stack(99);
    
    for(int i = 0; i < t; i++){
        cin >> input; // 연산식 입력
        for(int j=0;j<input.size();j++){
            if(input[j]>= '0' && input[j] <= '9'){
                stack.push(input[j] - '0');
            }
            else{ // 연산자가 들어왔을 때
                int tmp;
                elem1 = stack.pop();
                elem2 = stack.pop();
                if(input[j] == '+'){
                    tmp = elem1 + elem2;
                }
                else if(input[j] == '-'){
                    tmp = elem2 - elem1;
                }
                else if(input[j] == '*'){
                    tmp = elem1 * elem2;
                }
                else{
                    tmp = 0; // 여기까지 올리가,,
                }
                stack.push(tmp);
            }
            if(j == input.size()-1){
                result = stack.pop();
                cout<<result%10<<endl;
            }
        }
    }
}
