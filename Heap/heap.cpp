 #include<iostream>
 using namespace std;

 class Node{
 public:
    int num;
    Node *left, *right;
    Node(int n){
        num = n;
        left = right = nullptr;
    }
 };

 int count(Node* g){
    if(g == nullptr)
        return 0;
    int x = 1 + count(g->left);
    int y = 1 + count(g->right);
    if(x < y)
        return x;
    return y;
 }

 Node* insert(Node *g, int n){
    if(g == nullptr)
        return g = new Node(n);
    int x = count(g->left);
    int y = count(g->right);
    if(x < y)
        g->left = insert(g->left, n);
    else    
        g->right = insert(g->right, n);
    return g;
 }

 void show(Node* g, int p){
    // Base Case.
    if(g == nullptr)
        return;
    // Print the (parent of the node), (node)
    cout<<p<<" ---> "<<g->num<<endl;
    show(g->left, g->num);
    show(g->right, g->num);
 }

 bool checkBinary(Node* g){
    if(g == nullptr)
        return true;
    if(g->left == nullptr && g->right == nullptr)
        return true;
    if(g->left != nullptr && g->right != nullptr)
        return checkBinary(g->left) && checkBinary(g->right);
    return false;
    
 }

 bool checkMinHeap(Node* g){
    if(g == nullptr)
        return NULL;
    if(g->left == nullptr && g->right == nullptr)
        return true;
    if(g->left->num >= g->num && g->right->num >= g->num)
        return checkMinHeap(g->left) && checkMinHeap(g->right);
    return false;
 }

 bool checkMaxHeap(Node* g){
    if(g == nullptr)
        return NULL;
    if(g->left == nullptr && g->right == nullptr)
        return true;
    if(g->left->num <= g->num && g->right->num <= g->num)
        return checkMaxHeap(g->left) && checkMaxHeap(g->right);
    return false;
 }

 int main(){
    Node* g = nullptr;
    int n;
    do {
        cout<<"Enter a number: ";
        cin>>n;
        if(n)
            g = insert(g,n);
    } while(n);

    show(g, 0);
    if(checkBinary(g))
        cout<<"Complete Binary \n";
    if(checkMinHeap(g))
        cout<<"Min-Heap"<<endl;
    if(checkMaxHeap(g))
        cout<<"Max-Heap\n";

    return 0;
 }

 /*
    Test Data:
    for max-heap:=> 10  5  9  3  4  7  8
        10
    5        9
  3   4    7   8

   for min-heap:
   1 5 9 6 7 10 11

        1
    5        9
  6   7   10   11

 */ 