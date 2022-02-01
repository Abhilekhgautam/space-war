//
// Created by abhilekh on 2022-02-01.
//

#ifndef SPACE_WAR_ENTITY_H
#define SPACE_WAR_ENTITY_H

#include "Components.h"


class Entity {

     friend class EntityManager;
     size_t m_id;
     bool m_active = true;
     std::string m_tag = "Default";

public:

    std::shared_ptr<CTransform> cTransform;
    std::shared_ptr<CShape> cShape;
    std::shared_ptr<CCollision> cCollision;
    std::shared_ptr<CLifespan> cLifespan;

    bool isActive() const;
    std::string getTag() const;
    size_t getId() const;
    void destroy();

    Entity(size_t id, const std::string& tag)
            :m_id(id), m_tag(tag){}
};


#endif //SPACE_WAR_ENTITY_H
