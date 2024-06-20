#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x, int y)
        : xpos(x), ypos(y)
    { }

    void ShowPointInfo(void) const { cout << "[" << xpos << ", " << ypos << "]" << endl; }
    int GetX(void) const { return xpos; }
    int GetY(void) const { return ypos; }
};

class Circle
{
private:
    Point center;
    int radius;

public:
    Circle(int x, int y, int r)
        : center(x, y), radius(r)
    { }
    
    int GetR(void) const { return radius; }
    int GetX(void) const { return center.GetX(); }
    int GetY(void) const { return center.GetY(); }
};

class Ring
{
private:
    Circle inner;
    Circle outter;

public:
    Ring(int iX, int iY, int iR, int oX, int oY, int oR)
        : inner(iX, iY, iR), outter(oX, oY, oR)
    { }

    void ShowRingInfo(void) const
    {
        cout << "Inner Circle Info..." << endl;
        cout << "radius: " << inner.GetR() << endl;
        cout << "[" << inner.GetX() << ", " << inner.GetY() << "]" << endl;

        cout << "Outter Circle Info..." << endl;
        cout << "radius: " << outter.GetR() << endl;
        cout << "[" << outter.GetX() << ", " << outter.GetY() << "]" << endl;
    }
};


int main(void)
{
    Ring ring(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();
    
    return 0;
}