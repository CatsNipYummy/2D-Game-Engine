#include "collisionmanager.h"
#include <string>

std::vector<Collision> CollisionManager::m_vCollisionComponents;

void CollisionManager::addCollision(Collision *collision) {
    CollisionManager::m_vCollisionComponents.push_back(*collision);
}

std::vector<Collision> &CollisionManager::getAllCollisions() {
    return CollisionManager::m_vCollisionComponents;
}

void CollisionManager::checkCollision(Collision *collision) {

    for (int i = 0; i < (int) m_vCollisionComponents.size(); i++) {
        Collision currentCollision = m_vCollisionComponents[i];

        if (strcmp(collision->name().c_str(), currentCollision.name().c_str()) != 0) {

            // AABB Test

            SDL_Rect rect1 = collision->rect();
            SDL_Rect rect2 = currentCollision.rect();

            if (rect1.w > 0 && rect2.w > 0) {
                if (rect1.x < rect2.x + (rect2.w * 2) &&
                    rect1.x + (rect1.w * 2) > rect2.x &&
                    rect1.y < rect2.y + (rect2.h * 2) &&
                    (rect1.h * 2) + rect1.y > rect2.y) {

/*
                    //Right collision check
                    if( rect1.x + (rect1.w) >= rect2.x)
                    {
                        float t=rect1.x + (rect1.w)-rect2.x;
                        if(rect1.y+(rect1.h)>=rect2.y)
                        {
                          float d=rect1.y+(rect1.h)-rect2.y;
                          if(d>t)
                          {
                              collision->setTop(true);
                              std::cerr<<"HIt from top\n";
                          }
                          else if(d<=t)
                          {
                              collision->setRight(true);
                              std::cerr<<"HIt from right\n";
                          }
                        }
                        else if(rect1.y<=rect2.y+(rect2.h))
                        {
                            float d=rect2.y+(rect2.h)-rect1.y;
                            if(d>t)
                            {
                                collision->setBottom(true);
                                std::cerr<<"HIt from bottom\n";
                            }
                            else
                            {
                                collision->setRight(true);
                                std::cerr<<"HIt from right\n";
                            }
                        }
                    }
                    //Left check
                    else if(rect1.x <= rect2.x + (2*rect2.w))
                    {
                        float t=-(rect2.x + (2*rect2.w)-rect1.x);
                        if(rect1.y+(rect1.h)>=rect2.y)
                        {
                          float d=rect1.y+(rect1.h)-rect2.y;
                          if(d>t)
                          {
                              collision->setTop(true);
                              std::cerr<<"HIt from top\n";
                          }
                          else
                          {
                              collision->setLeft(true);
                              std::cerr<<"HIt from left\n";
                          }
                        }
                        else if(rect1.y<=rect2.y+(rect2.h))
                        {
                            float d=rect2.y+(rect2.h)-rect1.y;
                            if(d>t)
                            {
                                collision->setBottom(true);
                                std::cerr<<"HIt from bottom\n";
                            }
                            else
                            {
                                collision->setLeft(true);
                                std::cerr<<"HIt from left\n";
                            }
                        }
                    }*/



//                    std::cerr<<"Collided"<< (rect1.x + rect1.w);
                    collision->setCollide(true);
                    currentCollision.setCollide(true);
                }
                else {
                    collision->setLeft(false);
                    collision->setRight(false);
                    collision->setBottom(false);
                    collision->setTop(false);
                    collision->setCollide(false);
                    currentCollision.setCollide(false);
                }
            }
        }

    }
}

bool CollisionManager::checkCollision(SDL_Rect a, SDL_Rect b)
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

