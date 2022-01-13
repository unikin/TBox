#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <regex>

using namespace std;

int main() {
    string str;
    map<string, size_t> words;

    while(cin>>str && str!="^"){
        auto filtered {regex_replace(str, regex("[.|,|:|;|]"), "")};

        auto search = words.find(filtered);
        if(search != words.end())
            ++words[filtered];
        else
            words.insert({filtered, 1});

    }
    int sum=0;
    for(const auto &[word, count]: words){
        sum += (int)count;
    }
    cout << "words: " << sum << endl;
    string answer;
    while(true){
        cin >> answer;
        if(answer == "QUIT") {
            cout << "Bye!" << endl;
            break;
        }
        else
            cout << answer << ": " << words[answer] << endl;
    }

    return 0;

}