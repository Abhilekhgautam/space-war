//
// Created by abhilekh on 2022-02-01.
//

#include "Entity.h"

Entity ::Entity(size_t id, const std::string &tag)
         :m_id(id),m_tag(tag){}

bool Entity ::isActive() const {
    return m_active;
}
size_t Entity ::getId() const {
    return m_id;
}

std::string Entity ::getTag() const {
    return m_tag;
}

void Entity ::destroy() {
    m_active = false;
}
