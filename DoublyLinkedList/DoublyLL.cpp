#include <iostream>
using namespace std;

class Faculty {
    public:
    string name;
    int payment;
    Faculty *next, *prev;
};

// Function to add a new Faculty node at the end
Faculty* add(Faculty* p, Faculty* n){
    if(n == nullptr){
        n = new Faculty;
        cout<<"Enter the name: ";
        cin>>n->name;
        cout<<"Enter the payment: ";
        cin>>n->payment;
        n->next = nullptr;
        n->prev = p;
        return n;
    }

    n->next = add(n, n->next);
    return n;
}

// Function to display the Faculty list
void show(Faculty* n){
    Faculty* rev = nullptr;
    cout<<"---------------------------\n";
    // Display data in forward order
    while(n != nullptr){
        cout<<n->name<<" "<<n->payment<<endl;
        if(n->next == nullptr)  
            rev = n;
        n = n->next;
        cout<<"---------------------------\n";
    }
    cout<<"***************************";
    cout<<"***************************";
    cout<<"***************************";
    // Display data in reverse order
    n = rev;
    while(rev != nullptr){
        cout<<n->name<<" "<<n->payment<<endl;
        n = n->prev; 
        cout<<"---------------------------\n";
    }
}

int main(){
    int userInput;
    Faculty* head = nullptr;

    do {
        cout<<"1) Add\n2)Show\nChoose an option:\n";
        cin>>userInput;
        if(userInput == 1){
            head = add(head, head);
        }
        else if(userInput == 2){
            show(head);
        } 
        else {
            cout<<"undefined option, EXIT\n";
            userInput = 0;
        }
    } while(userInput);

     // Cleaning up memory
    Faculty* current = head;
    while (current != nullptr) {
        Faculty* next = current->next;
        delete current;
        current = next;
    }

    cout<<"The end of the script\n";
    cout<<"The main is Executed Successfully\n:)";
    return 0;
}