#include<iostream>
#include<cmath>
using namespace std;

int comonDivider(int a, int b){
    if(a == 0 || b ==0) return 1;
    if(a <= b){
        if(b % a == 0) return a;
        for (int i = a;i > 0;i--) {
            if((a % i) == 0 && (b % i) == 0)
                return abs(i);
        }
        return 1;
    }
    else {
        if(a % b == 0) return b;
        for (int i = b;i > 0;i--) {
            if((a % i) == 0 && (b % i) == 0)
                return abs(i);
        }
        return 1;
    }
}
class Fraction{
private:
    int num;
    int divider;
public:
    Fraction(int newDividend, int newDivider) : num(newDividend), divider(newDivider){

    }
      int getNum() const {
          return num;
    }
      int getDivider() const {
          return divider;
      }
      void setFract(int nNum, int dividerN){
          setNum(nNum);
          setDivider(dividerN);
      }
      void setNum(int nNum){
          num = nNum;
      }
      void setDivider(int dividerN){
          if(!dividerN){
              cout << "Error! Division by zero" << endl;
              return;
          }
          divider = dividerN;
      }
      void showFract() const {
          cout << getNum() << "/" << getDivider();
      }
      //-------------------Перегрузка операторов
      Fraction operator-(){
          return Fraction (-getNum(), -getDivider());
      }
      Fraction operator* (const Fraction& fract){
          return Fraction ((getNum() * fract.getNum()), (getDivider() * fract.getDivider()));
      }
      friend Fraction operator+(const Fraction& fract1, const Fraction& fract2);
      friend Fraction operator-(const Fraction& fract1, const Fraction& fract2);
      friend Fraction operator*(const Fraction& fract1, const Fraction& fract2);
      friend Fraction operator/(const Fraction& fract1, const Fraction& fract2);
      friend bool operator==(const Fraction& fract1, const Fraction& fract2);
      friend bool operator!=(const Fraction& fract1, const Fraction& fract2);
      friend bool operator>(const Fraction& fract1, const Fraction& fract2);
      friend bool operator<(const Fraction& fract1, const Fraction& fract2);
      friend bool operator>=(const Fraction& fract1, const Fraction& fract2);//work
      friend bool operator<=(const Fraction& fract1, const Fraction& fract2);//work
};

Fraction operator+ (const Fraction& fract1, const Fraction& fract2){
    if(fract1.divider != fract2.divider){
        int sumNum = (fract1.num * fract2.divider) + (fract2.num * fract1.divider);
        int sumDiv = fract1.divider * fract2.divider;
        int comDiv = comonDivider(sumNum, sumDiv);
        return Fraction((sumNum / comDiv), (comDiv / comDiv));
    }
    return Fraction ((fract1.num + fract2.num), fract1.divider);
}

Fraction operator-(const Fraction& fract1, const Fraction& fract2){
    if(fract1.divider != fract2.divider){
            int sumNum = (fract1.num * fract2.divider) - (fract2.num * fract1.divider);
            int sumDiv = fract1.divider * fract2.divider;
            int comDiv = comonDivider(sumNum, sumDiv);
            return Fraction(sumNum / comDiv, sumDiv / comDiv);
        }
        return Fraction ((fract1.num - fract2.num), fract1.divider);
}

Fraction operator*(const Fraction& fract1, const Fraction& fract2){
    int nNum = fract1.num * fract2.num;
    int nDivider = fract1.divider * fract2.divider;
    int comDiv = comonDivider(nNum, nDivider);
    return Fraction((nNum / comDiv), (nDivider / comDiv));
}

Fraction operator/(const Fraction& fract1, const Fraction& fract2){
    int nNum = fract1.num * fract2.divider;
    int nDivider = fract1.divider * fract2.num;
    int comDiv = comonDivider(nNum, nDivider);
    return Fraction ((nNum / comDiv), (nDivider / comDiv));
}

bool operator==(const Fraction& fract1, const Fraction& fract2){
    int nNum1 = fract1.num * fract2.divider;
    int nNum2 = fract2.num * fract1.divider;
    return nNum1 == nNum2;
}

bool operator!=(const Fraction& fract1, const Fraction& fract2){
    int nNum1 = fract1.num * fract2.divider;
    int nNum2 = fract2.num * fract1.divider;
    return nNum1 != nNum2;
}

bool operator>(const Fraction& fract1, const Fraction& fract2){
    int nNum1 = fract1.num * fract2.divider;
    int nNum2 = fract2.num * fract1.divider;
    return nNum1 > nNum2;
}

bool operator<(const Fraction& fract1, const Fraction& fract2){
    int nNum1 = fract1.num * fract2.divider;
    int nNum2 = fract2.num * fract1.divider;
    return nNum1 < nNum2;
}

bool operator>=(const Fraction& fract1, const Fraction& fract2){
    return !(fract1 < fract2);
}

bool operator<=(const Fraction& fract1, const Fraction& fract2){
    return !(fract1 > fract2);
}
int main(int args, char** argv){
    int a, b;
    Fraction fract1(1, 2);
    cout << "fract1 : ";
    fract1.showFract();
    cout << endl;

    Fraction fract2(2, 1);
    cout << "fract2: ";
    fract2.showFract();
    cout << endl;

    Fraction fract3 = fract1 + fract2;
    cout << "fract1 + fract2 = ";
    fract3.showFract();
    cout << endl;
    fract3 = fract1 - fract2;
    cout << "fract1 - fract2 = ";
    fract3.showFract();
    cout << endl;
    fract3 = fract1 * fract2;
    cout << "fract1 * fract2 = ";
    fract3.showFract();
    cout << endl;
    cout << "fract1 / fract2 = ";
    fract3 = fract1 / fract2;
    fract3.showFract();
    cout << endl;

    cout <<"fract1 == fract2: " << (fract1 == fract2) << endl;
    cout << "fract1 != fract2: " << (fract1 != fract2) << endl;
    cout << "fract1 > fract2: " << (fract1 > fract2) << endl;
    cout << "fract1 < fract2: " << (fract1 < fract2) << endl;
    cout << "fract1 >= fract2: " << (fract1 >= fract2) << endl;
    cout << "fract1 <= fract2: " << (fract1 <= fract2) << endl;
    return 0;
}
