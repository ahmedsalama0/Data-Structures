 #include<iostream>
 #include<list>
 using namespace std;


 int main(){
    //Initializing with values directly
    // list<int> x = {5, 1, 2, 3, 6};
    // or using push
    list<int> x;
    x.push_back(5);
    x.push_back(1);
    x.push_back(2);
    x.push_front(3);
    x.push_front(6);

    // x.sort(); // Ascending order sorting
    x.sort(greater<>()); // descending order sorting

    for(int i: x)
        cout<< i << endl;

    return 0;
 }