#include <iostream>

using namespace std;

template <typename T>
class MyQueue{
private:
    // an array that holds the elements of the queue
    T* queueArray;
    
    // variables that keep track of the head and tail of the queue;
    // changes with enQs and deQs
    int queueHead;
    int queueTail;
    
    // keeps track of the allocated memory for the queue (on the heap)
    int maxAllocMemory;
    
    // function for reallocating memory for queue
    // does not need to be visible to the user
    void resizeMemory(int newAllocMemory);
public:
    
    // enqueue and dequeue functions
    void enQ(T pushee);
    T deQ();
    
    // base constructor with no arguments
    MyQueue(){
        queueArray = new T[10];
        queueHead = 0;
        queueTail = 0;
        maxAllocMemory = 10;
    }
    
    /* :( doesn't work... coding error or compiler error?
    // constructor with initializer list
    MyQueue(const initializer_list<T> &initList){
        queueArray = new T[10];
        queueHead = 0;
        queueTail = 0;
        maxAllocMemory = 10;
        for (auto elem: initList) this.enQ(elem);
    }
    */
    
    int sizeOfQueue(){
        return (maxAllocMemory+(queueTail - queueHead)%maxAllocMemory)\
            %maxAllocMemory;
    }
    
    // prints information about the array
    void printInfo(){
        cout << "queue size: " << sizeOfQueue() << endl;
        cout << "queue head: " << queueHead << endl;
        cout << "queue tail: " << queueTail << endl;
        cout << "[ ";
        for (int i = queueHead; i%maxAllocMemory!=queueTail; i++){
            cout << queueArray[i%maxAllocMemory] << " ";
        }
        cout << "]" << endl;
        cout << "allocated memory: " << maxAllocMemory << endl;
    }
    
    // destructor; deletes memory on heap
    ~MyQueue(){
        delete queueArray;
    }
};

// pushes an element
template <typename T>
void MyQueue<T>::enQ(T pushee){
    // reallocates memory if memory is full
    if (queueHead == queueTail+1) {
        resizeMemory(maxAllocMemory*2);
    }
    queueArray[queueTail] = pushee;
    queueTail = (queueTail+1)%maxAllocMemory;
}

// pops an element and returns it to the user
template <typename T>
T MyQueue<T>::deQ(){
    if (queueHead == queueTail){
        // throw error
    }
    else{
        T temp = queueArray[queueHead];
        queueHead = (queueHead+1)%maxAllocMemory;
        
        // resizes memory smaller if size of queue is less than a quarter
        // of allocated memory; subtracts that number by 1 to avoid thrashing
        // when array size is small (between 0 and 1)
        if (sizeOfQueue() < 0.25*maxAllocMemory - 1){
            resizeMemory(maxAllocMemory/2);
        }
        return temp;
    }
}

// resizes the memory allocation on the heap to newAllocMemory;
// copies the current queue array to a new queue array with less/more memory
template <typename T>
void MyQueue<T>::resizeMemory(int newAllocMemory){
    T* queueArrayCpy = queueArray;
    queueArray = new T[newAllocMemory];
    if (queueTail >= queueHead){
        std::copy(queueArrayCpy+queueHead,\
                  queueArrayCpy+queueTail,queueArray);
        int temp = sizeOfQueue();
        queueHead = 0;
        queueTail = temp;
    }
    else{
        std::copy(queueArrayCpy + queueHead, queueArrayCpy + maxAllocMemory,\
                 queueArray + newAllocMemory -(maxAllocMemory - queueHead));
        std::copy(queueArrayCpy, queueArrayCpy + queueTail,\
                  queueArray);
        queueHead = newAllocMemory - (maxAllocMemory - queueHead);
    }
    maxAllocMemory = newAllocMemory;
    // deallocates memory on heap from old array
    delete queueArrayCpy;
}
    

int main(){
    MyQueue<int> olives = MyQueue<int>();
    olives.printInfo();
    olives.enQ(3);
    olives.printInfo();
    olives.enQ(4);
    olives.printInfo();
    olives.enQ(5);
    olives.printInfo();
    cout<< olives.deQ() <<endl;
    olives.printInfo();
    for (int i = 0; i<6; i++){
        olives.enQ(6);
    }
    olives.printInfo();
    olives.enQ(6);
    olives.printInfo();
    olives.enQ(6);
    olives.printInfo();
    
    for (int i = 0; i<17; i++){
        olives.enQ(7);
    }
    olives.printInfo();
    olives.deQ();
    olives.printInfo();
    for (int i = 0; i<10; i++){
        olives.deQ();
    }
    olives.printInfo();
    for (int i = 0; i<13; i++){
        olives.deQ();
    }
    olives.printInfo();
    for (int i = 0; i<23; i++){
        olives.deQ();
    }
    olives.printInfo();
}
