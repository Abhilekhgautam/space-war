//
// Created by abhilekh on 2022-02-01.
//

#ifndef SPACE_WAR_GAME_H
#define SPACE_WAR_GAME_H

#include "Components.h"
#include "EntityManager.h"
#include "Entity.h"

class Game {

    sf::RenderWindow m_window;
    EntityManager    m_entities;

    bool             m_paused = false;
    bool             m_running = true;

    void             Init();

    void             spawnPlayer();
    void             spawnEnemy();
    void             spawnBullet();


    void             setPause();
    void             setMovement();
    void             checkCollision();
    void             getInput();
    void             Render();

    std::shared_ptr<Entity> m_player;

public:
                     Game();
    void             Run();


};


#endif //SPACE_WAR_GAME_H
