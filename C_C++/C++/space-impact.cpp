#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Impact");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear(sf::Color::Black);

        // Draw the player's spaceship
        sf::RectangleShape player(sf::Vector2f(50, 50));
        player.setFillColor(sf::Color::Green);
        player.setPosition(375, 525);
        window.draw(player);

        // Draw the enemy spaceships
        sf::RectangleShape enemy1(sf::Vector2f(50, 50));
        enemy1.setFillColor(sf::Color::Red);
        enemy1.setPosition(25, 25);
        window.draw(enemy1);

        sf::RectangleShape enemy2(sf::Vector2f(50, 50));
        enemy2.setFillColor(sf::Color::Red);
        enemy2.setPosition(725, 25);
        window.draw(enemy2);

        // Draw the bullets
        sf::RectangleShape bullet(sf::Vector2f(5, 10));
        bullet.setFillColor(sf::Color::Yellow);
        bullet.setPosition(400, 500);
        window.draw(bullet);

        // Display the window
        window.display();
    }

    return 0;
}
