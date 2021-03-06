// stdafx.h: включаемый файл для стандартных системных включаемых файлов
// или включаемых файлов для конкретного проекта, которые часто используются, но
// не часто изменяются
//

#pragma once

#include "targetver.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <tchar.h>
#include <string>
#include <vector>


//Players

#include "characters/Hero.h"
#include "characters/goblin.h"
#include "characters/knight.h"
#include "characters/mage.h"

#include "game/player.h"
#include "game/game.h"

//Factories

#include "factories/base_factory.h"
#include "factories/goblin_factory.h"
#include "factories/knight_factory.h"
#include "factories/mage_factory.h"

using namespace std;