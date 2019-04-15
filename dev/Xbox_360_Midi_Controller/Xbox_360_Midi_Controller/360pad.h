#include <windows.h>
#include <Xinput.h>
#include <math.h>
#include <stdio.h>

class Gamepad
{
private:
	int cId;
	XINPUT_STATE state;

	float deadzoneX;
	float deadzoneY;

	bool held = false;

public:
	Gamepad() : deadzoneX(0.05f), deadzoneY(0.02f) {}
	Gamepad(float dzX, float dzY) : deadzoneX(dzX), deadzoneY(dzY) {}

	float leftStickX;
	float leftStickY;
	float rightStickX;
	float rightStickY;
	float leftTrigger;
	float rightTrigger;

	int  GetPort();
	XINPUT_GAMEPAD *GetState();
	bool CheckConnection();
	bool Refresh();
	int getLeftTriggerValue();
	int getRightTriggerValue();
	bool IsPressed(WORD);
	bool calibrate();

	WORD A = XINPUT_GAMEPAD_A;
	WORD B = XINPUT_GAMEPAD_B;
	WORD Y = XINPUT_GAMEPAD_Y;
	WORD X = XINPUT_GAMEPAD_X;
	WORD RB = XINPUT_GAMEPAD_RIGHT_SHOULDER;
	WORD LB = XINPUT_GAMEPAD_LEFT_SHOULDER;
	WORD DPU = XINPUT_GAMEPAD_DPAD_UP;
	WORD DPD = XINPUT_GAMEPAD_DPAD_DOWN;

};

