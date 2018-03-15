#include "EnemyBullet.h"


Enemy_Bullet::Enemy_Bullet(SPRITE bullet_sprite, Vector3 bullet_pos)
{
	sprite = bullet_sprite;
	pos = bullet_pos;
	imagesize = Vector2(50.0f, 50.0f);
}


Enemy_Bullet::~Enemy_Bullet()
{
	
}

Rect Enemy_Bullet::GetRect()
{
	Rect rect;
	rect = Rect();
	rect.left = pos.x;
	rect.top = pos.y;
	rect.right = pos.x + imagesize.x;
	rect.bottom = pos.y + imagesize.y;

	return rect;
}


void Enemy_Bullet::Update()
{
	pos.y += 3.0f;
}


void Enemy_Bullet::Draw()
{
	SpriteBatch.Draw(*sprite, pos);
}