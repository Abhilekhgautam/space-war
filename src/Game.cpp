//
// Created by abhilekh on 2022-02-01.
//

#include "Game.h"

Game :: Game(){
    Init();
}

void Game :: Init(){

   m_window.create(sf::VideoMode(1200,800), "Space War");
   m_window.setFramerateLimit(60);

   spawnPlayer();

}

void Game :: Run(){

    while(m_running){

        sf::Event event;
        while(m_window.pollEvent(event)){

            if(event.type == sf ::Event::Closed) {
                m_window.close();
                return;
            }

            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::H){
                    spawnBullet();
                }

                if (event.key.code == sf::Keyboard::Escape){
                    setPause();
                }
            }

        }

        if(!m_paused) {

            m_entities.update();
            spawnEnemy();
            setMovement();
            checkCollision();
            Render();

        }


    }

}

void Game ::spawnPlayer() {

    auto entity = m_entities.addEntity("player");
    entity->cTransform = std::make_shared<CTransform> (sf::Vector2f(m_window.getSize().x / 2, m_window.getSize().y / 2), sf::Vector2f(1.0f, 1.0f), 0.0f);
    entity->cShape = std::make_shared<CShape> (32.0f,3, sf::Color(10,10,10),sf::Color(0,0,255), 4.0f);

    m_player = entity;

}

void Game ::spawnEnemy() {

    srand(time(0));

    auto entity = m_entities.addEntity("enemy");
    entity->cTransform = std::make_shared<CTransform> (sf::Vector2f((rand() % m_window.getSize().x) - 30 , (rand() % m_window.getSize().y) - 30), sf::Vector2f(1.0f, 1.0f), 0.0f);
    entity->cShape = std::make_shared<CShape> (32.0f,rand() % 8, sf::Color(rand() % 255,rand()% 255,rand() % 255),sf::Color(255,0,0), 2.5f);

}

void Game ::spawnBullet() {

//    auto entity = m_entities.addEntity("bullet");
//    entity->cTransform = std::make_shared<CTransform>(sf::Vector2f (m_player->cTransform->pos.x + 15 ,m_player->cTransform->pos.y - 15),sf::Vector2f(0.0f, 0.0f),0.0f);
//    entity->cShape = std::make_shared<CShape>(10.0f,10,sf::Color::Red,sf::Color::Red,0.0f);

}

void Game ::Render() {

    auto entity = m_entities.getEntities();

    m_window.clear();

    for (auto e : entity){
        e->cShape->circle.setPosition(e->cTransform->pos.x, e->cTransform->pos.y);


        m_window.draw(e->cShape->circle);

    }
    m_window.display();
}

void Game ::setPause() {
    m_paused = !m_paused;

}

void Game ::checkCollision() {

    //TODO: Check for collision

}

void Game ::setMovement() {

    //TODO: move enemies randomly and player on key press

}

