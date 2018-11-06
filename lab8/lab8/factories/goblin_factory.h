#pragma once

class goblin_factory : public base_factory {
public:
	Hero* create_character() override;
};