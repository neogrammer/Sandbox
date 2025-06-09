#ifndef GUI_H__
#define GUI_H__

class GUI
{
	public:
		GUI();
		~GUI();
		GUI(const GUI&) = delete;
		GUI& operator=(const GUI&) = delete;
		GUI(GUI&&) = default;
		GUI& operator=(GUI&&) = default;
};

#endif