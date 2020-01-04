#include<iostream>
using namespace std;

class Date{
private:
    int m_day, m_month, m_year;
public:
    Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year){}
    int getDay() const{
        return m_day;
    }
    int getMonth() const{
        return m_month;
    }
    int getYear() const{
        return m_year;
    }
    void setDay(int day){
        m_day = day;
    }
    void setMonth(int month){
        m_month = month;
    }
    void setYear(int year){
        m_year = year;
    }
    friend ostream& operator<<(ostream& out, Date& date);
};

ostream& operator<<(ostream& out, Date& date){
    out << date.getDay() << "." << date.getMonth() << "." << date.getYear() << ".";
    return out;
}

class DatePointer{
private:
    Date* pointer;
public:
    DatePointer(int day, int month, int year){
        pointer = new Date(day, month, year);
    }
    DatePointer(){
        pointer = nullptr;
    }
    ~DatePointer(){
        delete pointer;
    }
    DatePointer(const DatePointer &date) = delete;
    DatePointer& operator=(const DatePointer& date) = delete;
    DatePointer(DatePointer&& date){
        delete pointer;
        pointer = date.pointer;
        date.pointer = nullptr;
    }
    DatePointer& operator=(DatePointer&& date){
        delete pointer;
        pointer = date.pointer;
        date.pointer = nullptr;
        return *this;
    }
    Date& operator*(){
        return *pointer;
    }
    Date* operator->(){
        return pointer;
    }
    Date* getPointer(){
        return pointer;
    }
};

//2.

Date& maxDate(DatePointer &date1, DatePointer &date2){
    if(date1->getYear() != date2->getYear()){
        return date1->getYear() > date2->getYear() ? *date1 : *date2;
    }
    else if (date1->getMonth() != date2->getMonth()) {
        return date1->getMonth() > date2->getMonth() ? *date1 : *date2;
    }
    else if (date1->getDay() != date2->getDay()) {
        return date1->getDay() > date2->getDay() ? *date1 : *date2;
    }
    else {
        return *date1;
    }
}

void swapDatePointers(DatePointer &date1, DatePointer& date2){
    DatePointer temp(0, 0, 0);
    temp = move(date1);
    date1 = move(date2);
    date2 = move(temp);
}
int main(int args, char** argv){
    //1

    DatePointer today(21, 12, 2019);
    cout <<"Day: " << today->getDay() << endl;
    cout << "Month: " << today->getMonth() << endl;
    cout << "Year: " << today->getYear() << endl;
    cout << "Today is " << *today << endl;
    DatePointer date;
    date = move(today);
    cout << *date << endl;
    if(today.getPointer() == nullptr){
        cout << "*today = nullptr" << endl;
    }
    else {
        cout << "*today != nullptr" << endl;
    }
    if(date.getPointer() == nullptr){
        cout << "*date = nullptr" << endl;
    }
    else {
         cout << "*date != nullptr" << endl;
    }

    //2

    DatePointer date1(1, 12, 2019);
    DatePointer date2(2, 12, 2019);
    cout << *date1 << endl << *date2 <<endl;
    cout << "Max date: " << maxDate(date1, date2) << endl;
    cout << *date1 << endl << *date2 << endl << endl;
    cout << "*date1: " << *date1 << endl;
    cout << "*date2: " << *date2 << endl;
    swapDatePointers(date1, date2);
    cout << "*date1: " << *date1 << endl;
    cout << "*date2: " << *date2 << endl;
    return 0;
}




