#include "../../ESGLib.h"

class Bullet{

public:

	bool Initialize();
	void Finalize();
	void Update();
	void Draw();

	Vector2 GetSize(){

		return this->imagesize * this->scale;

	}

	Rect GetRect(){

		Vector2 size = this->GetSize();

		Rect rect;

		rect.left = (int)this->position.x;
		rect.top = (int)this->position.y;
		rect.right = (int) (this->position.x + size.x);
		rect.bottom = (int) (this->position.y + size.y);

		return rect;

	}

	void SetPosition(Vector3 position){
	
		this->position = position;

	};

	void SetAngle(float angle){

		this->angle = angle;

	}

	void SetDisplaySize(Vector2 size){

		this->displaysize = size;

	}

	bool IsDisplayOut();

private:

	Vector3 position;
	SPRITE sprite;

	float angle;
	float power;

	Vector2 imagesize;
	float scale;
	Vector2 displaysize;

};