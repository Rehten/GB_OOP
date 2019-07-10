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
};

class Banana: public Fruit
{
private:
    string name = "Banana";
public:
    Banana(string clr): Fruit(move(clr)) {}
};

class Apple: public Fruit
{
private:
    string name = "Apple";
public:
    Apple(string clr): Fruit(move(clr)) {}
};

class GrannySmith: public Apple
{
private:
    string name = "GrannySmith";
public:
    GrannySmith(string clr): Apple(move(clr)) {}
};

int main()
{
    Banana banana("yellow");
    cout << banana.get_color() << endl;
    Apple apple("green");
    cout << apple.get_color() << endl;
    GrannySmith granny_smith("lightgreen");
    cout << granny_smith.get_color() << endl;

    return 0;
}