#include <iostream>
#include "flecs.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    ecs_world_t* world = ecs_init();

    struct some_struct {
        int a;
        int b;
    };

    ECS_COMPONENT(world, some_struct);

    std::cout << "Hello component!" << std::endl;

    return 0;
}
