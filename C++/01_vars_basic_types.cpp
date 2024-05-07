#include <iostream>
using namespace std;

extern const int b = 10;

int main() {
    //  C++ has some built-in primitive types, and a special void
    // Each of the arithmetic types has an "unsigned variant"
    unsigned int x = (1<<31);
    cout << x << endl;
    cout << (int) x << endl; // this does a type conversion
    cout << *(int *)&x << endl; // this reinterprets the bits
    // do the same thing as they are the same operation in the legal range
    // notice that 1<<31 becomes -ve in int
    // also notice unsigned subtraction is whack
    unsigned u1 = 42, u2 = 10;
    cout << u2 - u1 << endl;
    // make sure you dont put dumb conditions like u >=0, loop may never terminate
    // literals are actual values written inside the program
    // could be integer, floating point, character or string
    // -42 is not a -ve literal, it is unary - on literal 42
    // string literals are arrays of const chars
    cout << (int)"A"[1] << endl; // last character is a \0
    // type of a literal can be overriden by correct prefix/suffix
    // use U, L, LL, F suffix for numbers
    bool *z;
    z = new bool(true);
    cout << *z << endl;
    // nullptr is a pointer literal
    // variable definition looks like:
    int sum=0, value;
    // initialization is when a variable is given a value when it is created. sum was initialized above.
    // many forms of initialization:
    int way1 = 0;
    int way2 = {0};
    int way3{0};
    int way4(0);
    // 2 and 3 are called list initialization
    // they throw error when loss of precision might happen
    // vraiables defined oustdie any function scope are initialized to zero
    // those inside are uninitialized
    // error to try and copy or access this value
    // user defined class itself determines what happens on initialization
    // to enable seperate compilation, we might declare variables without defining them
    extern int babu;
    // variables may be decalred mulitple times
    // a scope is delimited by curly braces
    // names are visible between declaration and end of scope
    // name lookup almost always follows LEGB
    // compound types use recipes to build newer types, recipes include pointer and reference
    // lval references are like aliases for existing objects
    int iVal = 2;
    int &iVal2 = iVal; // initializer is needed
    iVal2 = 4;
    cout << iVal << endl; 
    // the type of the reference and the type of the object must match exactly
    // the reference must be bound to an expression that evaluates to an lval
    // a pointer stores the hardware address of an object
    // may not ALWAYS do so, could be a sentinel or some shit
    // & takes the address of objects, and * dereferences pointers
    // there are three ways to generate a nullptr:
    int *p1 = nullptr;
    int *p2 = NULL;
    int *p3 = 0;
    // preprocessor runs before the compiler and does lexical substitutions
    // assignment to a reference changes the object
    // assignment to pointer changes the pointer variable
    // dereference it to change the object
    // pointers are equal if they hold the same address
    // void* is a gawd pointer type
    // type of object at address is unknown
    // could define pointer to pointer, reference to pointer, but no pointer to reference
    // can define variable as unchangable by using const
    const int a = 3;
    // uncomment to get error
    // a = 5;
    // for same reason uninitialized const is error
    // const int k;
    // you can copy const object to nonconst, its fine
    // to avoid multiple redefinitions of a const object and allow compiler optimization,
    // const type global objects are by default local to the file
    // if you want to share (which means initializer is nonconst),
    // put extern on definition also:
    // ref line 4
    // reference to const type object looks like
    const int c1 = 10;
    const int &r1 = c1;
    // cannot use r1 or c1 to change the object
    // also illegal:
    // int &r2 = c1;
    // a reference to a const can be initialzied from an expression that can be converted to said type
    double d_ = 3.14;
    const int &i_ = d_;
    d_ = 5.86;
    cout << i_ << endl; // value didnt get tracked (!)
    int i_bar = 3;
    const int &d_bar = i_bar;
    i_bar = 7;
    cout << d_bar << endl; // it does now
    // exact same stuff with pointers to const, written as
    // pointers to const could point to non const objects
    int * one;
    double * two = &d_;
    // one = two; // notice error here...
    // can have const pointers themselves
    int *const i_p_last = one;
    // in general, if the object itself is const we say top level const
    // if what it wraps around, the content, is const, we csay low level const
    // during copy, top-level consts are ignored
    // low-level consts are never ignored, they should have the same qualifications
    // else, nonconst to const is also usually okay
    int *a1;
    const int *ca1 = a1;
    // int *a2 = ca1; // OnO
    // a constant expression is one whose value can be determined at compile time and cannot change
    // eg: any literal
    // you can ask the compiler to confirm if the initializer is a const expression as:
    constexpr int mf = 20;
    constexpr int lim = mf+1;
    // user defined classes are not literal types, so cannot be used in constexpr definitions
    // such variables are automatically const
    // constexpr pointers could be from nullptr, 0 or objects that "cannot change address"
    // variables inside a function dont have a constant address, globals do
    // "static" objects too
    // here the const-ness is top level:
    constexpr int *p = nullptr;
    // type aliasing can be thorugh
    typedef double wages, *p_type;
    // or as
    using SI = int;
    // note that below is a top-level const:
    const p_type bruh = nullptr;
    // you can ask compiler to "deduce" the type
    auto item = mf + 7;
    // look at this error
    // auto v1 = 0, v2 = 8.9;
    // the type that auto infers is not the same as that of initializer in all respects:
    int &eg1 = i_bar;
    auto eg2 = eg1; // takes int and not int&
    // auto also ignore top level consts
    // add constness and & explicitly in the declaration:
    const auto &eg3 = i_bar;
    // note that you can point a const reference to a literal
    const int &eg4  = 7;
    // pointers and stuff on top of auto should match
    auto *a_p = &i_bar;
    // if you want to use an expressions type as a type elsewhere:
    decltype(d_bar) d_bar_bar = 4; // include top-level constness and reference-ness
    // decltype can give cranky outputs on expressions, if they are lval the idiot will give reference type
    // even more crazily, if the variable was int:
    int ono;
    // decltype((ono)) ono2; // lmaoded
    return 0;
}