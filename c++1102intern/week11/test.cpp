/*
Author: Xiaoyo
id: 01057020
time: 2022/05/26
*/
#include "iostream"
#include "Mystring.h"
using namespace std;

/*
void testMyString(){
    MyString str1("String"), str2("Test String 2"), str3(str1);
    cout << "str1 is " << str1 << endl;
    cout << "str1 is: " << str1 << endl;
    cout << "str2 is: " << str2 << endl;
    cout << "str3 is: " << str3 << endl;
    cout << "The number of MyString instances is: " << MyString::GetCount() << endl;

    /////////////////////////////////////////////////////////

    cout << "Give one word " << endl;
    cin >> str1; // from stdin "this is a test line"
    cout << "str1 is: " << str1 << endl;
    /////////////////////////////////////////////////////////

    str2 = str1;
    cout << "str2 is: " << str2 << endl;

    /////////////////////////////////////////////////////////

    str3 += str1;
    cout << "str3 is: " << str3 << endl;

        /////////////////////////////////////////////////////////

    cout << "str3 is: ";
    for (unsigned i = 0; i < str3.length(); i++) cout << str3[i];
    cout << endl;

    for (unsigned i = 0; i < str3.length(); i++) str3[i] = 'a' + i;
    cout << "str3 is: " << str3 << endl;

    /////////////////////////////////////////////////////////

    cout << "str1 is: " << str1 << endl;
    cout << "str2 is: " << str2 << endl;
    cout << "str3 is: " << str3 << endl;
    cout << "Compare str1 == str2 is: " << (str1 == str2) << endl;
    cout << "Compare str1 == str3 is: " << (str1 == str3) << endl;
    cout << "Compare str1 != str2 is: " << (str1 != str2) << endl;
    cout << "Compare str1 != str3 is: " << (str1 != str3) << endl;
}

void testMystringDerived(){
    Mystring_Derived st1("NTOU");
    cout << (Mystring)str1 << endl;
    cout << static_cast<Mystring>(str1) << endl;
    cout << *(dynamic_cast<Mystring*>(&str1)) << endl;
}//*/

int main(){
    // testMyString();
}