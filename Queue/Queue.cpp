 #include<iostream>
 #include<queue>
 #include<string>
 using namespace std;

class Company {
private:
    string name;
    int day,month,year;

public:
    Company(string n, int d, int m, int y){
        name = n;
        day = d;
        month = m;
        year = y;
    }

    // check the yearly-subscription if it ends after one year 
    bool check(int d, int m, int y){
        if(d == day && m == month && y == year + 1)
            return true;
        else
            return false;
    }  

    string print(){
        return name;
    }  
};

 int main(){
    queue<Company> c;
    c.push(Company("Ahmed", 1, 1, 2019));
    c.push(Company("John", 2, 1, 2019));
    c.push(Company("Aly", 3, 1, 2019));
    c.push(Company("Omar", 3, 1, 2019));
    c.push(Company("Mansour", 3, 1, 2019));
    c.push(Company("Magdy", 4, 1, 2019));

    while(!c.empty()){
        cout<<"Enter day:month:year : ";
        int d,m,y;
        cin>>d>>m>>y;
        flag:
        if(c.front().check(d,m,y)){
            cout<<"Deleting ";
            cout<<c.front().print()<<endl;
            c.pop();
            // We handled this statement because may users might be registered in the same day
            goto flag;
        }
    }
    return 0;
 }