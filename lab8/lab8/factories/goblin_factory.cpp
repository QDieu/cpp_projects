#include "../stdafx.h"
#include "goblin_factory.h"



Hero * goblin_factory::create_character()
{
	return new goblin();
}
