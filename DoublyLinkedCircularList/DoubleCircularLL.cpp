#include <iostream>
using namespace std;

class Faculty {
    public:
    string name;
    int payment;
    Faculty *next, *prev;
};

// Function to add a new node to the circular doubly linked list
Faculty* add(Faculty* n, Faculty* head){
    if(head == nullptr || n->next == head){
        Faculty* t = new Faculty;
        cout<<"Enter the name: ";
        cin>>t->name;
        cout<<"Enter the payment:";
        cin>>t->payment;
        if(head == nullptr){
            t->next = t;
            t->prev = t;
            return t;
        }

        t->next = head; 
        head->prev = t;
        n->next = t;
        t->prev = n;
        return n;
    }
    n->next = add(n->next, head);
    return n;
}

// Function to display the Faculty list
void show(Faculty* n, Faculty* head){
    // if there is an empty list
    if(head == nullptr){
        cout<<"This is an empty list\n";
        return;
    }
        cout<<"---------------------------\n";
    do{
        cout<<n->name<<" "<<n->payment<<endl;
        // You can choose the order of navigation by activating one of below lines
        // n = n->prev; 
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
    // Check for an empty list condition
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
    cout<<"The main executed Successfully\n:)";
    return 0;
}