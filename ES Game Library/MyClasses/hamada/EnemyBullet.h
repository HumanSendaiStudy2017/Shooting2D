#pragma once
#include "../../ESGLib.h"
#include <iostream>
using namespace std;

class Enemy_Bullet
{
public:
	Enemy_Bullet(SPRITE bullet_sprite, Vector3 bullet_pos);
	~Enemy_Bullet();
	void Update();
	Rect GetRect();
	void Draw();
private:
	SPRITE sprite;
	Vector3 pos;
	Vector2 imagesize;
};

