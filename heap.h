//
// Created by hieu- on 14.05.2020.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H
template<typename T>
class Heap{
public:
    Heap(int initializeSize);
    T insert(int val);
    T minimum();
    T extractMin();
    T* toString();
    ~Heap();
    Heap(int *values);





private:
    bool isEmpty();
    bool isFull();
    void increaseSize();
    int size,last;   // größe des heaps,  letztes element
    T * values; //array für die werte des heaps
    int find(T x);
    void downHeap(int pos);
    void upHeap(int pos);






};

#endif //HEAP_HEAP_H
