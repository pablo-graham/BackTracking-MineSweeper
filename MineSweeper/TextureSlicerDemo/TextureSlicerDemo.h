//
// Created by Pablo Ruiz on 4/24/25.
//

#ifndef MALENATEST_TEXTURESLICERDEMO_H
#define MALENATEST_TEXTURESLICERDEMO_H

#include <Malena/common.hpp>
class TextureSlicerDemo : public ml::Application
{
    sf::Texture texture;
    ml::Rectangle rect;
public:
    TextureSlicerDemo();
    void initialization() override;

    void registerEvents() override;
};


#endif //MALENATEST_TEXTURESLICERDEMO_H
