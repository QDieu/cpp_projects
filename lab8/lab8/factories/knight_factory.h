#pragma once

class knight_factory : public base_factory {
public:
	Hero * create_character() override;
};