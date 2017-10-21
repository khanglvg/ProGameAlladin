#ifndef _COLOR_H__

#define __COLOR_H__
#define WHITE			Color(255, 255, 255, 255)
#define BLACK			Color(0, 0, 0, 255)
#define TRANSPARENT		Color(0, 0, 0, 0)
#define GRAY			Color(127.5, 127.5, 127.5)
#define RED				Color(255, 0, 0, 255)
#define GREEN			Color(0, 255, 0, 255)
#define BLUE			Color(0, 0, 255, 255)
#define YELLOW			Color(255, 235, 4, 255)
#define ORANGE			Color(255, 127, 0, 255)
#define CYAN			Color(0, 255, 255, 255)
#define MAGENTA			Color(255, 0, 255, 255)

class Color

{
public:
	Color();
	~Color();
	Color(const char& red, const char& green, const char& blue, const char& alpha);

#pragma region GET-SET
	char getRed();
	void setRed(const char& red);
	char getGreen();
	void setGreen(const char& green);
	char getBlue();
	void setBlue(const char& blue);
	char getAlpha();
	void setAlpha(const char& alpha);
#pragma endregion 
private:
	char _red;
	char _green;
	char _blue;
	char _alpha;
};

#endif // _COLOR_H__
