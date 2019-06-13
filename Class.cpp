#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Bicycle
{
public:
    int getting_speed();
    void setting_speed(int speed);
    void pedal();
    void brake();
    int speed;
};
//get the bicycle's ispeed
void Bicycle::setting_speed(int newSpeed)
{
    if (newSpeed >= 0)
    {
        speed = newSpeed;
    }

}
//getting the bicycle initial speed
int Bicycle::getting_speed()
{
    return speed;
}
//pedal the bike
void Bicycle::pedal()
{
    setting_speed(speed + 1);
}
// brake the bike
void Bicycle::brake()
{
    setting_speed(speed -1);
}
//create a bicycle then ride it
main()
{
    Bicycle sing_wah;
    sing_wah.setting_speed(0);
    sing_wah.pedal();
    cout << "Pedaling; Sing-Wah's bicycle at " << sing_wah.getting_speed()<< "mps" <<endl;
    sing_wah.pedal();
    cout << "Pedaling; Sing-Wah's bicycle at " << sing_wah.getting_speed()<< "mps" <<endl;
    sing_wah.pedal();
    cout << "Pedaling; Sing-Wah's bicycle at " << sing_wah.getting_speed()<< "mps" << endl;
    sing_wah.brake();
    cout << "Braking; Sing-Wah's bicycle at " << sing_wah.getting_speed()<< "mps" << endl;
    sing_wah.brake();
    cout << "Braking; Sing-Wah's bicycle at " << sing_wah.getting_speed()<< "mps" << endl;

    return 0;
}


