#pragma once

#include "TileType.hpp"

namespace map
{
	//
	// A tile struct to represent information for a particular tile on the map.
	//
	struct TileInfo
	{
		int x, y;
		TileType tileType;
		bool explored;
		bool blockView;
		bool walkable;
	};
} // end of namespace map
