#pragma once
class SB_DisableUsrInput
{
	bool disableUserInput_Internal = false;
	bool disableUserInput_External = false;
public:
	SB_DisableUsrInput();
	~SB_DisableUsrInput();

	bool getDisableUserInput_Internal(void) const { return disableUserInput_Internal; }
	bool getDisableUserInput_External(void) const { return disableUserInput_External; }

	void setDisableUserInput_Internal(const bool& disableUserInput_Internal){ this->disableUserInput_Internal = disableUserInput_Internal; }
	void setDisableUserInput_External(const bool& disableUserInput_External){ this->disableUserInput_External = disableUserInput_External; }
};