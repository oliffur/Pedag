/* A stack class that does error checking
 * 
 *
 */



#include <iostream>

using namespace std;

template <typename T>
class MyStack{
private:
    // an array that holds the elements of the stack
    T* stackArray;
    
    // an integer that keeps track of the size of the stack;
    // changes with pushes and pops
    int sizeOfStack;
    
    // keeps track of the allocated memory for the stack (on the heap)
    int maxAllocMemory;
    
    // function for reallocating memory for stack
    // does not need to be visible to the user
    void resizeMemory(int newAllocMemory);
public:
    
    // push function
    void push(T pushee);
    
    
    T pop();
    
    // base constructor with no arguments
    MyStack(){
        stackArray = new T[10];
        sizeOfStack = 0;
        maxAllocMemory = 10;
    }
    
    /* :( doesn't work... coding error or compiler error?
    // constructor with initializer list
    MyStack(const initializer_list<T> &initList){
        stackArray = new T[10];
        sizeOfStack = 0;
        maxAllocMemory = 10;
        for (auto elem: initList) this.push(elem);
    }
    */
    
    // prints information about the array
    void printInfo(){
        cout << "stack size: " << sizeOfStack << endl;
        cout << "[ ";
        for (int i = 0; i<sizeOfStack; i++){
            cout << stackArray[i] << " ";
        }
        cout << "]" << endl;
        cout << "allocated memory: " << maxAllocMemory << endl;
    }
    
    // destructor; deletes memory on heap
    ~MyStack(){
        delete stackArray;
    }
};

// pushes an element
template <typename T>
void MyStack<T>::push(T pushee){
    // reallocates memory if memory is full
    if (sizeOfStack == maxAllocMemory) {
        resizeMemory(maxAllocMemory*2);
    }
    stackArray[sizeOfStack] = pushee;
    sizeOfStack++;
}

// pops an element and returns it to the user
template <typename T>
T MyStack<T>::pop(){
    if (sizeOfStack==0){
        // throw error
    }
    else{
        sizeOfStack--;
        
        // resizes memory smaller if size of stack is less than a quarter
        // of allocated memory; subtracts that number by 1 to avoid thrashing
        // when array size is small (between 0 and 1)
        if (sizeOfStack < 0.25*maxAllocMemory - 1){
            resizeMemory(maxAllocMemory/2);
        }
        return stackArray[sizeOfStack];
    }
}

// resizes the memory allocation on the heap to newAllocMemory;
// copies the current stack array to a new stack array with less/more memory
template <typename T>
void MyStack<T>::resizeMemory(int newAllocMemory){
    maxAllocMemory = newAllocMemory;
    T* stackArrayCpy = stackArray;
    stackArray = new T[maxAllocMemory];
    std::copy(stackArrayCpy,stackArrayCpy+sizeOfStack,stackArray);
    // deallocates memory on heap from old array
    delete stackArrayCpy;
}
    


int main(){
    MyStack<int> olives = MyStack<int>();
    olives.printInfo();
    olives.push(3);
    olives.printInfo();
    olives.push(4);
    olives.printInfo();
    olives.push(5);
    olives.printInfo();
    cout<<olives.pop()<<endl;
    olives.printInfo();
    for (int i = 0; i<10; i++){
        olives.push(6);
    }
    olives.printInfo();
    for (int i = 0; i<17; i++){
        olives.push(7);
    }
    olives.printInfo();
    for (int i = 0; i<23; i++){
        olives.pop();
    }
    olives.printInfo();
        for (int i = 0; i<23; i++){
        olives.pop();
    }
    olives.printInfo();
}
