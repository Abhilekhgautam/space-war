//
// Created by abhilekh on 2022-02-01.
//

#ifndef SPACE_WAR_ENTITYMANAGER_H
#define SPACE_WAR_ENTITYMANAGER_H

#include <memory>
#include <algorithm>
#include <vector>
#include "Entity.h"

typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map<std::string, EntityVec> EntityMap;


class EntityManager {

    EntityVec m_entities;
    EntityVec m_entitiesToAdd;

    EntityMap m_entitiesMap;
    size_t    m_totalEntities;

    void removeDeadEntities(EntityVec& );

public:
    EntityManager();
    void update();
    std::shared_ptr<Entity> addEntity(std::string tag);
    EntityVec getEntities();
    EntityVec getEntities(std::string tag);

};


#endif //SPACE_WAR_ENTITYMANAGER_H
