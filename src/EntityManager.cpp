//
// Created by abhilekh on 2022-02-01.
//

#include "EntityManager.h"

EntityManager :: EntityManager()
               :m_totalEntities(0){}

void EntityManager :: update(){
    // update the entities here

    for(auto& e : m_entitiesToAdd){
        m_entities.push_back(e);
    }
}

std::shared_ptr<Entity> EntityManager ::addEntity(std::string tag) {

    std::shared_ptr<Entity> entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));
    m_entitiesToAdd.push_back(entity);
    return  entity;

}

EntityVec EntityManager ::getEntities() {
    return m_entities;
}

EntityVec EntityManager ::getEntities(std::string tag) {

    //loop through the map and return the entities
    return m_entities;

}