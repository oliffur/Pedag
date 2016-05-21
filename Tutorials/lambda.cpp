#include <iostream>
using namespace std;

// this is a function that takes two ints and returns a double:
double average1(int num1, int num2);

// this is a pointer to a function that takes 2 ints and returns a double
double (*average2)(int, int);


double average1(int num1, int num2){
    return (0.5)*(num1 + num2);
}

void averages(){
    // function pointers are converted to bool because there's an infinite
    // amount of them
    cout << &average1;
    
    // the two below mean the same thing
    average2 = &average1;
    average2 = average1;
    
    // the two below work as you would expect and actually do the same thing
    cout << average2(1,2) << endl;
    cout << (*average2)(1,2) << endl;
    
    return;
}

// with a lambda function, you do not even need to explicitly define
// your first function before setting it to the second:

double (*average3)(int, int) = \
    [](int num1, int num2) -> double {return 0.5*(num1 + num2);};

void averages_v2(){
    cout << average3(1,2) << endl;
}

// lambdas can 'capture' variables from outside the function declaration,
// which is a feature functions do not provide:
void capture1(){
    int intValue = 42;
    double doubleValue = 3.14;
    cout << [intValue, doubleValue](int num1) -> double{
        return intValue + doubleValue + num1;
    } << endl;
}

// the way the compiler implements this is shown below.
void capture2(){
    int intValue = 42;
    double doubleValue = 3.14;
    class lambdaFunction{
        public:
        lambdaFunction(int intValue_, double doubleValue_): intValue(intValue_), doubleValue(doubleValue_){}
        void operator() const{
            //???
        }
        private:
        int intValue;
        double doubleValue;
    };
    lambdaFunction myFunc(intValue, doubleValue);
    myFunc();
    intValue++;
    myFunc();
    intValue++;
    myFunc();
}

// note that it store a *copy* of the captured variables; if these
// variables change, the variable in this compiler will not change
void capture3(){
    int intValue = 42;
    double doubleValue = 3.14;
    auto func =  [intValue, doubleValue](int num1) -> double{
        return intValue + doubleValue + num1;
    };
    cout << func << endl;
    intValue++;
    cout << func << endl;
    intValue++;
    cout << func << endl;
}

// to modify the value of captured variables or react to them, pass them by
// reference:
void capture4(){
    int intValue = 42;
    double doubleValue = 3.14;
    auto func =  [&intValue, &doubleValue](int num1) -> double{
        intValue++;
        return intValue + doubleValue + num1;
    };
    cout << func << endl;
    cout << intValue << endl;
    cout << func << endl;
    cout << intValue << endl;
    cout << func << endl;
}

// the shortcuts for the above are [=] for all variables in the same 
// scope by value and [&] for all variables in the same scope by
// reference

int main(){
    
    cout << func(1);
    
    return 0;
}

