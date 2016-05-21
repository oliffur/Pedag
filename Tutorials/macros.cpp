#include <stdio.h>
#include <iostream>

#define CALL(function) { \
    cout << #function << endl;\
    function();\
}

#define SECOND_FUNC(a, b,...) (a+b)

using namespace std;

#define CONS 5+6
void constantExample(){
    cout << CONS << endl;
}

#define FIRST_FUNC(a, b) (a+b)
void functionExample(){
    cout << FIRST_FUNC(7,8) << endl;
    cout << FIRST_FUNC('a','b') << endl;
    // if we wrote this as a normal function we would have to write two
    // versions, one for chars and one for ints
}

int main(){
    
    CALL(constantExample);
    

    
    return 0;
}
