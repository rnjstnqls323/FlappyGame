#pragma once

class EndScene :public Scene
{
public:
	EndScene();
	~EndScene();

	// Scene��(��) ���� ��ӵ�
	void Update() override;
	void Render() override;

private:
	BackGround* backGround;
	Ground* ground;
	Quad* gameOver;
};