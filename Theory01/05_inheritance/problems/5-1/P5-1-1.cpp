#include <iostream>
using namespace std;

class Car
{
private:
    int gasolineGauge;

public:
    Car(int gasoline) : gasolineGauge(gasoline) { }
    int GetGasGauge(void) { return gasolineGauge; }
};


class HybridCar : public Car
{
private:
    int electricGauge;

public:
    HybridCar(int gasoline, int electric)
        : Car(gasoline), electricGauge(electric)
    { }
    int GetElecGauge(void) { return electricGauge; }
};


class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;

public:
    HybridWaterCar(int gasoline, int electric, int water)
        : HybridCar(gasoline, electric), waterGauge(water)
    { }
    void ShowCurrentGauge(void)
    {
        cout << "잔여 가솔린: " << GetGasGauge() << endl;
        cout << "잔여 전기량: " << GetElecGauge() << endl;
        cout << "잔여 워터량: " << waterGauge << endl << endl;
    }
};


int main(void)
{
    HybridWaterCar hwcar1(200, 1000, 2000);
    hwcar1.ShowCurrentGauge();

    HybridWaterCar hwcar2(300, 5000, 7000);
    hwcar2.ShowCurrentGauge();

    return 0;
}