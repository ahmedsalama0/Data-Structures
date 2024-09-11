#include <iostream>

using namespace std;

class Stack 
{
    int tos;
    int size;
    int* st;
    friend void viewContent(Stack x);
    static int counter;
    public:
    Stack(Stack &x);

   
    Stack(int n = 10){
        tos = 0;
        size = n;
        st = new int [n]; 
        counter++;
        cout<<"This is the stack object No. "<<counter<<endl;
        // cout<<"The constructor is fired\n";
    } 

    ~Stack(){
        delete [] st;
        cout<<"This object No. "<<counter<<" is destroyed\n";
        counter--;
        // cout<<"The destructor is activated\n";

    }

    void push(int x);
    int pop();
    static int getCounter();
    Stack& operator = (const Stack& s);
    int getSize(){
        return this->size;
    }
    
};

int Stack::counter = 0;

int Stack::getCounter(){
    return Stack::counter;
}

// Copy Constructor
Stack::Stack(Stack &x){
    tos = x.tos;
    size = x.size;
    st = new int [size];
    for(int i = 0; i < tos; i++)
        st[i] = x.st[i];
    counter++;
    cout<<"Copy Constructor ran successfully\n";
}

void Stack::push(int x){
    if(tos == size){
        cout<<"The stack is full\n";
    }
    else {
        st[tos] = x;
        tos++;
    }
}

int Stack::pop(){
    int retVal;
    if(tos == 0){
        cout<<"Stack is empty\n";
        retVal = -1;
    }

    else {
        tos--;
        retVal = st[tos];
    }
    return retVal;
}
  
void viewContent(Stack x){
    int t  = x.tos;
    while(t != 0)
        cout<<x.st[--t]<<endl;
}


Stack& Stack::operator = (const Stack &s){

    delete [] this->st;
    this->tos = s.tos;
    this->size = s.size;
    this->st = new int[size];
    for(int i = 0; i < tos; i++)
        this->st[i] = s.st[i];
    cout<<"Operator overloading worked successfully\n";
    cout<<this<<endl;
    return *this;
    
}


int main() {
    Stack s1(3);
    Stack s2(2);
    s2=s1;
    Stack s3;
    Stack s4;
    s4.push(1);
    s4.push(2);
    s4.push(3);
    s4.push(4);
    s4.push(5);
    s4.pop();
    s4.pop();
    s4.pop();
    s4.pop();
    // cout<<s2.getSize()<<" "<<s1.getSize()<<endl;
    // s3 = s2 = s1;
    return 0;
}