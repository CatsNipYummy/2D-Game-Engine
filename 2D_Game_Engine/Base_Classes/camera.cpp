#include "camera.h"

Camera::Camera(SDL_Rect rect)
{
    m_rRect = rect;
}

// Get Rect
SDL_Rect Camera::rect() {
    return m_rRect;
}

// Get camera position
int Camera::x() {
    return m_rRect.x;
}

int Camera::y() {
    return m_rRect.y;
}

// Set camera position
void Camera::setX(int x) {
    m_rRect.x = x;
}

void Camera::setY(int y) {
    m_rRect.y = y;
}
