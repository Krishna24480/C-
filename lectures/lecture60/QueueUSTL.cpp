#include <iostream>
#include <queue>
using namespace std;

int main()
{

    queue<int> q1,q2;

    q1.push(99);
    q1.push(77);
    q1.push(55);
    q1.push(33);
    q1.push(11);

    q2.push(88);
    q2.push(66);
    q2.push(44);
    q2.push(22);
    q2.push(02);

    cout << q1.size() << endl;

    cout << q1.front() << endl;

    q1.pop();

    cout << q1.front() << endl;

    cout << q1.back() << endl;

    cout << q1.size() << endl;

    cout << q1.front() << endl;

    q1.swap(q2);

    cout <<"Q1 front: "<< q1.front() << endl;

    cout << "Q2 front: "<< q2.front() << endl;

    if(q1.empty()){
        cout << "Q1 is Empty" << endl;
    }
    else
    {
        cout << "Q1 is Not Empty" << endl;
    };

    return 0;
}