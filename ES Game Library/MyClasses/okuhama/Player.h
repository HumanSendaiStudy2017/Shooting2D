#pragma once
#include "../../ESGLib.h"
#include  "../fujimura/Bullet.h"

class Player
{
public:
	Player();
	~Player();
    bool Initialize();
	void Finalize();
	void UpDate();
	void GetRect();
	void Draw();

	Rect GetBulletRect(){

		return bullet.GetRect();

	}

	
private:

	SPRITE sp;
	Vector3 pos;
	Bullet bullet;

	enum BULLET_STATE
	{
		SHOT_START,
		SHOT_NOW,
		SHOT_END
	}bullet_state;

	void BulletShot();
	void Move();



};

