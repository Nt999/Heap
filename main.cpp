#include <iostream>
#include "heap.cpp"

using namespace std;

int main() {
    Heap<int> name(12);
    try {
        name.insert(12);
        cout << name.minimum() << endl;
        name.insert(12);
        name.extractMin();
        cout << name.minimum() << endl;
        //name.toString();


    } catch (exception& x){
        cout << x.what() << endl;
    }
    catch (const char* e){
        cout << e << endl;

    }

    return 0;
}
