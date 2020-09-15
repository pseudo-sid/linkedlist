#include<iostream>
#include<list>
#include<string>

using namespace std;
int main(){
    list<int> l1;
    l1.push_front(1);
    list<string> l2({"apple","guava", "mango", "banana"});
    l2.push_back("pineapple");
    cout << l2.front()<<endl;
    l2.pop_front();
    for(auto s: l2)
        cout << s <<"->";
    cout << endl;
    return 0;
}