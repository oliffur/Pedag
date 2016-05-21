#include <stdio.h>
#include <iostream>
using namespace std;
    
// constexpr: Evaluate at compile time
// const: Do not modify in this scope
//
// X const: whatever X is referring to should not change in this scope;
// specifically: if we are addressing a part of memory using 'X', then we can't
// modify it.
//
// If used at beginning of declaration, const X can be used as a synonym for
// X const. E.g. "const int myInt;" would be the same as "int const myInt;"
// 
// I will use the former notation for now because it is more consistent
    
 
// a variable declared as const cannot be changed
void example1(){
   int const var1 = 2;

    // error! var1 was declared const, we cannot change its value
    var1 = 3;
    
    // error! var2 cannot be uninitialized because it cannot be modified after  
    int const var2;
       
    return;
}

// demonstrating illegal dereferencing of const data
void example2(){

    int myArray[10];
    int const *arr1 = myArray;
    
    // error! we address memory through the pointer arr1 so we cannot change it
    arr1[5] = 6;
        
    // error! even though arr1[11] wasn't technically set aside for the array,
	// we are addressing it through arr1, so this is an error
    arr1[11] = 12;
    
    int myArray2[13]; // OK
    
    int const *arr1 = myArray1; // OK
    
    // OK; we are not changing any type of memory, just changing the pointer;
	// the program would error if we changed (*arr1), the memory addressed by
	// arr1 which is declared as constant. Here we are leaving that memory
	// alone and changing the pointer value arr1 to another memory
    arr1 = myArray2;
    
    return;
}

// demonstrating const pointers
void example3(){
    
    int myArray1[10];
    int myArray2[13];
    
    int *const arr1 = myArray1;

    // error! pointer declared as constant so we cannot change where it points
    arr1 = myArray2;
    
    // OK; pointer does not change even though the value it points to changes
    arr1[5] = 6;
    
    return;
}

// some tricky referencing examples
void example4(){
    
    int const var1 = 3;
    
    // OK
    int const *var2 = &var1;
    
    // OK
    int var3 = var1;
    
    // error! var4 does not point to a constant memory so there is a risk we
	// may try to change the constant memory at var1 through var4.
    int *var4 = &var1;
}

// demonstrating passing constant variable in a function
void example5(int const var1, int const & var2){
    
    // error! var1 was declared as const and cannot be changed
    var1 += 4;
    
    // error! similar
    var2++;
}

// demonstrating passing constant variable in a function
int example5(int const var1){
    int var2 = var1 + 4;
    return var2;

    // error! var1 was declared as const and cannot be changed
    var1 += 4;
    return var1;
}

// demonstrating const member functions
class MyClass{
    int var1;
    mutable int var2;
    void example6() const{
        // error! const member functions cannot edit members of their class;
		// this is implimented with a const 'this' pointer
        var1++;
        
        var2++; // OK; declared mutable
    }
    
    // error! const member function cannot return a non-const type!
    int example7() const{
        // code
    }
    
    // OK
    const int example8() const{
        // code
    }
    
    // OK! overloaded function that is a non-const version of the above fn; the
	// program will choose which to use based on the function details
    int example8(){
        // code
    }
};

// const vs constexpr
void example9(){
	const int a = 17;
	int b = 17;

	constexpr double c = 1.4*a; // OK! a is a constant known at compile time
	constexpr double d = 1.4*b; // error! b is not constant expression
	const double e = 1.4*b; // OK! evaluated as a constant at run time
	
	// the following is legal and returns a constant expression if the argument
	// passed in is a constexpr; otherwise it does NOT return a constexpr
	constexpr double square(double f){return f*f;}

}
