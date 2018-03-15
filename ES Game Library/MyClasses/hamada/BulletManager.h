#pragma once
#include "../../ESGLib.h"
#include "EnemyBullet.h"
#include <vector>
using namespace std;

class BulletManager
{
public:
	BulletManager();
	~BulletManager();
	void Update(Rect display_rect);
	void Draw();
	void Shot(Vector3 pos);
	vector<Enemy_Bullet*>& GetBulletList();
private:
	SPRITE sp;
	vector<Enemy_Bullet*> bullets;
};

