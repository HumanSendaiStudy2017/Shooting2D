#include "UI.h"
#include <typeinfo>

bool Ui::Initialize(){

	this->font = GraphicsDevice.CreateDefaultFont();
	if (typeid(this->font) == typeid(CDXGNullFont)) return false;

	this->time = 1000 * (90);
	this->startflag = false;
	return true;

}

void Ui::Finalize(){



}

void Ui::Update(){

	if (!this->IsTimeUp()){

		this->time -= GameTimer.GetElapsedMilliSecond();

		if (this->time < 0)this->time = 0;

	}

}

void Ui::Draw(){

	int time = this->time;
	int m = time / (1000 * 60);
	int s = time / 1000 % 60;
	int micro = time % 1000;

	SpriteBatch.Begin();

	SpriteBatch.DrawString(font,Vector2_Zero,Color(255,255,255),_T("%02d:%02d.%03d"),m,s,micro);

	SpriteBatch.End();

}