#include <iostream>
#include <string>

class Vehicle {
private:
    std::string model;
    double speed;

public:
    Vehicle(const std::string& m, double s) : model(m), speed(s) {}

    std::string getModel() const {
        return model;
    }

    double getSpeed() const {
        return speed;
    }

    void setModel(const std::string& m) {
        model = m;
    }

    void setSpeed(double s) {
        speed = s;
    }

    virtual double calculateTime(double distance) const = 0;
};

class Car : public Vehicle {
public:
    Car(const std::string& m, double s) : Vehicle(m, s) {}

    double calculateTime(double distance) const override {
        return distance / getSpeed();
    }
};

class Bike : public Vehicle {
public:
    Bike(const std::string& m, double s) : Vehicle(m, s) {}

    double calculateTime(double distance) const override {
        return distance / getSpeed();
    }
};

int main() {
    Car myCar("Sedan", 40.0);
    Bike myBike("Mountain Bike", 20.0);

    double carTime = myCar.calculateTime(100.0);
    std::cout << "Time taken by " << myCar.getModel() << ": " << carTime << " hours\n";

    double bikeTime = myBike.calculateTime(100.0);
    std::cout << "Time taken by " << myBike.getModel() << ": " << bikeTime << " hours\n";

    return 0;
}
