#include <heatTest.h>
#include <iostream>
using namespace std;
bool check(sf::Sprite &s1,sf::Sprite &s2){
if(s1.getGlobalBounds().intersects(s2.getGlobalBounds())){
    return true;
}
else
{
    return false;
}

}
