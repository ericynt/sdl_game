#include "Map.hpp"
#include "TextureManager.hpp"

int lvl1[20][25] = {
    {0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2},
    {0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {0,0,0,0,1,1,1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,2,2,2,1,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,1,2,2,2,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,1,2,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,2},
    {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,2,2},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

Map::Map()
{
    dirt = TextureManager::LoadTexture("resources/dirt.png");
    grass = TextureManager::LoadTexture("resources/grass.png");
    water = TextureManager::LoadTexture("resources/water.png");

    LoadMap(lvl1);

    src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;

    dest.x = dest.y = 0;
}

void Map::LoadMap(int arr[20][25])
{
    for (int row = 0; row < 20; row++) 
    {
        for (int column = 0; column < 25; column++) 
        {
            map[row][column] = arr[row][column];
        }
    }
}

void Map::DrawMap()
{
    int type = 0;

    for (int row = 0; row < 20; row++) 
    {
        for (int column = 0; column < 25; column++) 
        {
            type = map[row][column];

            dest.x = column * 32;
            dest.y = row * 32;

            switch (type)
            {
                case 0: 
                    TextureManager::Draw(water, src, dest);
                    break;
                case 1:
                    TextureManager::Draw(grass, src, dest);
                    break;
                case 2:
                    TextureManager::Draw(dirt, src, dest);
                    break;
                default:
                    break;
            }
        }
    }   
}