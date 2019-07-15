#include <iostream>
#include <vector>

class Car
{
public:
    std::string company;
    std::string model;
    Car(std::string cmp, std::string mdl) : company(std::move(cmp)), model(std::move(mdl)) {
        std::cout << "Car" << std::endl;
    };
    virtual ~Car() = default;
};

class PassengerCar: virtual public Car
{
public:
    PassengerCar(std::string cmp, std::string mdl) : Car(std::move(cmp), std::move(mdl)) {
        std::cout << "PassengerCar" << std::endl;
    }
    ~PassengerCar() override = default;
};

class Bus: virtual public Car
{
public:
    Bus(std::string cmp, std::string mdl) : Car(std::move(cmp), std::move(mdl)) {
        std::cout << "Bus" << std::endl;
    }
    ~Bus() override = default;
};

class Minivan: public PassengerCar, public Bus
{
public:
    Minivan(std::string cmp, std::string mdl) :
    Car(std::move(cmp), std::move(mdl)),
    Bus(std::move(cmp), std::move(mdl)),
    PassengerCar(std::move(cmp), std::move(mdl))
    {
        std::cout << "Minivan" << std::endl;
    }
    ~Minivan() override = default;
};

int main() {
    std::cout << "Car initialize: " << std::endl;
    Car car("Hundai", "po179xx");
    std::cout << "PassengerCar initialize: " << std::endl;
    PassengerCar pas_car("Lada", "ka1ina");
    std::cout << "Bus initialize: " << std::endl;
    Bus bus("Detstvo", "u98q");
    std::cout << "Minivan initialize: " << std::endl;
    Minivan minivan("Unico", "xsl3m");
    return 0;
}