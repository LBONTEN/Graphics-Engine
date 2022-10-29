//
// Created by teryjacky on 13/05/19.
//

#include "intro.h"


std::vector<unsigned int> zeroToTwofiftyfive(std::vector<double> color)
{
    std::vector<unsigned int> conversion;
    for(unsigned int i : color)
    {
        conversion.push_back(unsigned (int(i * 255)));
    }
    return conversion;
}


img::EasyImage generate_intro_rectangle(unsigned int width, unsigned int height)
{
    img::EasyImage image(width, height);
    for(unsigned int i = 0; i < width; i++)
    {
        for(unsigned int j = 0; j < height; j++)
        {
            image(i, j).red = i / (width / 255.0);
            image(i, j).green = j / (width / 255.0);
            image(i, j).blue = int (i / (width / 255.0) + j / (width / 255.0)) % 255;
        }
    }
    return image;
}


img::EasyImage generateIntroBlocks(unsigned int width, unsigned int height, unsigned int rows, unsigned int columns, std::vector<unsigned int> color1, std::vector<unsigned int> color2, bool invert)
{
    unsigned int cellWidth = width / columns;
    unsigned int cellHeight = height / rows;

    img::EasyImage image(width, height);
    for(unsigned int i = 0; i < width; i++)
    {
        for(unsigned int j = 0; j < height; j++)
        {
            unsigned int cellX = i / cellWidth;
            unsigned int cellY = j / cellHeight;

            if(invert)
            {
                std::vector<unsigned int> temp = color1;
                color1 = color2;
                color2 = temp;
            }

            if((cellX + cellY) % 2 == 0)
            {
                image(i, j).red = color1[0];
                image(i, j).green = color1[1];
                image(i, j).blue = color1[2];
            }
            else
            {
                image(i, j).red = color2[0];
                image(i, j).green = color2[1];
                image(i, j).blue = color2[2];
            }
        }
    }
    return image;
}


img::EasyImage QuarterCircle(unsigned int height, unsigned int width, unsigned  int n, std::vector<unsigned int> color1, std::vector<unsigned int> color2)
{
    img::EasyImage img(width, height);
    unsigned int distanceX = height / n;
    unsigned int distanceY = width / n;

    for(unsigned int i = 0; i < width; i++)
    {
        for(unsigned int j = 0; j < height; j++)
        {

        }
    }
    return img;
}


img::EasyImage generate_image(const ini::Configuration &configuration)
{
    std::string type = configuration["General"]["type"];
    if(type == "IntroColorRectangle")
    {
        unsigned int width = configuration["ImageProperties"]["width"].as_int_or_die();;
        unsigned int height = configuration["ImageProperties"]["height"].as_int_or_die();;

        return generate_intro_rectangle(width, height);
    }
    else if(type == "IntroBlocks")
    {
        unsigned int width = configuration["ImageProperties"]["width"].as_int_or_die();;
        unsigned int height = configuration["ImageProperties"]["height"].as_int_or_die();;

        std::vector<unsigned int> color1 = zeroToTwofiftyfive(configuration["BlockProperties"]["colorWhite"].as_double_tuple_or_die());
        std::vector<unsigned int> color2 = zeroToTwofiftyfive(configuration["BlockProperties"]["colorBlack"].as_double_tuple_or_die());

        unsigned int rows = configuration["BlockProperties"]["nrXBlocks"].as_int_or_die();
        unsigned int columns = configuration["BlockProperties"]["nrYBlocks"].as_int_or_die();

        bool invert = configuration["BlockProperties"]["invertColors"].as_bool_or_die();

        return generateIntroBlocks(width, height, rows, columns, color1, color2, invert);
    }
    return img::EasyImage();
}
