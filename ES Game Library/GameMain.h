#pragma once

#include "ESGLib.h"
#include "GameScene/GameScene.hpp"
#include "MyClasses\okuhama\Player.h"
#include "MyClasses\fujimura\UI.h"
#include "MyClasses\hamada\Enemy.h"
#include "MyClasses\hamada\EnemyBullet.h"
#include "MyClasses\hamada\BulletManager.h"

class GameMain : public CGameScene {
public:
	GameMain() : DefaultFont(GraphicsDevice.CreateDefaultFont())
	{
//		ContentRootDirectory(_T("Content"));
	}

	virtual ~GameMain()
	{
#ifdef _INC_SQUIRREL
		Squirrel.ReleaseAllScripts();
#endif
#ifdef _INC_NUI
		NUI.ReleaseAllKinects();
#endif
#ifdef _INC_LIVE2D
		Live2D.ReleaseAllModels();
#endif
#ifdef _INC_EFFEKSEER
		Effekseer.ReleaseAllEffects();
#endif
#ifdef _INC_DIRECT2D
		Direct2D.ReleaseAllResources();
#endif
		MediaManager.ReleaseAllMedia();

		SoundDevice.ReleaseAllMusics();
		SoundDevice.ReleaseAllSounds();

		GraphicsDevice.ReleaseAllRenderTargets();
		GraphicsDevice.ReleaseAllStateBlocks();
		GraphicsDevice.ReleaseAllFonts();
		GraphicsDevice.ReleaseAllSprites();
		GraphicsDevice.ReleaseAllAnimationModels();
		GraphicsDevice.ReleaseAllModels();
		GraphicsDevice.ReleaseAllVertexBuffers();
		GraphicsDevice.ReleaseAllEffects();

		Finalize();
	}

public:
	virtual bool Initialize();

	virtual int  Update();
	virtual void Draw();

private:
	void Finalize();
	FONT DefaultFont;

private:
	// �ϐ��錾
	Player player;
	Enemy*  enemy;
	Ui  ui;
	BulletManager manager;

	SPRITE enemy_sprite;
	Rect display_rect;

	// �֐��錾


};

//�N���X���@�啶���@�����o�ϐ��@�X�l�[�N�Q�@�����o�����@�p�X�J���@