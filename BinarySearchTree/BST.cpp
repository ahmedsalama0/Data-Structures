#include<iostream>
 using namespace std;

 class Company{
 public:
    string name;
    int score;
    Company *left, *right;
    Company(string n, int s){
        name = n;
        score = s;
        left = right = nullptr;
    } 

    void print(){
        cout<<name<<"\t"<<score<<endl;
    }
 }; 

 Company* add(Company* p, string n, int s){
    // Base case
    if (p == nullptr){
    //  if there is no tree, initialize the new tree and allocate memory to it.
    // or if there is node children to a node add them.
        p = new Company(n, s);
        return p;
    }

    // Apply the rules of binary search tree
    // which is the left child of a parent is smaller than it
    // and the right one is greater than it.
    if(s < p->score){
        p->left = add(p->left, n, s);
    }
    if(s > p->score){
        p->right = add(p->right, n, s);
    }
    return p;
 }

 void show(Company* p){
    if(p == nullptr)
        return;
    // preorder displaying 
    // You can move the line that display the parent up and down to display data In-order and in Post-order respectively
    show(p->left);
    p->print(); // parent
    show(p->right);
    
 }

 Company* delete_node(Company* p){
    Company* r = p->right;
    
    Company* l = p->left;
    if(r != nullptr){
        Company* prev = r;
        while(r->left != nullptr){
            prev = r;
            r = r->left;
        }
        if(r != prev)
            prev->left = r->right;
        r->left = p->left;
        if(p->right != r)
            r->right = p->right;
        delete p;
        return r;
    }

    if(l != nullptr){
        Company* prev = l;
        while(l->right != nullptr){
            prev = l;
            l = l->right;
        }
        if(prev != l)
            prev->right = l->left;
        l->right = p->right;
        if(p->left != l)
            l->left = p->left;
        delete p;
        return l;
    }

        delete p;
        return NULL;

 }

  Company* delete_name(Company* p, string n){
    if(p == nullptr)
        return NULL;

    if(p->name == n){
        return delete_node(p);
    }

    p->right = delete_name(p->right, n);
    p->left = delete_name(p->left, n);
    return p;
  }  

 // clean the allocated memory
 void deleteTree(Company* p) {
    if (p == nullptr) return;
    // Recursively delete left and right subtrees
    deleteTree(p->left);
    deleteTree(p->right);
    // Delete the current node
    delete p;
}


 int main(){
    // Parent node of the tree
    Company *parent = nullptr;
    int answer;
    do {
        cout<<"1) Add\n";
        cout<<"2) Show\n";
        cout<<"3) Delete\n";
        cout<<"4) Exit\n";
        cout<<"What would you like to do? ";
        cin>>answer;
        if(answer == 1){
            string n;
            int s;
            cout<<"Name: ";
            cin>>n;
            cout<<"Score: ";
            cin>>s;
            parent = add(parent,n,s);
        }

        else if(answer == 2) {
            show(parent);
        }

        else if(answer == 3){
            cout<<"Name: ";
            string n;
            cin>>n;
            parent = delete_name(parent, n);
        }

    } while(answer >=1 && answer <=3);

    // Free the allocated memory when exiting
    deleteTree(parent);
    parent = nullptr;

    return 0;
 }