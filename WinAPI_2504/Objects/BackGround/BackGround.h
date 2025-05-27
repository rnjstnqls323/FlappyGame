#pragma once

class BackGround : public RectCollider
{

private:
	const int MAX_FRAME = 3;
public:
	BackGround();
	~BackGround();

	void Update();
	void Render();

private:
	void CreateFrames();
private:
	vector<Quad*> frames;
};