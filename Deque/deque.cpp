 #include<iostream>
 #include<deque>
 #include<string>
 using namespace std;

// deque
// deque: stand for -> double ended queue

 int main(){
    deque<int> trains;
    int c, a;
    do{
        cout<<"C Train: ";
        cin>>c;
        cout<<"A Train: ";
        cin>>a;
        trains.push_back(c);
        trains.push_front(a);

    } while( c || a); // while neither train arrives from a nor c;

    while(!trains.empty()){
        if(trains.back()!= 0){
            cout<<trains.back();
            cout<<" Going To C\n";
        }

        if(trains.front()!= 0){
            cout<<trains.front();
            cout<<" Going to A\n";
        }
        trains.pop_back();
        trains.pop_front();
    }
    return 0;
 }