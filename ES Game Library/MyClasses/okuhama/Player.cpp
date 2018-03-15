#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

bool Player::Initialize()
{
	sp = GraphicsDevice.CreateSpriteFromFile(_T("EX000011.png"),Color(255,255,255));
	
	//プレイヤーポジション
	pos.x = 550.0f;
	pos.y = 550.0f;
	pos.z = 0.0f;

	bullet_state = SHOT_START;

	bullet.Initialize();

	return true;
}

void Player::Finalize()
{
}

void Player::UpDate()
{
	Move();
	BulletShot();

	//範囲限定
	if (pos.x >= 1080)
	{
		pos.x = 1080;
	}
	if (pos.x <= -10)
	{
		pos.x = -10;
	}




}

void Player::GetRect()
{
}

void Player::BulletShot()
{
	KeyboardBuffer key_buffer = Keyboard->GetBuffer();
	Vector3 pos = this->pos;
	pos.y += 10;

	switch (bullet_state){

		case SHOT_START :
			if (key_buffer.IsPressed(Keys_Space)){
				
				bullet.SetPosition(pos);

				bullet_state = SHOT_NOW;

			}
			break;

		case SHOT_NOW:


			bullet.Update();
			if (bullet.IsDisplayOut()){

				bullet_state = SHOT_START;

			}
			break;

	}

}

void Player::Move()
{
	KeyboardState   key_state = Keyboard->GetState();
	if (key_state.IsKeyDown(Keys_Right)) {
		pos.x += 20.0f;
	}
	if (key_state.IsKeyDown(Keys_Left)) {
		pos.x -= 20.0f;
	}
}



void Player::Draw()
{
	SpriteBatch.Begin();

	SpriteBatch.Draw(*sp, pos);

	SpriteBatch.End();
	bullet.Draw();

}




