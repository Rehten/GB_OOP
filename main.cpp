#include <iostream>
#include <cmath>

namespace GBLesson {
    class Power
    {
    private:
        int val;
        int coef;
    public:
        void set (int value, int power)
        {
            val = value;
            coef = power;
        }
        void calculate ()
        {
            std::cout << pow(val, coef) << std::endl;
        }
        Power() = default;
    };
}

int main() {
    GBLesson::Power power = *new GBLesson::Power();
    power.set(2, 3);
    power.calculate();
    power.set(3, 3);
    power.calculate();
    power.set(4, 2);
    power.calculate();
    power.set(5, 5);
    power.calculate();
    return 0;
}