
#include <iostream>
using namespace std;

class Faculty {
    public:
    string name;
    int payment;
    Faculty* next;
};

// Function to add a new Faculty node
Faculty* add(Faculty* n, Faculty* head){
    if(head == nullptr || n->next == head){
        Faculty* t = new Faculty;
        cout<<"Enter the name: ";
        cin>>t->name;
        cout<<"Enter the payment:";
        cin>>t->payment;

        // If the list is empty, create the first node
        if(head == nullptr){
            t->next = t;
            return t;
        }

        // Otherwise, insert the new node into the circular list
        t->next = head;
        n->next = t;
        return n;
    }

    // Recursively move to the last node
    n->next = add(n->next, head);
    return n;
}

void show(Faculty* n, Faculty* head){
    if(head == nullptr){
        cout<<"This is an empty list\n";
        return;
    }
    do{
        cout<<"---------------------------\n";
        cout<<n->name<<" "<<n->payment<<endl;
        n = n->next; 
        cout<<"---------------------------\n";
    }while(n != head);
}


int main(){
    int userInput;
    Faculty* head = nullptr;

    do {
    cout<<"1) Add\n2)Show\nChoose an option -(Type 0 to exit)-:\n";
    cin>>userInput;
    if(userInput == 1){
        head = add(head, head);
    }
    else if(userInput == 2){
        show(head, head);
    } 
    else if(userInput != 0) {
        cout<<"undefined option, please try again\n";
    }
    } while(userInput);

    // Cleaning up memory
    if(head != nullptr){    
    Faculty* cur = head;
    Faculty* temp = nullptr;

    do{
        temp = cur->next;
        delete cur;
        cur = temp;
    }while(cur != head);
    }
    cout<<"The end of the script\n";
    cout<<"The main is Executed Successfully\n:)";
    return 0;
}