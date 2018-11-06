#pragma once

class mage_factory : public base_factory {
public:
	Hero * create_character() override;
};