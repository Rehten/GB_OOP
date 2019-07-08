#include <iostream>
#include "cstdint"

using namespace std;

namespace GBLesson {
    class RGBA {
    private:
        uint8_t m_red;
        uint8_t m_green;
        uint8_t m_blue;
        uint8_t m_alpha;
    public:
        RGBA(
                uint8_t red,
                uint8_t green,
                uint8_t blue,
                uint8_t alpha = 255
        ) : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {}
        void print()
        {
            cout<<"( "<<(int)m_red<<", "<<(int)m_green<<", "<<(int)m_blue<<", "<<(int)m_alpha<<" )"<<endl;
        }
    };
}

int main() {
    GBLesson::RGBA color1(25, 25, 25, 255);
    color1.print();
    GBLesson::RGBA color2(13, 14, 5);
    color2.print();
    return 0;
}