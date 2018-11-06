#pragma once
class base_factory
{
public:
	virtual Hero* create_character() = 0;
	virtual ~base_factory();
};

