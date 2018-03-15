#include "Bullet.h"
#include <typeinfo>

bool Bullet::Initialize(){

	this->sprite = GraphicsDevice.CreateSpriteFromFile(_T("bullet.png"));

	if (typeid(this->sprite) == typeid(CNullSprite)) return false;

	this->imagesize = Vector2(512.0f,512.0f);
	this->scale = 0.05f;

	this->position = Vector3(640,360,0);
	this->angle = 180.0f;//Šp“x
	this->power = 30.0f;  //‘¬‚³

	Viewport view = GraphicsDevice.GetViewport();
	this->displaysize = Vector2_Zero;
	this->displaysize.x = view.Width;
	this->displaysize.y = view.Height;

	return true;

}

void Bullet::Finalize(){

//	GraphicsDevice.ReleaseSprite(this->sprite);

}

void Bullet::Update(){

	Vector3 movement = Vector3_Zero;

	movement.x = MathHelper_Sin(this->angle);
	movement.y = MathHelper_Cos(this->angle);

	movement *= this->power;

	this->position += movement;

}

void Bullet::Draw(){

	SPRITE sp = this->sprite;
	Vector3 pos = this->position;

	SpriteBatch.Begin();

	SpriteBatch.Draw(*sp,pos,1.0f,Vector3_Zero,Vector3_Zero,this->scale);

	SpriteBatch.End();

}

bool Bullet::IsDisplayOut(){

	Vector2 size = this->GetSize();

	Rect displayrect = Rect();

	displayrect.right = this->displaysize.x;
	displayrect.bottom = this->displaysize.y;

	Rect myrect = this->GetRect();

	if (displayrect.left > myrect.right || displayrect.top > myrect.bottom||
		displayrect.right < myrect.left || displayrect.bottom< myrect.top){

		return true;

	}

	return false;

}