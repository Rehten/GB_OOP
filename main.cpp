#include <iostream>
#include "cstdint"
#include <array>

using namespace std;

namespace GBLesson {
    class StackFrame
    {
    private:
        StackFrame* stack_frame = nullptr;
        int number;
    public:
        int const get_number()
        {
            return number;
        }
        StackFrame* get_stack_frame()
        {
            return stack_frame;
        }
        StackFrame(int value, StackFrame* prev) : number(value), stack_frame(prev) {}
    };

    class Stack
    {
    private:
        array<StackFrame*, 10> frames = {};
        int count = 0;
    public:
        Stack() {
            for (auto frame : frames)
            {
                frame = nullptr;
            }
        }
        ~Stack() {
            cout << "Stack destructed" << endl;
        }

        bool push(StackFrame* new_frame)
        {
            if (count != 10)
            {
                frames[count] = new_frame;
                count++;

                return true;
            }
            else
            {
                cout << "Error! Stack size is only 10 frames!" << endl;
                return false;
            }
        }

        int pop()
        {
            if (count != 0) {
                count--;
                int rslt{frames[count]->get_number()};
                delete(frames[count]);
                frames[count] = nullptr;

                return rslt;
            }
            else
            {
                cout << "Error! Stack is empty!!!" << endl;
                return -1;
            }
        }

        void print()
        {
            cout << "( ";
            for (int i = 0; i != count; i++)
            {
                cout << frames[i]->get_number();
                if (i != count - 1)
                {
                    cout << ", ";
                }
            }
            cout << " )";
        }
    };
}

using namespace GBLesson;

int main() {
    Stack first_stack{*new Stack()};
    auto ff1 = new StackFrame(3, nullptr);
    first_stack.push(ff1);
    auto ff2 = new StackFrame(4, ff1);
    first_stack.push(ff2);
    auto ff3 = new StackFrame(5, ff2);
    first_stack.push(ff3);
    auto ff4 = new StackFrame(6, ff3);
    first_stack.push(ff4);

    first_stack.pop();
    auto ff5 = new StackFrame(93, ff3);
    first_stack.push(ff5);

    first_stack.print();
    return 0;
}