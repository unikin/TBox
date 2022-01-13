#include "shape.h"
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

bool cmp_RECT(const unique_ptr<Rectangle> & a, const unique_ptr<Rectangle> & b){
    if(a->area > b->area) return true;
    return false;
}
bool cmp_CIR(const unique_ptr<Circle> & a, const unique_ptr<Circle> & b){
    if(a->area > b->area) return true;
    return false;
}

int main(){
    vector<unique_ptr<Rectangle>> rvec; vector<unique_ptr<Circle>> cvec;
    while(true){
        string cmd; cin >> cmd;
        transform(begin(cmd), end(cmd), begin(cmd), [](char& c){return tolower(c);});
        Command c = getCommand(cmd);
        switch(c){
            case RECT:
                rvec.emplace_back(make_rectangle());
                break;
            case CIRCLE:
                cvec.emplace_back(make_circle());
                break;
            case CLEAR:
                rvec.clear(); cvec.clear();
                break;
            case QUIT:
                return 0;
            case INVALID:
                cout << "Invalid Command" << '\n';
                break;
            case PRINT:{
                for_each(rvec.begin(), rvec.end(), [](auto& n){cout << "Rectangle:" << '\t' << n->width << '\t' << n->height << '\t' << n->area<<endl;});
                for_each(cvec.begin(), cvec.end(), [](auto& n){cout << "Circle:" << '\t' << n->radius << '\t' << n->area <<endl;});
            }
                break;
            case SORT:
                std::sort(rvec.begin(), rvec.end(), cmp_RECT);
                std::sort(cvec.begin(), cvec.end(), cmp_CIR);
                break;
            case SUM:{
                int r_sum, c_sum, sum_sum;
                r_sum = std::accumulate(rvec.begin(), rvec.end(), 0, [](int sum, const unique_ptr<Rectangle>& cur){return sum+cur->area;});
                c_sum = std::accumulate(cvec.begin(),cvec.end(), 0, [](int sum, const unique_ptr<Circle>& cur){return sum+cur->area;});
                sum_sum = r_sum + c_sum;
                cout << sum_sum << endl;
            }
                break;
            default:
                cout << "Invalid Command" << endl;
                break;

        }
    }

}