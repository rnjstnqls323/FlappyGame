#pragma once

class EndScene :public Scene
{
public:
	EndScene();
	~EndScene();

	// Scene을(를) 통해 상속됨
	void Update() override;
	void Render() override;

private:
	BackGround* backGround;
	Ground* ground;
	Quad* gameOver;
};