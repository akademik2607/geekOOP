#include<iostream>
#include<cstdint>
using namespace std;

class RGBA{
private:
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;
public:
    RGBA() : m_red(0), m_green(0), m_blue(0), m_alpha(255)
    {}
    RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) :
        m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
    {}
    void print(){
        cout <<"Red: " << (int)m_red;
        cout << " Green: " << (int)m_green;
        cout << " Blue: " << (int)m_blue;
        cout << " Alpha: " << (int)m_alpha << endl;
    }

};

int main(int argc, char** argv){
    RGBA color1;
    color1.print();
    RGBA color2(20, 30, 40, 253);
    color2.print();
    return 0;
}
