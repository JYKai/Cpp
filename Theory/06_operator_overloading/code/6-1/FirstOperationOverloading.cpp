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
    const Point operator++(int) // 후위증가
    {
        const Point retobj(xpos, ypos);
        xpos += 1;
        ypos += 1;
        return retobj;
    }

    Point& operator-(void)
    {
        xpos = -xpos;
        ypos = -ypos;
        return *this;
    }
    friend Point& operator--(Point &ref);
    friend const Point operator--(Point &ref, int);
};

Point& operator--(Point &ref)
{
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

const Point operator--(Point &ref, int)
{
    const Point retobj(ref);
    ref.xpos -= 1;
    ref.ypos -= 1;
    return retobj;
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

    return 0;
}