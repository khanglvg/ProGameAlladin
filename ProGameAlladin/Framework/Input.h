#ifndef __INPUT_H__

#define __INPUT_H__

#include "definitions.h"
#include "dinput.h"

NS_JK_BEGIN

enum MyKey {
	KEY_NONE,
	KEY_BACKSPACE,
	KEY_DELETE,
	KEY_TAB,
	KEY_RETURN,
	KEY_ESCAPE,
	KEY_SPACE,
	KEY_KEYPAD_0,
	KEY_KEYPAD_1,
	KEY_KEYPAD_2,
	KEY_KEYPAD_3,
	KEY_KEYPAD_4,
	KEY_KEYPAD_5,
	KEY_KEYPAD_6,
	KEY_KEYPAD_7,
	KEY_KEYPAD_8,
	KEY_KEYPAD_9,
	KEY_KEYPAD_PERIOD,
	KEY_KEYPAD_DIVIDE,
	KEY_KEYPAD_MULTIPLY,
	KEY_KEYPAD_MINUS,
	KEY_KEYPAD_PLUS,
	KEY_KEYPAD_ENTER,
	KEY_KEYPAD_EQUALS,
	KEY_UP_ARROW,
	KEY_DOWN_ARROW,
	KEY_LEFT_ARROW,
	KEY_RIGHT_ARROW,
	KEY_INSERT,
	KEY_HOME,
	KEY_END,
	KEY_PAGE_UP,
	KEY_PAGE_DOWN,
	KEY_F1,
	KEY_F2,
	KEY_F3,
	KEY_F4,
	KEY_F5,
	KEY_F6,
	KEY_F7,
	KEY_F8,
	KEY_F9,
	KEY_F10,
	KEY_F11,
	KEY_F12,
	KEY_F13,
	KEY_F14,
	KEY_F15,
	KEY_ALPHA_0,
	KEY_ALPHA_1,
	KEY_ALPHA_2,
	KEY_ALPHA_3,
	KEY_ALPHA_4,
	KEY_ALPHA_5,
	KEY_ALPHA_6,
	KEY_ALPHA_7,
	KEY_ALPHA_8,
	KEY_ALPHA_9,
	KEY_COMMA,
	KEY_MINUS,
	KEY_PERIOD,
	KEY_SLASH,
	KEY_COLON,
	KEY_SEMICOLON,
	KEY_EQUALS,
	KEY_LEFTBRACKET,
	KEY_BACKSLASH,
	KEY_RIGHTBRACKET,
	KEY_A,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,
	KEY_NUM_LOCK,
	KEY_CAPS_LOCK,
	KEY_RIGHT_SHIFT,
	KEY_LEFT_SHIFT,
	KEY_RIGHT_CONTROL,
	KEY_LEFT_CONTROL,
	KEY_RIGHT_ALT,
	KEY_LEFT_ALT,
	KEY_RIGHT_WINDOWS,
	KEY_LEFT_WINDOWS,
	END_ENUM,
};

// Reference: phucmt97
class Input
{
	friend class Application;

public:

	// Constructor
	Input();

	// Virtual Destructor
	virtual ~Input();

	// getInstance for Input class
	static Input* getInstance();
	


#pragma region CHECK KEY (INT)
	// To check this key is DOWN
	// param:	int my keyCode
	// return 	bool
	bool getKey(const int keyCode) const;

	// To check the key was DOWN in last frame is the same in this frame
	// param:	int my keyCode
	// return:	bool
	bool isKeyDown(const int keyCode) const;

	// To check the key was UP in last frame is the same in this frame
	// param:	int my keyCode
	// return:	bool
	bool isKeyUp(const int keyCode) const;
#pragma endregion 



#pragma region CHECK KEY (STRING)
	// To check this key is DOWN
	// param:	string my keyCode
	// return 	bool
	bool getKey(const string& keyName) const;

	// To check the key was UP in last frame is the same in this frame
	// param:	string my keyCode
	// return:	bool
	bool isKeyDown(const string& keyName) const;

	// To check the key was UP in last frame is the same in this frame
	// param:	string my keyCode
	// return:	bool
	bool isKeyUp(const string& keyName) const;
#pragma endregion 


	// TODO: check it later
	bool isAnyKey() const;
	bool isAnyKeyDown() const;


	void initialize();
	void update();
	void release();
		
	

	

private:

#pragma region DECLARE VARIABLE
	// Input is a singleton
	static Input* _instance;

	// Save what key is downed in this frame.
	char _keyDown[256];

	//Save what key was downed in last frame.
	char _oldKeyDown[256];
	
	// key-value <=> my keycode - directX's keycode
	map<int, int> _keysMapInt;
	map<string, int> _keysMapString;

	HINSTANCE _hInstance;		// Handle of game instance
	HWND _hWnd;
	LPDIRECTINPUT8 _directXInput;  // The DirectX Input Object
	LPDIRECTINPUTDEVICE8 _directXInputKeyboard; // The DirectX Input Device
#pragma endregion 



#pragma region METHOD
	// To check keyCode in this frame is DOWN using directX
	// param:	int keyCode
	// return:	bool
	bool directXKeyDown(const int keyCode) const;

	// To check keyCode in last frame is DOWN using directX
	// param:	int keyCode
	// return:	bool
	bool oldDirectXKeyDown(const int keyCode) const;

	// Init for DirectX Input
	void initDirectXInput();

	// Init for keys Map
	void initDirectXKeysMap();

	void releaseDirectXInput();

	//convert my keycode to directX's keycode
	int convertToDirectXKey(const int keyCode) const;

	//convert my keycode to directX's keycode
	int convertToDirectXKey(const string& keyName) const;
#pragma endregion 


};

NS_JK_END

#endif __INPUT_H__

