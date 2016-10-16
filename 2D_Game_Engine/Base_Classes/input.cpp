#include "input.h"
#include<iostream>

Input::Input()
{

}

void Input::getKeyData( SDL_KeyboardEvent *key ){

        if( key->type == SDL_KEYUP )
            std::cerr<<"Released";
        else
            std::cerr<<"Pressed";

        std::cerr<<" "<<SDL_GetKeyName(key->keysym.sym)<<std::endl;
    }

