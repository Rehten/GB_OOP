#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Person
{
protected:
    int name{1};
    int age{2};
    int sex{3};
    int weight{4};
public:
    int get_name() const
    {
        return name;
    };
    void set_name(int new_name)
    {
        name = new_name;
    };
    int get_age() const
    {
        return age;
    };
    void set_age(int new_age)
    {
        age = new_age;
    };
    int get_sex() const
    {
        return sex;
    };
    void set_sex(int new_sex)
    {
        sex = new_sex;
    };
    int get_weight() const
    {
        return weight;
    };
    void set_weight(int new_weight)
    {
        weight = new_weight;
    };
};

class Student: public Person
{
private:
    int age_studying{5};
public:
    int get_age_studying() const
    {
        return age_studying;
    };
    void set_age_studying(int new_age_studying)
    {
        age_studying = new_age_studying;
    };
};

int main()
{
    Student student;
    cout << student.get_age() << " " << student.get_name() << " " << student.get_sex() << " " << student.get_weight()
    << " " << student.get_age_studying() << endl;
    return 0;
}