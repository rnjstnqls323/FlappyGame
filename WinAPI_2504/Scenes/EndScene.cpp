#include "Framework.h"
#include "EndScene.h"

EndScene::EndScene()
{
	backGround = new BackGround();
	ground = new Ground();
	gameOver = new Quad(L"Resources/Textures/GameOver.png");
	gameOver->SetLocalPosition({ CENTER_X,CENTER_Y });
}

EndScene::~EndScene()
{
	delete backGround;
	delete ground;
	delete gameOver;
}

void EndScene::Update()
{
	backGround->Update();
	ground->Update();
	gameOver->UpdateWorld();
}

void EndScene::Render()
{
	backGround->Render();
	ground->Render();
	gameOver->Render();
}
