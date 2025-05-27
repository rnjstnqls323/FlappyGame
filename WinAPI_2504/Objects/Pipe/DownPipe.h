#pragma once

class DownPipe : public Pipe
{
public :
	DownPipe();
	~DownPipe();

private:
	void CreatePipe() override;
};