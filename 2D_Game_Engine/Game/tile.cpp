#include "tile.h"

Tile::Tile(int x, int y, int tileType) : Entity("Tile" +x+y)
{
    this->transform->setPosition({x,y});
    this->transform->setScale({1,1});
    m_TileSpriteComponent=new Sprite();
    m_TileSpriteComponent->setName("Tile_Sprite_"+x+y);
    m_TileSpriteComponent->setFrame({x,y,80,80});
    m_Type=tileType;
    //Temp loading sprite
    m_TileSpriteComponent->loadSprite("/home/milind/Desktop/2D_Game_Engine/2D-Game-Engine/2D_Game_Engine/Assets/pink.png");
    this->addComponent(m_TileSpriteComponent);
    EntityManager::addEntity(this);
}

void Tile::update(float deltaTime, Transform* transform, SDL_Rect &camera)
{
    if(CollisionManager::checkCollision(camera, m_TileSpriteComponent->frame()))
    {
        m_TileSpriteComponent->update(deltaTime, transform,m_TileSpriteComponent->frame().x-camera.x, m_TileSpriteComponent->frame().y-camera.y);
    }
}

