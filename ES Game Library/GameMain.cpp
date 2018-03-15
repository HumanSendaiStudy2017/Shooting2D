// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"


/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load all of your content.
/// Initialize will enumerate through any components and initialize them as well.
/// </summary>
bool GameMain::Initialize()
{
	// TODO: Add your initialization logic here
	WindowTitle(_T("ES Game Library"));

	enemy_sprite = GraphicsDevice.CreateSpriteFromFile(_T("enemy.png"));

	player.Initialize();
	enemy = new Enemy(enemy_sprite, Vector3(0,0,0));
	ui.Initialize();
	manager = BulletManager();
	Viewport view = GraphicsDevice.GetViewport();
	display_rect = Rect();
	display_rect.right = view.Width;
	display_rect.bottom = view.Height;

	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void GameMain::Finalize()
{
	// TODO: Add your finalization logic here
	delete  enemy;
}

/// <summary>
/// Allows the game to run logic such as updating the world,
/// checking for collisions, gathering input, and playing audio.
/// </summary>
/// <returns>
/// Scene continued value.
/// </returns>
int GameMain::Update()
{
	// TODO: Add your update logic here
	player.UpDate();
	enemy->Update(&manager);
	manager.Update(display_rect);
	ui.Update();

	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_CornflowerBlue);

	GraphicsDevice.BeginScene();

	player.Draw();
	enemy->Draw();
	manager.Draw();
	ui.Draw();

	GraphicsDevice.EndScene();
}
