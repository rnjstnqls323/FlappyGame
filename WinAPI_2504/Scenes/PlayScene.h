#pragma once

class PlayScene :public Scene
{
private:
	const float PIPE_ON_TIME = 4.0f;
public:
	PlayScene();
	~PlayScene();

	void Update() override;
	void Render() override;

private:
	void PipeOnTime();
private:
	float pipeOnTimer = 0.0f;
	Bird* bird;
	BackGround* backGround;
	Ground* ground;

};