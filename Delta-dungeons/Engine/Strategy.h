#include <memory>
#include "ColliderComponent.h"
#include "main.h"

class Strategy
{
public:    
	ENGINE_API Strategy();
	ENGINE_API virtual ~Strategy() = default;
	ENGINE_API Strategy(Strategy const& other) = delete;
	ENGINE_API Strategy(Strategy&& other) = delete;
	ENGINE_API Strategy& operator=(Strategy const& other) = delete;
	ENGINE_API Strategy& operator=(Strategy&& other) = delete;

    ENGINE_API virtual void actCollision(std::shared_ptr<ColliderComponent> collider, int x, int y, KeyCodes direction) = 0;
private:
};