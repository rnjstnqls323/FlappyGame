#pragma once

class StartScene :public Scene
{
public :
	StartScene();
	~StartScene();

	void Update() override;
	void Render() override;

private:
	BackGround* backGround;
	Ground* ground;
	Bird* bird;
	Quad* title;

};