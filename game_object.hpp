#pragma once

// Standard lib
#include <sys/types.h>
#include <memory>

#include "model.hpp"

namespace vke {

struct Transform2dComponant {
  glm::vec2 translation{};
  glm::vec2 scale{1.0f, 1.0f};
  float rotation;

  glm::mat2 mat2() {
    const float sin = glm::sin(rotation);
    const float cos = glm::cos(rotation);
    glm::mat2 rotMatrix{{cos, sin}, {-sin, cos}};

    glm::mat2 scaleMat{{scale.x, 0.0f}, {0.0f, scale.y}};
    return rotMatrix * scaleMat;
  }
};

class GameObject {
  public:
  using id_t = unsigned int;

  static GameObject createGameObject() {
    static id_t currentId = 0;
    return GameObject{currentId++};
  }

  GameObject(const GameObject &) = delete;
  GameObject &operator=(const GameObject &) = delete;
  GameObject(GameObject&&) = default;
  GameObject &operator=(GameObject&&) = default;


  const id_t getId() { return id; }

  std::shared_ptr<Model> model{};
  glm::vec3 color{};
  Transform2dComponant transform2d{};

  private:
  
  GameObject(id_t objId) : id{objId} {}
  
  id_t id;
};

}
