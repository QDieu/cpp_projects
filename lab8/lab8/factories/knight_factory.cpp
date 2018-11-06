#include "../stdafx.h"
#include "knight_factory.h"

Hero * knight_factory::create_character()
{
	return new knight();
}


