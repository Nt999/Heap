//
// Created by hieu- on 14.05.2020.
//
#include <iostream>
#include "heap.h"
#include <cstring>
using namespace std;

template<typename T>
Heap<T>::Heap(int *values) {


}

template<typename T>
Heap<T>::Heap(int initializeSize) {
    last = 0;
    size = initializeSize;
    values = new T[size];      //Speicher für beliebiges Array der Größe size
}

template<typename T>
Heap<T>::~Heap<T>() {
    delete values;
}

template<typename T>
bool Heap<T>::isEmpty() {                 //static deshalb private
    return last == 0;
}
template<typename T>
bool Heap<T>::isFull() {
 return last == size;                     //static deshalb private
}

template<typename T>
T Heap<T>::minimum() {
    if (isEmpty()){
        throw "heap ist leer";
    }
    return values[0];

}

template<typename T>
int Heap<T>::find(T x) {
    int i;

    for(i=0;i < last;i++)               //static deshalb private
    if (values[i] == x)
        return i;
    return -1;

}



template<typename T>
void Heap<T>::increaseSize() {
    size *= 2;
    T * temp = new T[size];   // neues array mit neuer größe
    for (int i = 0; i < size/2; i++) // Alle alten Werte übernehmen
        temp[i] = values[i];

    delete[] values; // Speicher vom alten Array wieder freigeben
    values = temp; // Der 'values' Pointer zeigt jetzt auf unser neues Array
}

template<typename T>
void Heap<T>::downHeap(int pos) {
    char end = 0;

    while (!end && pos < last){
        int min = pos;
        int l = 2 * pos +1;
        int r = 2 * pos +2;

        if( l < last && values[pos] > values[l])
            min = l;
        if( r < last && values[min] > values[r] )
            min = r;

        if(min == pos)
            end = 1;
        else{
            //swap(min,pos)
            int t = values[min];
            values[min] = values[pos];
            values[pos] = t;
            pos = min;
        }
    }

}


template<typename T>
void Heap<T>::upHeap(int pos) {
    char end = 0;
    while (!end && pos > 0){
        int v = (pos -1) /2;
        if(v >= 0 && values[v] > values[pos]){
            int t = values[pos];
            values[pos] = values[v];
            values[v] = t;
            pos = v;
        } else end -1;
    }

}

template<typename T>
T Heap<T>::insert(int val) {
    if (find(val)!= -1)
        return 1;
    if(isFull())
        increaseSize();

    values[last] = val;
    last += 1;
    upHeap(last -1);
    return 0 ;
}

template<typename T>
T Heap<T>::extractMin() {
    if(isEmpty())
        return 0;

    last -= 1;
    values[0] = values[last];
    downHeap(0);
    return 1;
}

template<typename T>
T* Heap<T>::toString() {
    char *res = new T[last];

    for(int i = 0; i < last;i++){
        char tmp[12];
        if (i > 0)
            strcat(res, ", ");
        sprintf(tmp, "%d", values[i]);
        strcat(res, tmp);
    }
    return res;

    }





