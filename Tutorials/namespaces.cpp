#include <iostream>

using namespace std;

/*
// foo.h
void doSomething(){
    // code
}

// goo.h
void doSomething(){
    // code
}

// error: name collision
// by default, foo and goo and main and global variables reside
// in the global namespace, accessed by ::, e.g. ::foo()
*/


// foo.h
namespace Foo{
    int doSomething(){
        cout << "f";
        return 0;
    }
}

// goo.h
namespace Goo{
    int doSomething(){
        cout << "g";
        return 0;
    }
}

// when a function or object is called, the compiler first looks
// in the namespace it is in and then checks all the namespaces it
// is 'using' and then moves to parent namespaces

// to restrict a global variable or function so that it can 
// only be accessed within its own file, use the 'static' keyword
static int s_x;
static int s_fn();

// to signify that a variable or function can be used by other
// files, we use the 'extern' keyword, which is also the default:
extern int g_z;
extern double g_fn2();

// because variables are initiated when they are declared and
// functions are not, we have the following cases:

/*
// file A:
int g_x;
// file B:
int g_x;
// error! g_x would be initiated twice
*/

// file A:
int g_x;
// file B:
extern int g_x;
// OK! the extern variable is a forward declaration and refers
// to the first variable in file A

// file A:
extern int g_x;
// file B:
extern int g_x;
// OK! both forward declarations

// file A:
int g_fn();
// file B:
int g_fn();
// OK! with the understanding that g_fn() will be implemented
// later; these are 2 forward declarations

// a file can only have 1 definition, but can have multiple declarations
// declarations must match: for example, the following yields an error:
extern int inconsistent;
extern short inconsistent;

int main(){
    
    return 0;
}
