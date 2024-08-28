#include <iostream>
using namespace std;


class Point
{
private:
    int xpos, ypos;

public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    { }
    void ShowPosition(void) const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    friend ostream& ostream<<(ostream&, const Point&);
    friend istream& istream>>(istream&, const Point&);
};

friend ostream& ostream<<(ostream& os, const Point& pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}

friend istream& istream>>(istream& is, const Point& pos)
{
    is >> pos.xpos >> pos.ypos;
    return is;
}

int main(void)
{
    Point pos1;
    cout << "x, y 좌표 순으로 입력: ";
    cin >> pos1;
    cout << pos1;

    return 0;
}