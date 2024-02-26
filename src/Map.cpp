#include "Map.h"
#include "TextureManager.h"


Map::Map()
{
	src.x = 0;
	src.y = 120;
	src.w = dst.w = 800;
	src.h = dst.h = 600;

	dst.x = dst.y = 0;

	map = TextureManager::TextureAss("assets/map.png");
}

void Map::Mapping()
{
	

	
	TextureManager::Draw(map, src, dst);

}



