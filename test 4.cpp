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

    virtual void displayDetails() const = 0;
};

class Car : public Vehicle {
public:
    Car(const std::string& m, double s) : Vehicle(m, s) {}

    double calculateTime(double distance) const override {
        return distance / getSpeed();
    }

    void displayDetails() const override {
        std::cout << "Car Model: " << getModel() << "\n";
        std::cout << "Car Speed: " << getSpeed() << " km/h\n";
    }
};

class Bike : public Vehicle {
public:
    Bike(const std::string& m, double s) : Vehicle(m, s) {}

    double calculateTime(double distance) const override {
        return distance / getSpeed();
    }

    void displayDetails() const override {
        std::cout << "Bike Model: " << getModel() << "\n";
        std::cout << "Bike Speed: " << getSpeed() << " km/h\n";
    }
};

int main() {
    Car myCar("Sedan", 60.0);
    Bike myBike("Mountain Bike", 20.0);

    Vehicle* vehicles[2];
    vehicles[0] = &myCar;
    vehicles[1] = &myBike;

    for (int i = 0; i < 2; ++i) {
        std::cout << "Details for Vehicle " << i + 1 << ":\n";
        vehicles[i]->displayDetails();
        std::cout << "\n";
    }

    return 0;
}
