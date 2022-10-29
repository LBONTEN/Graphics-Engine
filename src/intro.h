//
// Created by teryjacky on 13/05/19.
//

#ifndef GRAPHICS_ENGINE_INTRO_H
#define GRAPHICS_ENGINE_INTRO_H

#include <vector>
#include <string>

#include "easy_image.h"
#include "ini_configuration.h"

std::vector<unsigned int> zeroToTwofiftyfive(std::vector<double> color);
img::EasyImage generate_intro_rectangle(unsigned int width, unsigned int height);
img::EasyImage generateIntroBlocks(unsigned int width, unsigned int height, unsigned int rows, unsigned int columns, std::vector<unsigned int> color1, std::vector<unsigned int> color2, bool invert);
img::EasyImage generate_image(const ini::Configuration &configuration);

#endif //GRAPHICS_ENGINE_INTRO_H
