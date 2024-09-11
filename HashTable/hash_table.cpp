 #include<iostream>
 using namespace std;

 int transformChar(char c){
    if(c >= 'a' && c <= 'z')
        return (int)c - 'a' + 1;
    return (int)c - 'A' + 1; 
 }

  int hashFunction (string x){
    int retVal = 0;
    for(int i = 1; i <= x.size(); i++)
        retVal += transformChar(x[i-1]) * i;
    return retVal;
  }

  struct Directory {
        string name, number;
        Directory *next;
    } *hashTable[100];


void insert(int index, Directory* c){
    if(hashTable[index%100] == NULL){
        hashTable[index%100] = c;
        return;
    }

    Directory *p = hashTable[index%100];
    while(p->next != NULL)
        p = p->next;
    p->next = c;
    return;
}


 int main(){
    string response;
    do {
        Directory* c = new Directory;
        cout<<"Name: ";
        cin>>c->name;
        cout<<"Number: ";
        cin>>c->number;
        c->next = nullptr;
        int index = hashFunction(c->name);
        insert(index, c);
        cout<<"Do you have another contact?";
        cin>>response;
    } while (response == "yes");

    for(int i = 0; i < 100; i++)
        if(hashTable[i]!=NULL){
            Directory* p = hashTable[i];
            while(p!=NULL){
                cout<<p->name<<endl;
                cout<<p->number<<endl;
                p = p->next;
            }
        }

    return 0;
 }
