//
// Created by madman on 3/29/23.
//

#include "ECS/CommonECS.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Game
{
public:
    Game()
    {
        Window = new sf::RenderWindow(sf::VideoMode(800, 400), "Deus Engine");
    }

    ~Game()
    {
        delete Window;
    }

    void Start()
    {
        manager.RunStarts();
        HandleFramebuffer();
    }

    static Game& Instance()
    {
        static Game instance;
        return instance;
    }
    Game(Game const&) = delete;
    void operator=(Game const&) = delete;
    sf::RenderWindow *Window;

protected:
    sf::Event event;
    EntityManager manager;

private:
    void HandleFramebuffer()
    {
        while (Window->isOpen())
        {
            while (Window->pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    Window->close();
            }



            Window->display();

            //runs all entity updates
            manager.RunUpdates();


            Window->clear();
        }
    }

};

class Transform : public Component
{
public:
    sf::Vector2f position;
    sf::Vector2f scale;
};

class Renderable : public Component
{
public:
    void OnUpdate() override
    {
        if(Game::Instance().Window != NULL)
        {
            Game::Instance().Window->draw(Body);
        }
    }

protected:
    sf::RectangleShape Body;
};





int main()
{
    Game game;
    Entity player;

    player.AddComponent<Renderable>();

    game.Start();



    return 0;
}