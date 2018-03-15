#include "Enemy.h"
#include "BulletManager.h"


Enemy::Enemy(SPRITE enemy_sprite, Vector3 enemy_pos)
{
	sprite = enemy_sprite;
	pos = enemy_pos;
	imagesize = Vector2(204.0f, 300.0f);
	move_state = MOVE_RIGHT;
	shot_time = 0;
}


Enemy::~Enemy()
{

}

//bool Enemy::Initialize()
//{
//	enemy = GraphicsDevice.CreateSpriteFromFile(_T("enemy.png"));
//	enemy_x = 0.0f;
//	enemy_y = 0.0f;
//	move_state = 0;
//	shot_time = 0.0f;
//
//	std::random_device seed;
//	std::mt19937 random(seed());
//
//	std::uniform_real_distribution<float> dist(2.0f, 3.5f);
//
//	float random_value = dist(random);
//	bullet.Initialize();
//
//	return true;
//}

void Enemy::Update(BulletManager* manager)
{
	shot_time += GameTimer.GetElapsedMilliSecond();
	if (shot_time > 800)
	{
		shot_time -= 800;
		Vector3 instace_pos;
		instace_pos = pos;
		instace_pos.y += imagesize.y;
		manager->Shot(instace_pos);
	}
	Move();
}

void Enemy::Move()
{
	switch (move_state)
	{
	case MOVE_RIGHT : 
		pos.x += 5.0f;
		if (pos.x + imagesize.x > 1280.0f)
		{
			pos.x = 1280.0f - imagesize.x;
			move_state = MOVE_LEFT;
		}
		break;
	case MOVE_LEFT : 
		pos.x -= 5.0f;
		if (pos.x < 0.0f)
		{
			pos.x = 0.0f;
			move_state = MOVE_RIGHT;
		}
	default:
		break;
	}
}

void Enemy::Draw()
{
	SpriteBatch.Begin();
	SpriteBatch.Draw(*sprite, pos);
	SpriteBatch.End();
}