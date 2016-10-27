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

                    // Collision detected

                    if(rect1.w+rect1.x >= rect2.x && rect1.x + rect1.w<rect2.x+rect2.w)
                        collision->setLeft(true);
                        //std::cerr<<"HIt from left\n";
                    if(rect1.y+rect1.h >=rect2.y && rect1.y+rect1.h<rect2.y+rect2.h)
                        collision->setTop(true);
//                        std::cerr<<"HIt from top\n";

                    if(rect1.x<=rect2.x+rect2.w && rect1.x>rect2.x)
                        collision->setRight(true);
//                        std::cerr<<"HIt from right\n";

                    if(rect1.y<=rect2.y+rect2.h && rect2.y>rect2.y)
                        collision->setBottom(true);
//                        std::cerr<<"HIt from bottom\n";


                    std::cerr<<"Collided"<< (rect1.x + rect1.w);
                    collision->setCollide(true);
                    currentCollision.setCollide(true);
                }

            }

            /*int left1=rect1.x, left2=rect2.x;
            int right1=rect1.x+rect1.w, right2=rect2.x+rect2.w;
            int top1=rect1.y, top2=rect2.y;
            int bottom1=rect1.y+rect1.h, bottom2=rect2.y+rect2.h;
            if(bottom1 <= top2)
            {
                collision->setCollide(false);
                currentCollision.setCollide(false);
            }
            else if(top1 >= bottom2)
            {
                collision->setCollide(false);
                currentCollision.setCollide(false);
            }
            else if( right1 <= left2 )
            {
                collision->setCollide(false);
                currentCollision.setCollide(false);
            }
            else if( left1 >= right2 )
            {
                collision->setCollide(false);
                currentCollision.setCollide(false);
            }
            else
            {
                collision->setCollide(true);
                currentCollision.setCollide(true);
                std::cerr<<"COllided";
            }*/
        }

    }
}
