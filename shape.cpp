#include "shape.h"
#include <iostream>
using namespace std;

unique_ptr<Rectangle> make_rectangle(){
    int w, h, a;
    cin >> w >> h;
    a = w*h;
    auto Rec = make_unique<Rectangle>();
    Rec->width = w; Rec->height = h; Rec->area = a;
    return Rec;
}
unique_ptr<Circle> make_circle(){
    int r;
    double a;
    cin >> r;
    a = r*r*3.14;
    auto Cir = make_unique<Circle>();
    Cir->radius = r; Cir->area = a;
    return Cir;
}
Command getCommand(const string& command){
    Command cmd;
    if (command == "rect") cmd = RECT;
    else if(command == "circle") cmd = CIRCLE;
    else if(command == "print") cmd = PRINT;
    else if(command == "sort") cmd = SORT;
    else if(command == "sum") cmd = SUM;
    else if(command == "quit") cmd = QUIT;
    else if(command == "clear") cmd = CLEAR;
    else cmd = INVALID;
    return cmd;
}
