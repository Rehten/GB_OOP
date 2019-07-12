#include <iostream>
#include <vector>

using namespace std;

class Figure
{
public:
    Figure() = default;
    virtual float area () = 0;
};

class Parallelogram: public Figure
{
protected:
    float width;
    float height;
    float sin_angle;
public:
    Parallelogram(float wdth, float hght, float sin_ngl) : width(wdth), height(hght), sin_angle(sin_ngl) {}
    float area () override {
        return width * height * sin_angle;
    }
};

class Circle: public Figure
{
private:
    float radius;
public:
    Circle(float rds) : radius(rds) {};
    float area() override {
        return radius * radius * (float)3.14;
    }
};

class Rectangle: public Parallelogram
{
public:
    Rectangle(float wdth, float hght) : Parallelogram(wdth, hght, (float)1.00) {}
};


class Square: public Parallelogram
{
public:
    Square(float wdth) : Parallelogram(wdth, wdth, (float)1.00) {}
};

class Rhombus: public Parallelogram
{
public:
    Rhombus(float wdth, float sin) : Parallelogram(wdth, wdth, sin) {}
};

int main() {
    vector<Figure*> figures;
    figures.push_back(new Parallelogram(4, 4, 0.85));
    figures.push_back(new Circle(4));
    figures.push_back(new Square(5));
    figures.push_back(new Rectangle(3, 4));
    figures.push_back(new Rhombus(6, 0.85));

    for (Figure* figure : figures)
    {
        cout << figure->area() << endl;
    }
    return 0;
}