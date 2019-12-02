#include<iostream>
#include<cstring>
using namespace std;

static int Human::count = 0;
class Human{
private:
    string firstName;
    string lastName;
public:
    static int count;
    Human(string first, string last) firstName(first), lastName(last) {}
    void setFirstName(string str){
        firstName = str;
    }
    void setLastName(string str){
        lastName = str;
    }
    string getFirstName(){
        return firstName;
    }
    string getLastName(){
        return lastName;
    }
};

class Student : public Human{
private:
    string facultyNumber;
public:
    Student(string first, string second, string faculty)
        : Human(first, second), facultyNumber(faculty){
        count++;
    }
    void setFacultyNumber(double str){
        facultyNumber = str;
    }
    string getFacultyNumber(){
        return facultyNumber;
    }
    void showStudent(){
        cout << "First Name: "<< getFirstName();
        cout << " Last Name: "<< getLastname();
        cout << " Facultet: " << getFacultyNumber();
        cout << endl;
    }
};

class Woker : public Human{
private:
    double weekSalary;
    double workHoursPerDay;
public:
    Worker(string first, string second, double Salary, double workHours)
        : Human(first, second), weekSalary(Salary), workHoursPerDay(workHours){
        count++;
    }
    void setWeekSalary(string str){
        weekSalary = str;
    }
    void setWorkHoursPerDay(string str){
        workHoursPerDay = str;
    }
    string getWeekSalary(){
        return weekSalary;
    }
    string getWorkHoursePerDay(){
        return workHoursPerDay;
    }
    void showWorker(){
        cout << "First Name: "<< getFirstName();
        cout << " Last Name: "<< getLastname();
        cout << " Week Salary: " << getWeekSalary();
        cout << " Work Hourse Per Day: " << getWorkHoursePerDay();
        cout << endl;
    }
};

int main(int args, char** argv){
    Worker arrWork[10];
    Studnt arrStud[10];
    int indWork = 0;
    int indStud = 0;
    string str;
    for(int i = 0;i < 5;i){
        string buf;
        cout << "Worker or Student?" << endl;
        getline(cin, buf);
        if(buf == "Worker"){
            Work arrWork[indWork];
            indWork++;
        }
        else if(buf == "Student") {
            Student arrWork[indStud];
            indStudent++;
        }
        else {
            cout << "Error" << endl;
        }
    }
    cout << "Enter Humans name: ";
    getline(cin, str);
    for (int i = 0;i < 10;i++ ) {
       if(arrWork[i].getFirstName() == str)
           cout << arrWork[i].showFirstName();
    }
    for (int i = 0;i < 10;i++ ) {
       if(arrStud[i].getFirstName() == str)
           cout << arrStud[i].showFirstName();
    }
    return 0;
}
