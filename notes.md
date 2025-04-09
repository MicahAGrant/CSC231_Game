# CSC 231 Game Notes
test:
*Itallics*
**Bold**
```
class A {
public: 
    A();
};
```
## Action class
The class to override to take a turn in the game 
```c++
class Action {
public:
    // override perform in a derived class
    virtual Result perform(Engine& engine, std::shared_ptr<Entity> entity) = 0;
};
```

My code goes in the `content` folder. DO NOT EDIT THE ENGINE CODE!!!
ctrl b: finds other code -- declarations to definations -- in functions

Always return from Action 
```C++
return success();
return failure();
return alternative(AnotherAction{});
```

When getting a tile, must call it by reference (Tile&)

Move::perform()
if (door + closed)
    alt(OpenDoor)