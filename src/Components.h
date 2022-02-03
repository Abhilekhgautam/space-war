//
// Created by abhilekh on 2022-02-01.
//

#ifndef SPACE_WAR_COMPONENTS_H
#define SPACE_WAR_COMPONENTS_H

#include <SFML/Graphics.hpp>
#include <memory>

class CTransform{
public:

    sf::Vector2f pos {0.0f,0.0f};
    sf::Vector2f vel {20.0f, 20.0f};
    float angle = 2.0f;

    CTransform(sf::Vector2f p, sf::Vector2f v, float a)
       :pos(p), vel(v), angle(a){}

};

class CShape{

public:
    sf::CircleShape circle;

    CShape(float r, size_t point, sf::Color fill, sf::Color outline, float thickness )
         : circle(r, point){

        circle.setFillColor(fill);
        circle.setPointCount(point);
        circle.setOutlineThickness(thickness);
        circle.setOutlineColor(outline);

    }

};

class CCollision{
public:
    float radius = 0.0f;
    explicit CCollision(float r)
      :radius(r){}

};

class CLifespan{

    int total = 0;
    int remaining =0;

public:
    explicit CLifespan(int total)
      :total(total),remaining(total){}

};

class CInput{
public:
    bool up;
    bool down;
    bool left;
    bool right;
    bool shoot;

    CInput():up(false),down(false),left(false),right(false),shoot(false){}

};

#endif //SPACE_WAR_COMPONENTS_H
