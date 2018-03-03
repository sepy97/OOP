//
//  main.cpp
//  GameHero
//
//  Created by Семен Пьянков on 25.02.2018.
//  Copyright © 2018 sepy. All rights reserved.
//

#include <cstdio>
using namespace std;

class Game_Hero
{
private:
    int  HP    = 0;
    bool alive = false;
    bool zombi = false;
    
public:
    Game_Hero (int = 10, bool = false);
    
    bool isDead ();
    int livePoints();
    void damage (int damage = 5);
    void heal (int health = 3);
    
};

Game_Hero::Game_Hero (int health , bool isZombi )
{
    this->HP = health;
    this->zombi = isZombi;
    if (this->HP > 0) alive = true;
}

bool Game_Hero::isDead ()
{
    return !alive;
}

int Game_Hero::livePoints ()
{
    return this->HP;
}

void Game_Hero::damage (int damage)
{
    this->HP -= damage;
    if (this->HP <= 0) this->alive = false;
}

void Game_Hero::heal (int health)
{
    this->HP += health;
    if (this->HP > 0 && this->zombi) this->alive = true;
}

int main(int argc, const char * argv[])
{
    
}
