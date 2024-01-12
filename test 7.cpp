#include <iostream>

class Shape {
public:
    virtual double calculateArea() const = 0;

    virtual void draw() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return 3.14 * radius * radius;
    }

    void draw() const override {
        std::cout << "Drawing a circle\n";
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double calculateArea() const override {
        return width * height;
    }

    void draw() const override {
        std::cout << "Drawing a rectangle\n";
    }
};

int main() {
    Circle myCircle(5.0);
    Rectangle myRectangle(4.0, 6.0);

    Shape* shapes[2];
    shapes[0] = &myCircle;
    shapes[1] = &myRectangle;

    for (int i = 0; i < 2; ++i) {
        std::cout << "Details for Shape " << i + 1 << ":\n";
        std::cout << "Area: " << shapes[i]->calculateArea() << "\n";
        shapes[i]->draw();
        std::cout << "\n";
    }

    return 0;
}
