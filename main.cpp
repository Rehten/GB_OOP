#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class rand_generator
{
private:
    mutable int cur_num{-1};
public:
    int current() const {
        if (cur_num == -1)
        {
            cout << "Error!!! Start random is not generated";
        }
        return cur_num;
    };
    int next() const {
        cur_num = rand();

        return cur_num;
    };
    rand_generator() = default;
    rand_generator(int num): cur_num(num) {};
    rand_generator(rand_generator& src): cur_num(src.current()) {};
};

int main()
{
    rand_generator rndm(rand());
    for (int i = 0; i != 10; i++)
    {
        cout << rndm.current() << ((i != 9) ? " -> " : "");
        rndm.next();
    }
    return 0;
}