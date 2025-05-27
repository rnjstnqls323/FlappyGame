#pragma once

class UpPipe :public Pipe
{
public:
	UpPipe();
	~UpPipe();

private:
	void CreatePipe() override;
};