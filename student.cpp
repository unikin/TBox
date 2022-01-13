#include "student.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>


using namespace std;

unique_ptr<StudentInfo> make_student(){

    unique_ptr<StudentInfo> si {new StudentInfo};
    double sum=0;
    string str;
    cin >> str;

    for(int & score : si->scores){
        cin >> score;
    }
    for(int score : si->scores){
        sum += score;
    }
    si->name = str;
    si->sum = (int)sum;
    si->average = sum/SUBJECT_NO;

    return si;
}
void print(const StudentInfo& si){
    cout << si.name << "\t";
    for(int score : si.scores){
        cout << score << "\t";
    }
    cout << si.sum << "\t" << si.average <<endl;
}
void print_all(const vector<unique_ptr<StudentInfo>>& vec){
    for(const unique_ptr<StudentInfo>& it : vec){
        print(*it);
    }
}
