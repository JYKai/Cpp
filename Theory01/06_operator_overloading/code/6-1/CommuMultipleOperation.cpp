#include <iostream>
using namespace std;


class Point
{
private:
    int xpos, ypos;

public:
    Point(int x=0, int y=0) : xpos(x), ypos(y)
    { }
    void ShowPosition(void) const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point operator*(int times)
    {
        Point pos(xpos * times, ypos * times);
        return pos;
    }
    friend Point operator*(int times, Point& ref);
};

Point operator*(int times, Point& ref)
{
    return ref * times;
}

int main(void)
{
    Point pos1(1, 2);
    Point cpy;

    cpy = 3 * pos1;
    cpy.ShowPosition();

    cpy = 2 * pos1 * 3;
    cpy.ShowPosition();

    return 0;
}