
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int arr[] = {10,20,30,40,50};
    vector<int> *v = new vector<int>(arr,arr+5);

    make_heap(v->begin(), v->end());
    cout << "Initial heap max: " << v->front() << endl;

    pop_heap(v->begin(), v->end());
    v->pop_back();
    cout << "Max heap after pop: " << v->front() << endl;

    v->push_back(99);
    push_heap(v->begin(), v->end());
    cout << "Max heap after push: " << v->front() << endl;

    sort_heap(v->begin(), v->end());
    cout << "Final sorted range: ";
    for (unsigned int i = 0; i < v->size(); i++)
        cout << ' ' << v->at(i);
    cout << endl;

    delete v;
    return 0;
}
