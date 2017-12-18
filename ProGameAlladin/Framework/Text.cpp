#include "Text.h"
US_NS_JK

Text::Text()
{
}

Text::Text(const LPCSTR fontName, const string& text, const float& x, const float& y, const int& fontWidth, const int& fontHeight, const UINT fontWeight, const Color& color)
{
	_fontName = fontName;
	_text = text;
	_position.setX(x);
	_position.setY(y);	
	_width = fontWidth;
	_height = fontHeight;
	_weight = fontWeight;
	_textAlign = DT_LEFT | DT_NOCLIP;
	_italic = false;
	_color = color;

	_font = nullptr;
	updateFont();
}

Text::~Text()
{
	if (_font)
	{
		_font->Release();
		_font = nullptr;
	}
}

void Text::update()
{
}

void Text::render()
{
	this->draw();
}

void Text::draw()
{
	_textRect.setX(_position.getX());
	_textRect.setY(_position.getY());

	auto rect = converttoRect(_textRect);

	_font->DrawTextA(Graphics::getInstance()->getSprite(),
		_text.c_str(), 
		-1,							// so ki tu mong muon ve ra
		&rect, 
		_textAlign, 
		D3DCOLOR_ARGB(_color.getAlpha(), _color.getRed(), _color.getGreen(), _color.getBlue()));
}


void Text::updateFont()
{
	if (_font)
	{
		_font->Release();
		_font = nullptr;
	}

	HRESULT result = D3DXCreateFont(
		Graphics::getInstance()->getDevice(),			// device
		_height,										// font height
		_width,											// font width
		_weight,										// font weight
		1,												// mip levels
		_italic,										// italic
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		ANTIALIASED_QUALITY,
		FF_DONTCARE,
		_fontName,										// font face
		&_font											// pointer font
	);

	if(SUCCEEDED(result))
	{
		const auto i = 1;
	}
	else
	{
		const auto i = 2;
	}
}

RECT Text::converttoRect(const Rect& rect)
{
	RECT r; //top-left <=> y-x			bottom-right <=> y-x
	r.left = rect.getX();
	r.top = rect.getY();
	r.right = rect.getX() + rect.getWidth();
	r.bottom = rect.getY() + rect.getHeight();

	return r;
}

#pragma region GET-SET
void Text::setText(const string& text)
{
	_text = text;
}

string Text::getText() const
{
	return _text;
}

void Text::setFontHeight(const int& fontheight)
{
	_height = fontheight;
	updateFont();
}

int Text::getFontHeight() const
{
	return _height;
}

void Text::setFontWidth(const int& fontwidth)
{
	_width = fontwidth;
	updateFont();
}

int Text::getFontWidth() const
{
	return _width;
}

void Text::setFontWeight(const UINT& fontW)
{
	_weight = fontW;
	updateFont();
}

UINT Text::getFontWeight() const
{
	return _weight;
}

void Text::setItalic(const bool& italic)
{
	_italic = italic;
	updateFont();
}

bool Text::isItalic() const
{
	return _italic;
}

void Text::setTextAlign(const DWORD align)
{
	_textAlign = align;
}

DWORD Text::getTextAlign() const
{
	return _textAlign;
}

void Text::setColor(const Color& color)
{
	_color = color;
}

Color Text::getColor() const
{
	return _color;
}

void Text::setFontName(const LPCSTR fontName)
{
	_fontName = fontName;
	updateFont();
}

LPCSTR Text::getFontName() const
{
	return _fontName;
}
#pragma endregion 



