#pragma once
#include "../../ESGLib.h"
#include <iostream>
#include <random>
using namespace std;

class BulletManager;

class Enemy
{
public:
	Enemy(SPRITE enemy_sprite, Vector3 enemy_pos);
	~Enemy();
	void Update(BulletManager*);
	void Draw();
private:

	enum MOVE_STATE
	{
		MOVE_RIGHT,
		MOVE_LEFT
	}move_state;
	SPRITE sprite;
	Vector3 pos;
	Vector2 imagesize;
	void Move();
	int shot_time;
};

