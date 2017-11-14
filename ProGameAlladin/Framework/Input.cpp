#include "Input.h"
#include "../DirectX/Include/dinput.h"

US_NS_JK

Input* Input::_instance = nullptr;

Input::Input(): _directXInput(nullptr), _directXInputKeyboard(nullptr)
{
}

Input::~Input()
{
}

Input* Input::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Input();
	}

	return _instance;
}

bool Input::getKey(const int keyCode) const
{
	return directXKeyDown(convertToDirectXKey(keyCode));
}

bool Input::isKeyDown(const int keyCode) const
{
	const auto directXKeyCode = convertToDirectXKey(keyCode);
	if (directXKeyDown(directXKeyCode) && !oldDirectXKeyDown(directXKeyCode))
		return true;
	return false;
}

bool Input::isKeyUp(const int keyCode) const
{
	const auto directXKeyCode = convertToDirectXKey(keyCode);
	if (!directXKeyDown(directXKeyCode) && oldDirectXKeyDown(directXKeyCode))
		return true;
	return false;
}

bool Input::getKey(const string& keyName) const
{
	return directXKeyDown(convertToDirectXKey(keyName));
}

bool Input::isKeyDown(const string& keyName) const
{
	const auto directXKeyCode = convertToDirectXKey(keyName);
	if (directXKeyDown(directXKeyCode) && !oldDirectXKeyDown(directXKeyCode))
		return true;
	return false;
}

bool Input::isKeyUp(const string& keyName) const
{
	const auto directXKeyCode = convertToDirectXKey(keyName);
	if (!directXKeyDown(directXKeyCode) && oldDirectXKeyDown(directXKeyCode))
		return true;
	return false;
}

bool Input::isAnyKey() const
{
	for (auto keyCode = 0; keyCode < END_ENUM; ++keyCode) {
		if (getKey(keyCode)) return true;
	}
	return false;
}

bool Input::isAnyKeyDown() const
{
	for (auto keyCode = 0; keyCode < END_ENUM; ++keyCode) {
		if (isKeyDown(keyCode)) return true;
	}
	return false;
}

void Input::initialize()
{
	// setToInitializing();

	initDirectXInput();

	initDirectXKeysMap();

	// setToInitialized();
}

void Input::update()
{
	// refresh last frame keys
	copy(_keyDown, _keyDown + 256, _oldKeyDown);
	_directXInputKeyboard->GetDeviceState(sizeof(_keyDown), static_cast<LPVOID>(&_keyDown));
}

void Input::release()
{
	// setToReleasing();

	releaseDirectXInput();

	// setToReleased();

	// destroy
	delete this;
}




void Input::initDirectXKeysMap()
{
	_keysMapInt.emplace(KEY_NONE, 0);
	_keysMapInt.emplace(KEY_BACKSPACE, DIK_BACKSPACE);
	_keysMapInt.emplace(KEY_DELETE, DIK_DELETE);
	_keysMapInt.emplace(KEY_TAB, DIK_TAB);
	_keysMapInt.emplace(KEY_RETURN, DIK_RETURN);
	_keysMapInt.emplace(KEY_ESCAPE, DIK_ESCAPE);
	_keysMapInt.emplace(KEY_SPACE, DIK_SPACE);
	_keysMapInt.emplace(KEY_KEYPAD_0, DIK_NUMPAD0);
	_keysMapInt.emplace(KEY_KEYPAD_1, DIK_NUMPAD1);
	_keysMapInt.emplace(KEY_KEYPAD_2, DIK_NUMPAD2);
	_keysMapInt.emplace(KEY_KEYPAD_3, DIK_NUMPAD3);
	_keysMapInt.emplace(KEY_KEYPAD_4, DIK_NUMPAD4);
	_keysMapInt.emplace(KEY_KEYPAD_5, DIK_NUMPAD5);
	_keysMapInt.emplace(KEY_KEYPAD_6, DIK_NUMPAD6);
	_keysMapInt.emplace(KEY_KEYPAD_7, DIK_NUMPAD7);
	_keysMapInt.emplace(KEY_KEYPAD_8, DIK_NUMPAD8);
	_keysMapInt.emplace(KEY_KEYPAD_9, DIK_NUMPAD9);
	_keysMapInt.emplace(KEY_KEYPAD_PERIOD, DIK_NUMPADPERIOD);
	_keysMapInt.emplace(KEY_KEYPAD_DIVIDE, DIK_NUMPADSLASH);
	_keysMapInt.emplace(KEY_KEYPAD_MULTIPLY, DIK_NUMPADSTAR);
	_keysMapInt.emplace(KEY_KEYPAD_MINUS, DIK_NUMPADMINUS);
	_keysMapInt.emplace(KEY_KEYPAD_PLUS, DIK_NUMPADPLUS);
	_keysMapInt.emplace(KEY_KEYPAD_ENTER, DIK_NUMPADENTER);
	_keysMapInt.emplace(KEY_KEYPAD_EQUALS, DIK_NUMPADEQUALS);
	_keysMapInt.emplace(KEY_UP_ARROW, DIK_UPARROW);
	_keysMapInt.emplace(KEY_DOWN_ARROW, DIK_DOWNARROW);
	_keysMapInt.emplace(KEY_LEFT_ARROW, DIK_LEFTARROW);
	_keysMapInt.emplace(KEY_RIGHT_ARROW, DIK_RIGHTARROW);
	_keysMapInt.emplace(KEY_INSERT, DIK_INSERT);
	_keysMapInt.emplace(KEY_HOME, DIK_HOME);
	_keysMapInt.emplace(KEY_END, DIK_END);
	_keysMapInt.emplace(KEY_PAGE_UP, DIK_PGUP);
	_keysMapInt.emplace(KEY_PAGE_DOWN, DIK_PGDN);
	_keysMapInt.emplace(KEY_F1, DIK_F1);
	_keysMapInt.emplace(KEY_F2, DIK_F2);
	_keysMapInt.emplace(KEY_F3, DIK_F3);
	_keysMapInt.emplace(KEY_F4, DIK_F4);
	_keysMapInt.emplace(KEY_F5, DIK_F5);
	_keysMapInt.emplace(KEY_F6, DIK_F6);
	_keysMapInt.emplace(KEY_F7, DIK_F7);
	_keysMapInt.emplace(KEY_F8, DIK_F8);
	_keysMapInt.emplace(KEY_F9, DIK_F9);
	_keysMapInt.emplace(KEY_F10, DIK_F10);
	_keysMapInt.emplace(KEY_F11, DIK_F11);
	_keysMapInt.emplace(KEY_F12, DIK_F12);
	_keysMapInt.emplace(KEY_F13, DIK_F13);
	_keysMapInt.emplace(KEY_F14, DIK_F14);
	_keysMapInt.emplace(KEY_F15, DIK_F15);
	_keysMapInt.emplace(KEY_ALPHA_0, DIK_0);
	_keysMapInt.emplace(KEY_ALPHA_1, DIK_1);
	_keysMapInt.emplace(KEY_ALPHA_2, DIK_2);
	_keysMapInt.emplace(KEY_ALPHA_3, DIK_3);
	_keysMapInt.emplace(KEY_ALPHA_4, DIK_4);
	_keysMapInt.emplace(KEY_ALPHA_5, DIK_5);
	_keysMapInt.emplace(KEY_ALPHA_6, DIK_6);
	_keysMapInt.emplace(KEY_ALPHA_7, DIK_7);
	_keysMapInt.emplace(KEY_ALPHA_8, DIK_8);
	_keysMapInt.emplace(KEY_ALPHA_9, DIK_9);
	_keysMapInt.emplace(KEY_COMMA, DIK_COMMA);
	_keysMapInt.emplace(KEY_MINUS, DIK_MINUS);
	_keysMapInt.emplace(KEY_PERIOD, DIK_PERIOD);
	_keysMapInt.emplace(KEY_SLASH, DIK_SLASH);
	_keysMapInt.emplace(KEY_COLON, DIK_COLON);
	_keysMapInt.emplace(KEY_SEMICOLON, DIK_SEMICOLON);
	_keysMapInt.emplace(KEY_EQUALS, DIK_EQUALS);
	_keysMapInt.emplace(KEY_LEFTBRACKET, DIK_LBRACKET);
	_keysMapInt.emplace(KEY_BACKSLASH, DIK_BACKSLASH);
	_keysMapInt.emplace(KEY_RIGHTBRACKET, DIK_RBRACKET);
	_keysMapInt.emplace(KEY_A, DIK_A);
	_keysMapInt.emplace(KEY_B, DIK_B);
	_keysMapInt.emplace(KEY_C, DIK_C);
	_keysMapInt.emplace(KEY_D, DIK_D);
	_keysMapInt.emplace(KEY_E, DIK_E);
	_keysMapInt.emplace(KEY_F, DIK_F);
	_keysMapInt.emplace(KEY_G, DIK_G);
	_keysMapInt.emplace(KEY_H, DIK_H);
	_keysMapInt.emplace(KEY_I, DIK_I);
	_keysMapInt.emplace(KEY_J, DIK_J);
	_keysMapInt.emplace(KEY_K, DIK_K);
	_keysMapInt.emplace(KEY_L, DIK_L);
	_keysMapInt.emplace(KEY_M, DIK_M);
	_keysMapInt.emplace(KEY_N, DIK_N);
	_keysMapInt.emplace(KEY_O, DIK_O);
	_keysMapInt.emplace(KEY_P, DIK_P);
	_keysMapInt.emplace(KEY_Q, DIK_Q);
	_keysMapInt.emplace(KEY_R, DIK_R);
	_keysMapInt.emplace(KEY_S, DIK_S);
	_keysMapInt.emplace(KEY_T, DIK_T);
	_keysMapInt.emplace(KEY_U, DIK_U);
	_keysMapInt.emplace(KEY_V, DIK_V);
	_keysMapInt.emplace(KEY_W, DIK_W);
	_keysMapInt.emplace(KEY_X, DIK_X);
	_keysMapInt.emplace(KEY_Y, DIK_Y);
	_keysMapInt.emplace(KEY_Z, DIK_Z);
	_keysMapInt.emplace(KEY_NUM_LOCK, DIK_NUMLOCK);
	_keysMapInt.emplace(KEY_CAPS_LOCK, DIK_CAPSLOCK);
	_keysMapInt.emplace(KEY_RIGHT_SHIFT, DIK_RSHIFT);
	_keysMapInt.emplace(KEY_LEFT_SHIFT, DIK_LSHIFT);
	_keysMapInt.emplace(KEY_RIGHT_CONTROL, DIK_RCONTROL);
	_keysMapInt.emplace(KEY_LEFT_CONTROL, DIK_LCONTROL);
	_keysMapInt.emplace(KEY_RIGHT_ALT, DIK_RALT);
	_keysMapInt.emplace(KEY_LEFT_ALT, DIK_LALT);
	_keysMapInt.emplace(KEY_RIGHT_WINDOWS, DIK_RWIN);
	_keysMapInt.emplace(KEY_LEFT_WINDOWS, DIK_LWIN);

	_keysMapString.emplace("", 0);
	_keysMapString.emplace("backspace", DIK_BACKSPACE);
	_keysMapString.emplace("delete", DIK_DELETE);
	_keysMapString.emplace("tab", DIK_TAB);
	_keysMapString.emplace("return", DIK_RETURN);
	_keysMapString.emplace("esc", DIK_ESCAPE);
	_keysMapString.emplace("space", DIK_SPACE);
	_keysMapString.emplace("[0]", DIK_NUMPAD0);
	_keysMapString.emplace("[1]", DIK_NUMPAD1);
	_keysMapString.emplace("[2]", DIK_NUMPAD2);
	_keysMapString.emplace("[3]", DIK_NUMPAD3);
	_keysMapString.emplace("[4]", DIK_NUMPAD4);
	_keysMapString.emplace("[5]", DIK_NUMPAD5);
	_keysMapString.emplace("[6]", DIK_NUMPAD6);
	_keysMapString.emplace("[7]", DIK_NUMPAD7);
	_keysMapString.emplace("[8]", DIK_NUMPAD8);
	_keysMapString.emplace("[9]", DIK_NUMPAD9);
	_keysMapString.emplace("[.]", DIK_NUMPADPERIOD);
	_keysMapString.emplace("[/]", DIK_NUMPADSLASH);
	_keysMapString.emplace("[*]", DIK_NUMPADSTAR);
	_keysMapString.emplace("[-]", DIK_NUMPADMINUS);
	_keysMapString.emplace("[+]", DIK_NUMPADPLUS);
	_keysMapString.emplace("[enter]", DIK_NUMPADENTER);
	_keysMapString.emplace("[=]", DIK_NUMPADEQUALS);
	_keysMapString.emplace("up", DIK_UPARROW);
	_keysMapString.emplace("down", DIK_DOWNARROW);
	_keysMapString.emplace("left", DIK_LEFTARROW);
	_keysMapString.emplace("right", DIK_RIGHTARROW);
	_keysMapString.emplace("insert", DIK_INSERT);
	_keysMapString.emplace("home", DIK_HOME);
	_keysMapString.emplace("end", DIK_END);
	_keysMapString.emplace("page up", DIK_PGUP);
	_keysMapString.emplace("page down", DIK_PGDN);
	_keysMapString.emplace("f1", DIK_F1);
	_keysMapString.emplace("f2", DIK_F2);
	_keysMapString.emplace("f3", DIK_F3);
	_keysMapString.emplace("f4", DIK_F4);
	_keysMapString.emplace("f5", DIK_F5);
	_keysMapString.emplace("f6", DIK_F6);
	_keysMapString.emplace("f7", DIK_F7);
	_keysMapString.emplace("f8", DIK_F8);
	_keysMapString.emplace("f9", DIK_F9);
	_keysMapString.emplace("f10", DIK_F10);
	_keysMapString.emplace("f11", DIK_F11);
	_keysMapString.emplace("f12", DIK_F12);
	_keysMapString.emplace("f13", DIK_F13);
	_keysMapString.emplace("f14", DIK_F14);
	_keysMapString.emplace("f15", DIK_F15);
	_keysMapString.emplace("0", DIK_0);
	_keysMapString.emplace("1", DIK_1);
	_keysMapString.emplace("2", DIK_2);
	_keysMapString.emplace("3", DIK_3);
	_keysMapString.emplace("4", DIK_4);
	_keysMapString.emplace("5", DIK_5);
	_keysMapString.emplace("6", DIK_6);
	_keysMapString.emplace("7", DIK_7);
	_keysMapString.emplace("8", DIK_8);
	_keysMapString.emplace("9", DIK_9);
	_keysMapString.emplace(",", DIK_COMMA);
	_keysMapString.emplace("-", DIK_MINUS);
	_keysMapString.emplace(".", DIK_PERIOD);
	_keysMapString.emplace("/", DIK_SLASH);
	_keysMapString.emplace(":", DIK_COLON);
	_keysMapString.emplace(";", DIK_SEMICOLON);
	_keysMapString.emplace("=", DIK_EQUALS);
	_keysMapString.emplace("[", DIK_LBRACKET);
	_keysMapString.emplace("\\", DIK_BACKSLASH);
	_keysMapString.emplace("]", DIK_RBRACKET);
	_keysMapString.emplace("a", DIK_A);
	_keysMapString.emplace("b", DIK_B);
	_keysMapString.emplace("c", DIK_C);
	_keysMapString.emplace("d", DIK_D);
	_keysMapString.emplace("e", DIK_E);
	_keysMapString.emplace("f", DIK_F);
	_keysMapString.emplace("g", DIK_G);
	_keysMapString.emplace("h", DIK_H);
	_keysMapString.emplace("i", DIK_I);
	_keysMapString.emplace("j", DIK_J);
	_keysMapString.emplace("k", DIK_K);
	_keysMapString.emplace("l", DIK_L);
	_keysMapString.emplace("m", DIK_M);
	_keysMapString.emplace("n", DIK_N);
	_keysMapString.emplace("o", DIK_O);
	_keysMapString.emplace("p", DIK_P);
	_keysMapString.emplace("q", DIK_Q);
	_keysMapString.emplace("r", DIK_R);
	_keysMapString.emplace("s", DIK_S);
	_keysMapString.emplace("t", DIK_T);
	_keysMapString.emplace("u", DIK_U);
	_keysMapString.emplace("v", DIK_V);
	_keysMapString.emplace("w", DIK_W);
	_keysMapString.emplace("x", DIK_X);
	_keysMapString.emplace("y", DIK_Y);
	_keysMapString.emplace("z", DIK_Z);
	_keysMapString.emplace("num lock", DIK_NUMLOCK);
	_keysMapString.emplace("caps lock", DIK_CAPSLOCK);
	_keysMapString.emplace("right shift", DIK_RSHIFT);
	_keysMapString.emplace("left shift", DIK_LSHIFT);
	_keysMapString.emplace("right ctrl", DIK_RCONTROL);
	_keysMapString.emplace("left ctrl", DIK_LCONTROL);
	_keysMapString.emplace("right alt", DIK_RALT);
	_keysMapString.emplace("left alt", DIK_LALT);
	_keysMapString.emplace("right win", DIK_RWIN);
	_keysMapString.emplace("left win", DIK_LWIN);
}

void Input::releaseDirectXInput()
{
	if (_directXInputKeyboard) 
	{
		_directXInputKeyboard->Unacquire();	
		_directXInputKeyboard->Release();		
	}

	if (_directXInput) 
	{
		_directXInput->Release();
	}
}


bool Input::directXKeyDown(const int keyCode) const 
{
	// Check if this key (keyCode) is down
	return (_keyDown[keyCode] & 0x80) != 0;
}


bool Input::oldDirectXKeyDown(const int keyCode) const
{
	// Check if last key (keyCode) is down
	return (_oldKeyDown[keyCode] & 0x80) != 0;
}

void Input::initDirectXInput()
{
	//// init DirectX Input
	//HRESULT result = DirectInput8Create(
	//	_hInstance,
	//	DIRECTINPUT_VERSION,
	//	IID_IDirectInput8,
	//	reinterpret_cast<void**>(&_directXInput),
	//	nullptr);
	//


	//// init DirectX Input Keyboard
	//result = _directXInput->CreateDevice(GUID_SysKeyboard, &_directXInputKeyboard, NULL);
	//

	//// acquire Keyboard	
	//result = _directXInputKeyboard->SetDataFormat(&c_dfDIKeyboard);
	//
	//result = _directXInputKeyboard->SetCooperativeLevel(_hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);

	//result = _directXInputKeyboard->Acquire();
	
}


int Input::convertToDirectXKey(const int keyCode) const
{
	// find keyCode in initDirectXKeysMap method and assign it into "it" variable
	const auto it = _keysMapInt.find(keyCode);

	// example: input "KEY_A" export "DIK_A"
	const auto directXCode = it->second;

	//return directX's keycode.
	return directXCode;
}


int Input::convertToDirectXKey(const string& keyName) const
{
	// look back toDirectXKey(int) method
	const auto it = _keysMapString.find(keyName);
	(it != _keysMapString.end());
	const auto directXCode = it->second;
	return directXCode;
}


