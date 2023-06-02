#include <iostream>
#include <expected>
#include <stdexcept>
#include <string>
#include <cctype>
using namespace std;

expected<int, runtime_error> string_to_int(const string& str) {
    int result = 0;
    for (int i = 0; i<str.size(); i++) {
        char current_char = str[i];
        if (!isdigit(current_char)) {
            return unexpected<runtime_error>{"Detected non-digit char"};
        }
        int current_digit = current_char - '0';
        result = result*10 + current_digit;
    }
    return result;
}

int main(){
    // cout<<string_to_int("1246")<<endl;
    auto result = string_to_int("1234");
    cout << boolalpha << result.has_value() << endl;
    if (result.has_value()){
        cout << result.value() << endl;
    }
    else {
        cout << result.error().what() << endl;
    }
}