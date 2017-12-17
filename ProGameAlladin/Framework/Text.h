#ifndef __TEXT_H__

#define __TEXT_H__
#include "definitions.h"
#include "Graphics.h"
#include "Rect.h"
#include "Node.h"
NS_JK_BEGIN

class Text: public Node
{
public:
	Text();
	Text(const LPCSTR fontName, const string& text, const float& x, const float& y, const int& fontWidth, const int& fontHeight, const UINT fontWeight, const Color& color);


	~Text();

	void update() override;
	void render() override;

	void draw();
	static RECT converttoRect(const Rect& rect);

#pragma region GET-SET
	void setText(const string& text);
	string getText() const;

	/*
	Set kích thước chữ
	*/
	void setFontHeight(const int& fontheight);
	int getFontHeight() const;

	/*
	Set kích thước chữ
	*/
	void setFontWidth(const int& fontwidth);
	int getFontWidth() const;

	/*
	Set độ đậm chữ
	@fontW: có thể sử dụng các mẫu FW_NORMAL, FW_BOLD, FW_LIGHT
	*/
	void setFontWeight(const UINT& fontW);
	UINT getFontWeight() const;

	/*
	Set chữ có nghiêng hay không
	*/
	void setItalic(const bool& italic);
	bool isItalic() const;

	/*
	Set canh lề cho chữ
	@align: DT_LEFT, DT_CENTER, DT_RIGHT, DT_WORDBREAK, v.v..
	*/
	void setTextAlign(DWORD align);
	DWORD getTextAlign() const;

	/*
	Set màu cho chữ
	*/
	void setColor(const Color& color);
	Color getColor() const;

	void setFontName(const LPCSTR fontName);
	LPCSTR getFontName()const;
#pragma endregion 


private:
	ID3DXFont *_font;
	LPCSTR _fontName;
	string _text;

	int _height;
	int _width;
	UINT _weight;
	bool _italic;
	DWORD _textAlign;
	Color _color;

	Rect _textRect;

	void updateFont();
};

NS_JK_END

#endif //__TEXT_H__