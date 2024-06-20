#include <iostream>
using namespace std;


class Rectangle
{
private:
    int row;
    int col;

public:
    Rectangle(int r, int c) : row(r), col(c) { }
    void ShowAreaInfo(void) const
    {
        cout << "면적 : " << row * col << endl;
    }
};


class Square : public Rectangle
{
private:
    int line;

public:
    Square(int l)
        : Rectangle(l, l), line(l)
    { }
    void ShowAreaInfo(void) const
    {
        cout << "면적 : " << line * line << endl;
    }
};


int main(void)
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();

    return 0;
}