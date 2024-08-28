#include <iostream>
using namespace std;


class Point
{
private:
    int xpos, ypos;

public:
    Point(int x, int y) : xpos(x), ypos(y)
    { }
    void ShowPosition(void) const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point& operator++(void)
    {
        xpos+=1;
        ypos+=1;
        return *this;
    }
    Point& operator-(void)
    {
        xpos = -xpos;
        ypos = -ypos;
        return *this;
    }
    friend Point& operator--(Point &ref);
    friend Point operator~(const Point &);
};

Point& operator--(Point &ref)
{
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

Point operator~(const Point &ref)
{
    Point pos(ref.ypos, ref.xpos);
    return pos;
}

int main(void)
{
    Point pos1(1, 2);
    ++pos1;
    pos1.ShowPosition();
    --pos1;
    pos1.ShowPosition();

    ++(++pos1);
    pos1.ShowPosition();
    --(--pos1);
    pos1.ShowPosition();

    Point pos2(2, 3);
    -pos2;
    pos2.ShowPosition();

    Point pos3(3, 4);
    (~pos3).ShowPosition();

    return 0;
}