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
//m_CollisionDirection

//        if (rect1.x < rect2.x + (rect2.w * 2)) {
//            m_bLeft = true;
//            if (rect1.x + (rect1.w * 2) > rect2.x) {
//                m_bRight = true;
//                if (rect1.y < rect2.y + (rect2.h * 2)) {
//                    m_bTop = true;
//                    if ((rect1.h * 2) + rect1.y > rect2.y) {
//                        m_bBottom = true;



//                    }
//                }
//            }
//        }




                if (rect1.x < rect2.x + (rect2.w * 2) &&
                    rect1.x + (rect1.w * 2) > rect2.x &&
                    rect1.y < rect2.y + (rect2.h * 2) &&
                    (rect1.h * 2) + rect1.y > rect2.y) {

                    // Collision detected
                    std::cerr<<"Collided";
                    collision->setCollide(true);
                    currentCollision.setCollide(true);



                }
            }
        }
    }
}
