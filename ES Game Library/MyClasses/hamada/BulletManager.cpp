#include "BulletManager.h"


BulletManager::BulletManager()
{
	sp = GraphicsDevice.CreateSpriteFromFile(_T("pai2.png"));
}


BulletManager::~BulletManager()
{
	for (auto bullet : bullets)
	{
		delete bullet;
	}
}

void BulletManager::Update(Rect display_rect)
{
	/*for (auto bullet : bullets)
	{
		bullet->Update();
	}*/

	auto itr = bullets.begin();
	while (itr != bullets.end())
	{
		(*itr)->Update();
		if (!display_rect.Intersect((*itr)->GetRect()))
		{
			delete (*itr);
			itr = bullets.erase(itr);
			continue;
		}
		itr++;
	}
}

void BulletManager::Shot(Vector3 pos)
{
	bullets.push_back(new Enemy_Bullet(sp,pos));
}

void BulletManager::Draw()
{
	SpriteBatch.Begin();
	for (auto bullet : bullets)
	{
		bullet->Draw();
	}
	SpriteBatch.End();
}
