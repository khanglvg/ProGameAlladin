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

#include "definitions.h"


NS_JK_BEGIN
class Color

{
public:
	Color();
	~Color();
	Color(const unsigned char& red, const unsigned char& green, const unsigned char& blue, const unsigned char& alpha);

#pragma region GET-SET
	unsigned char getRed() const;
	void setRed(const unsigned char& red);
	unsigned char getGreen() const;
	void setGreen(const unsigned char& green);
	unsigned char getBlue() const;
	void setBlue(const unsigned char& blue);
	unsigned char getAlpha() const;
	void setAlpha(const unsigned char& alpha);
#pragma endregion 

	bool operator==(const Color& color) const;


private:
	unsigned char _red;
	unsigned char _green;
	unsigned char _blue;
	unsigned char _alpha;
};
NS_JK_END


#endif // _COLOR_H__
