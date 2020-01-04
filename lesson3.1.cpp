#include<iostream>
#include<cmath>
using namespace std;


class Figure{
public:
    virtual double area() = 0;
};


class Parallelogram : public Figure{
protected:
    double a;
    double b;
public:
    Parallelogram(double strA, double strB) : a(strA), b(strB){}
    double getC() const{
        return a;
    }
    double getD() const {
        return b;
    }
};


class Rectangle : public Parallelogram {
public:
    Rectangle(double strA, double strB) : Parallelogram(strA, strB){}
    double area(){
        return a * b;
    }
};

class Square : public Parallelogram {
public:
    Square(double str) : Parallelogram(str, str){}
    double area(){
        return a * a;
    }
};

class Rhombus : public Parallelogram{
private:
    double h;//Высота ромба
private:
    Rhombus(double str, double Rh) : Parallelogram(str, str), h(Rh){}
    double getH() const {
        return h;
    }
    double area(){
        return a * getH();
    }
};

class Circl : public Figure{
private:
    double r;
public:
    Circl(double circlR) : r(circlR){}
    double getR() const {
        return r;
    }
    double area(){
        return M_PI * getR() * getR();
    }
};

void printArea(Figure &fig){
    cout << fig.area() << endl;
}


int main (int args, char** argv){
    Rectangle rect1(20, 2);
    Square squ1(20);
    Circl circ1(20);
    printArea(circ1);
    printArea(squ1);
    printArea(rect1);
    return 0;
}
