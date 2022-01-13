#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;


int main(){
    int count_int, count_long, count_float, count_double;
    count_int = count_long = count_float = count_double = {0};
    string cmd;
    while(1){
        cin >> cmd;
        std::transform(begin(cmd), end(cmd), begin(cmd), [](unsigned char c){return std::tolower(c);});
        if(cmd == "int"){
            cout << numeric_limits<int>::max() << " " << numeric_limits<int>::min() << endl;
            count_int++;
        }
        else if(cmd == "long"){
            cout << numeric_limits<long>::max() << " " << numeric_limits<long>::min() << endl;
            count_long++;
        }
        else if(cmd == "float"){
            cout << numeric_limits<float>::max() << " " << numeric_limits<float>::min() << endl;
            count_float++;
        }
        else if(cmd == "double"){
            cout << numeric_limits<double>::max() << " " << numeric_limits<double>::min() << endl;
            count_double++;
        }
        else if(cmd == "quit"){
            break;
        }
        else{
            cout << "Invalid Command" <<endl;
        }

    }
    cout << "== the number of types ==" << endl;
    cout << "int: " << count_int << endl;
    cout << "long: " << count_long << endl;
    cout << "float: " << count_float << endl;
    cout << "double: " << count_double << endl;

    return 0;
}