#include <iostream>
using namespace std;

class Faculty{
private:
    string name;
    int payment;

public:
    Faculty *next;
    Faculty(){
        cout<<"New member created"<<endl;
    }

    void get_data(){
        cout<<"Enter name:\n";
        cin>>name;
        cout<<"Enter payment:\n";
        cin>>payment;
        next = nullptr;
    }

    void print(){
        cout<<"---------------------\n";
        cout<<name<<endl<<payment<<endl;
    }

    bool compare(string x){
        return x == name;
    }

    ~Faculty(){
        cout<<"Member deleted"<<endl;
    }

};

// function to add a new node to the end of the list
Faculty* add(Faculty* n){
    // Base case: if the list is empty.
    if(n == nullptr){
        n = new Faculty;
        n->get_data();
        return n;
    }
    // go to the end of the list and add the new node
    n->next = add(n->next);
    return n;
}

void show(Faculty* n){
    while(n != nullptr){
        n->print();
        n = n->next;
    cout<<"---------------------------\n";
    }

}

// Function to display all nodes in the linked list
Faculty* deleteNode(Faculty* n){
    Faculty* head = n;
    Faculty* prev = nullptr;
    
    string user_input;
    cout<<"Enter a name:\n";
    cin>>user_input;
    while(n != nullptr){
        if(n->compare(user_input)){
            if(prev == nullptr){
                head = n->next;
                delete(n);
                return head;
            }
        else {
            prev->next = n->next;
            delete(n);
            return head; 
        }
        }
        else {
            prev = n;
            n = n->next;
        }
    }
    return head;
}



int main() {
    int userInput;
    // Initialize the head
    Faculty* head = nullptr;
    do {
        cout<<"1) Add\n2)Remove\n3)Show\nChoose an option:\n";
        cin>>userInput;
        if(userInput==1)
            head = add(head);
        else if(userInput == 2)
            head = deleteNode(head);
        else if(userInput == 3)
        show(head);
        else {
        cout<<"undefined option, EXIT\n";
        userInput = 0;
    }
    } while(userInput);

    // Clean up all dynamically allocated memory
        Faculty* temp;
        while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
        }

    cout<<"The end of the script\n";

    return 0;
}
