#include <iostream>
#include <vector>

class Fractal
{
public:
    virtual ~Fractal() = default;
    virtual float operator+(Fractal& two) = 0;
    virtual float operator-(Fractal& two) = 0;
    virtual float operator*(Fractal& two) = 0;
    virtual float operator/(Fractal& two) = 0;
    virtual bool operator==(Fractal& two) = 0;
    virtual bool operator!=(Fractal& two) = 0;
    virtual bool operator>(Fractal& two) = 0;
    virtual bool operator<(Fractal& two) = 0;
    virtual bool operator>=(Fractal& two) = 0;
    virtual bool operator<=(Fractal& two) = 0;
    virtual float operator-() = 0;
};

class SimpleFractal: public Fractal
{
public:
    int low_num;
    int high_num;
    SimpleFractal(int l_n, int h_n): low_num(l_n), high_num(h_n) {};
    virtual float operator+(SimpleFractal& sec)
    {
        return (float)high_num/(float)low_num + (float)sec.high_num/(float)sec.low_num;
    };
    virtual float operator-(SimpleFractal& sec) {
        return (float)high_num/(float)low_num - (float)sec.high_num/(float)sec.low_num;
    };
    virtual float operator*(SimpleFractal& sec) {
        return (float)high_num/(float)low_num * (float)sec.high_num/(float)sec.low_num;
    };
    virtual float operator/(SimpleFractal& sec) {
        return ((float)high_num/(float)low_num) / ((float)sec.high_num/(float)sec.low_num);
    };
    virtual bool operator==(SimpleFractal& sec) {
        return (float)high_num/(float)low_num - (float)sec.high_num/(float)sec.low_num == 0;
    };
    virtual bool operator!=(SimpleFractal& sec) {
        return (float)high_num/(float)low_num - (float)sec.high_num/(float)sec.low_num != 0;
    };
    virtual bool operator>(SimpleFractal& sec) {
        return (float)high_num/(float)low_num - (float)sec.high_num/(float)sec.low_num > 0;
    };
    virtual bool operator<(SimpleFractal& sec) {
        return (float)high_num/(float)low_num - (float)sec.high_num/(float)sec.low_num < 0;
    };
    virtual bool operator>=(SimpleFractal& sec) {
        return !(*this < sec);
    };
    virtual bool operator<=(SimpleFractal& sec) {
        return !(*this > sec);
    }
    virtual float operator-() {
        return 0.00;
    };
};

class MixedFractal: public Fractal
{
public:
    int decimal;
    int low_num;
    int high_num;
    MixedFractal(int dc, int l_n, int h_n): decimal(dc), low_num(l_n), high_num(h_n) {};
    virtual float operator+(MixedFractal& sec)
    {
        return ((float)decimal + (float)high_num/(float)low_num) + ((float)sec.decimal + (float)sec.high_num/(float)sec.low_num);
    };
    virtual float operator-(MixedFractal& sec) {
        return ((float)decimal + (float)high_num/(float)low_num) - ((float)sec.decimal + (float)sec.high_num/(float)sec.low_num);
    };
    virtual float operator*(MixedFractal& sec) {
        return ((float)decimal + (float)high_num/(float)low_num) * ((float)sec.decimal + (float)sec.high_num/(float)sec.low_num);
    };
    virtual float operator/(MixedFractal& sec) {
        return ((float)decimal + (float)high_num/(float)low_num) / ((float)sec.decimal + (float)sec.high_num/(float)sec.low_num);
    };
    virtual bool operator==(MixedFractal& sec) {
        return (float)decimal - (float)sec.decimal + (float)high_num/(float)low_num - (float)sec.high_num/(float)sec.low_num == 0;
    };
    virtual bool operator!=(MixedFractal& sec) {
        return (float)decimal - (float)sec.decimal + (float)high_num/(float)low_num - (float)sec.high_num/(float)sec.low_num != 0;
    };
    virtual bool operator>(MixedFractal& sec) {
        return (float)decimal - (float)sec.decimal + (float)high_num/(float)low_num - (float)sec.high_num/(float)sec.low_num > 0;
    };
    virtual bool operator<(MixedFractal& sec) {
        return (float)decimal - (float)sec.decimal + (float)high_num/(float)low_num - (float)sec.high_num/(float)sec.low_num < 0;
    };
    virtual bool operator>=(MixedFractal& sec) {
        return !(*this < sec);
    };
    virtual bool operator<=(MixedFractal& sec) {
        return !(*this > sec);
    };
    virtual float operator-() {
        return 0.00;
    };
};

int main() {

    return 0;
}