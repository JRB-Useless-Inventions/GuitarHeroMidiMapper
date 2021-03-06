#include "360pad.h"

int Gamepad::GetPort()
{
	return cId + 1;
}

XINPUT_GAMEPAD *Gamepad::GetState()
{
	return &state.Gamepad;
}

bool Gamepad::CheckConnection()
{
	int controllerId = -1;

	for (DWORD i = 0; i < XUSER_MAX_COUNT && controllerId == -1; i++)
	{
		XINPUT_STATE state;
		ZeroMemory(&state, sizeof(XINPUT_STATE));

		if (XInputGetState(i, &state) == ERROR_SUCCESS)
			controllerId = i;
	}

	cId = controllerId;

	return controllerId != -1;
}

// Returns false if the controller has been disconnected
bool Gamepad::Refresh()
{
	if (cId == -1)
		CheckConnection();

	if (cId != -1)
	{
		ZeroMemory(&state, sizeof(XINPUT_STATE));
		if (XInputGetState(cId, &state) != ERROR_SUCCESS)
		{
			cId = -1;
			return false;
		}

		float normLX = fmaxf(-1, (float)state.Gamepad.sThumbLX / 32767);
		float normLY = fmaxf(-1, (float)state.Gamepad.sThumbLY / 32767);

		//leftStickX = (abs(normLX) < deadzoneX ? 0 : (abs(normLX) - deadzoneX) * (normLX / abs(normLX)));
		//leftStickY = (abs(normLY) < deadzoneY ? 0 : (abs(normLY) - deadzoneY) * (normLY / abs(normLY)));

		if (deadzoneX > 0) leftStickX *= 1 / (1 - deadzoneX);
		if (deadzoneY > 0) leftStickY *= 1 / (1 - deadzoneY);

		float normRX = fmaxf(-1, (float)state.Gamepad.sThumbRX / 32767);
		float normRY = fmaxf(-1, (float)state.Gamepad.sThumbRY / 32767);

		//rightStickX = (abs(normRX) < deadzoneX ? 0 : (abs(normRX) - deadzoneX) * (normRX / abs(normRX)));
		//rightStickY = (abs(normRY) < deadzoneY ? 0 : (abs(normRY) - deadzoneY) * (normRY / abs(normRY)));

		if (deadzoneX > 0) rightStickX *= 1 / (1 - deadzoneX);
		if (deadzoneY > 0) rightStickY *= 1 / (1 - deadzoneY);

		leftTrigger = (float)state.Gamepad.bLeftTrigger / 255;
		rightTrigger = (float)state.Gamepad.bRightTrigger / 255;

		return true;
	}
	return false;
}

bool Gamepad::IsPressed(WORD button)
{
	return (state.Gamepad.wButtons & button) != 0;

}

int Gamepad::getLeftTriggerValue()
{
	return float(state.Gamepad.bLeftTrigger);
}

int Gamepad::getRightTriggerValue()
{
	return float(state.Gamepad.bRightTrigger);
}


bool Gamepad::calibrate() {
	//Read all button and pad states for x seconds. These vlaues are there 0 positions
	return false;
}

Button::Button()
{
	
}

void Button::setID(WORD id) {
	this->ID = id;
}

void Button::onAction(int trig) {
	//cout << trig << endl;
	if (trig > 0)
	{
		this->setValue(this->getDefaultValue());
	}
	else {
		this->setValue(0);
	}
}
int Button::getDefaultValue() {
	return this->defaultValue;
}
void Button::setDefaultValue(int x) {
	this->defaultValue = x;
}
int Button::getValue() {
	return this->value;
}
void Button::setValue(int x) {
	this->value = x;
}