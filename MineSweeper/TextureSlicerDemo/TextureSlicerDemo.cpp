//
// Created by Pablo Ruiz on 4/24/25.
//

#include "TextureSlicerDemo.h"

#include "Malena/Utilities/TextureSlicer.h"

TextureSlicerDemo::TextureSlicerDemo()
        : Application(720, 420, 32, "Texture Slicer Demo")
{
}

void TextureSlicerDemo::initialization()
{
    rect.setSize({50.f, 50.f});
    texture.loadFromFile("/Users/pabloruiz/CLionProjects/New_Malena/MineSweeper/TextureSlicerDemo/minesweep_cut.png");
    ml::ImageRects rects = TextureSlicer::getImageRects(texture, 12, 11);
    sf::IntRect intRect = rects.getIntRect(0, 2); /// gets rectangle at row 0, col 2

    rect.setTextureRect(intRect);
    rect.setTexture(&texture);

    addComponent(rect);

}

void TextureSlicerDemo::registerEvents()
{
}
