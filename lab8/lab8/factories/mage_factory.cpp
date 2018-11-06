#include "../stdafx.h"
#include "mage_factory.h"

Hero * mage_factory::create_character()
{
	return new mage();
}
