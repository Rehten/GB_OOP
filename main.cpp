#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Fruit
{
private:
    string name = "Fruit";
protected:
    string color;
    Fruit(string clr): color(move(clr)) {}
public:
    string get_color() const
    {
        return color;
    }
    virtual string get_name() const
    {
        return name;
    }
};

class Banana: public Fruit
{
private:
    string name = "Banana";
public:
    Banana(string clr): Fruit(move(clr)) {};
    string get_name() const override
    {
        return name;
    }
};

class Apple: public Fruit
{
private:
    string name = "Apple";
public:
    Apple(string clr): Fruit(move(clr)) {}
    string get_name() const override
    {
        return name;
    }
};

class GrannySmith: public Apple
{
private:
    string name = "GrannySmith";
public:
    GrannySmith(string clr): Apple(move(clr)) {}
    string get_name() const override
    {
        return name;
    }
};

int main()
{
    Banana banana("yellow");
    cout << "fruit: " << banana.get_name() << " color: " << banana.get_color() << endl;
    Apple apple("green");
    cout << "fruit: " << apple.get_name() << " color: " << apple.get_color() << endl;
    GrannySmith granny_smith("lightgreen");
    cout << "fruit: " << granny_smith.get_name() << " color: " << granny_smith.get_color() << endl;

    return 0;
}