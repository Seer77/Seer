#include <iostream>
#include < cmath >
#include < cstdint >
#include <cassert>

class Power
{
private:
    double m_numberone;
    double m_numbertwo;

public:
    void setPower(double numberone, double numbertwo) { m_numberone = numberone; m_numbertwo = numbertwo; }
    void calculate()
    {
        std::cout << std::pow(m_numberone, m_numbertwo);
    }
};

class RGBA
{
private:
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0;
    std::uint8_t m_alpha = 255;

public:
    RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
        : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {}

    void print()
    {
        std::cout << "red = " << static_cast<uint16_t>(m_red) << std::endl;
        std::cout << "green = " << static_cast<uint16_t>(m_green) << std::endl;
        std::cout << "blue = " << static_cast<uint16_t>(m_blue) << std::endl;
        std::cout << "alpha = " << static_cast<uint16_t>(m_alpha) << std::endl;
    }
};

class Stack
{
private:
    int m_array[10];
    int m_index;

public:
    void reset()
    {
        m_index = 0;
        for (int i = 0; i < 10; ++i)
            m_array[i] = 0;
    }

    bool push(int value)
    {
        if (m_index == 10)
        {
            return false;
        }
        else
        {
            m_array[m_index++] = value;
            return true;
        }
    }

    int pop()
    {
        assert(m_index > 0);
        return m_array[--m_index];
    }

    void print()
    {
        std::cout << "( ";
        for (int i = 0; i < m_index; ++i)
        {
            std::cout << m_array[i] << ' ';
        }
        std::cout << ")\n";
    }
};



int main()
{
    Power power;//dz1
    power.setPower(3, 2.05);
    power.calculate();
    std::cout << std::endl;

    RGBA rgba(105, 15, 16, 220);
    rgba.print();

    Stack stack;
    stack.reset();
    stack.print();
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    stack.pop();
    stack.print();

}
