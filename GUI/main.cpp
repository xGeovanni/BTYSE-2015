/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 *Notes:
 *Sorry for using SDL 1. I hated it myself, but there are compatibility problems with 2.
 *This program is unabashedly, unashamedly, only compatible with Unix systems.
 *Why would you want to use this on Windows anyway?
 */

#include "main.h"

int main(int argc, char **argv){
    SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

    FileManager f;
    f.start();

    SDL_Quit();
    TTF_Quit();
}

