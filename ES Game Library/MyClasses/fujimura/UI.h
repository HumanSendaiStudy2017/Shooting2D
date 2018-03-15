#include "../../ESGLib.h"

class Ui{

public:

	bool Initialize();
	void Finalize();
	void Update();
	void Draw();

	void CountDownStart(){

		this->startflag = true;

	}

	bool IsTimeUp(){

		return (this->time <= 0);

	}

private:

	FONT font;
	int time;

	bool startflag;

};