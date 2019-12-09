#include<iostream>
#include<cstring>
using namespace std;

class Car{
private:
    string company;
    string model;
public:
    Car(string companyName, string modelName) : company(companyName), model(modelName){
        cout << "It is a car " << getCompany() << " " << getModel() << endl;
    }
    string getCompany() const {
        return company;
    }
    string getModel() const {
        return model;
    }
};

class PassengerCar : virtual public Car{
public:
    PassengerCar(string companyName, string modelName) : Car(companyName, modelName){
        cout << "It is a Passenger car" << getCompany() << " " << getModel() << endl;
    }
};

class Bus : virtual public Car{
public:
    Bus(string companyName, string modelName) : Car(companyName, modelName){
        cout << "It is a bus" << getCompany() << " " << getModel() << endl;
    }
};

class Minivan : public PassengerCar, public Bus{
public:
    Minivan(string companyName, string modelName)
        : Car(companyName ,modelName), PassengerCar(companyName, modelName), Bus(companyName, modelName){
        cout << "It is a minivan" << getCompany() << " " << getModel() << endl;
    }
};

int main(int argc, char** argv){
    Car car1("Mos", "23");
    cout << endl;
    PassengerCar car2("Vol", "60");
    cout << endl;
    Bus car3("Aer", "40");
    cout << endl;
    Minivan car4("Mrs", "600");
    return 0;
}
