#include "background.h"

background::background() : Entity("BG")
{
    // Character
    this->transform->setPosition({0,0});
    this->transform->setScale({1,1});
//    this->transform->setRect({ 10, 10, 30, 35 });

    m_sSpriteComponent = new Sprite();
    m_sSpriteComponent->setName("Sprite_Component");
    //m_sSpriteComponent->loadSprite("/home/milind/Desktop/2D_Game_Engine/2D-Game-Engine/2D_Game_Engine/Assets/char_running.png");
//    m_sSpriteComponent->loadBMPFromString("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/char_running_bmp.bmp");

//    m_sSpriteComponent->loadSprite("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/char_running.png");
    m_sSpriteComponent->loadSprite("/home/milind/Desktop/2D_Game_Engine/2D-Game-Engine/2D_Game_Engine/Assets/char_running.png");

   // m_sSpriteComponent->loadSprite("/Users/anil/Game Dev/2D_Engine/2D-Game-Engine/2D_Game_Engine/Assets/char_idle2.png");


    SDL_Rect srcrect = {0, 0, 60, 82 };
    SDL_Rect dstrect = { 0, 0, 60, 82 };

    m_sSpriteComponent->setFrame(dstrect);
    m_sSpriteComponent->setSubRect(srcrect);
    this->addComponent(m_sSpriteComponent);

    m_aAnimation = new Animation();
    m_aAnimation->setName("Animation_Component");
    m_aAnimation->setSprite(m_sSpriteComponent);
    this->addComponent(m_aAnimation);

    EntityManager::addEntity(this);

    // Set Velocity
    m_fVelocityX = 2.0f;
    m_fVelocityY = -2.0f;
}

void background::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };

    //Set clip rendering dimensions
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}

