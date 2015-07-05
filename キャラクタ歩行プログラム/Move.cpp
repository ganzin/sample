#include "Move.h"
#include"game.h"
void Move::movePos(float &x, float &y, float &z,float &speed,float &angle)
{
	speed = 0;
	if (gsGetKeyState(GKEY_UP) != 0)
	{
		speed = 0.1f; 
	}
	if (gsGetKeyState(GKEY_DOWN) != 0)
	{
		speed = -0.1f;
	}
	x = x + gsSin(angle)*speed;
	z = z + gsCos(angle)*speed;

}

void Move::moveAngle(float &angle)
{
	if (gsGetKeyState(GKEY_LEFT) != 0)
	{
		angle += 1.5f;
	}
	if (gsGetKeyState(GKEY_RIGHT) != 0)
	{
		angle -= 1.5f;
	}
}