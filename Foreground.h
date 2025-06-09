#ifndef FOREGROUND_H__
#define FOREGROUND_H__

class Foreground
{
public:
	Foreground();
	~Foreground();
	Foreground(const Foreground&) = delete;
	Foreground& operator=(const Foreground&) = delete;
	Foreground(Foreground&&) = default;
	Foreground& operator=(Foreground&&) = default;

};

#endif