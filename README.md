## Chaos Arena: Turn-Based Battle Game with Priority Processing

Welcome to Chaos Arena! This game features a dynamic battle arena where different entities, such as players, enemies, and allies, interact based on their actions' priority. The game utilizes a heap-based priority system to efficiently manage the turn order and actions of entities during each cycle of the game. This results in an engaging experience where actions are performed based on priorities like speed or health. With two versions, basic and DSA based approach.

## Game Overview
- Language used : C++
  
- Part1 provided so far actually does not involve a heap data structure/heap sorting. Instead, it’s primarily focused on:
- Entity Management: Managing entities like players and enemies in a 2D space using classes
- Rendering and Graphics: Using SFML to render and display sprites, along with basic interactions
- Basic Collision and Health Mechanics: Entities can "attack" one another based on collision detection, reducing health and displaying a health bar

## Implementing heap data structure and heap sorting to build the same 

- Using a max-heap structure to sort entities based on priority each turn
- Heapifying the list of entities so that each entity action in the game loop follows an ordered priority (like speed / remaining health)
- Sorting and processing entities in O(nlogn) time complexity per game loop cycle
- Part2 is an updated version 

## Elucidation of Heap Use

- We are using a priority queue with EntityComparator to handle the heap-based ordering
- Each entity’s priority (for instance, speed) determines its place in the max-heap
- update() fills the queue each cycle, sorts entities by highest priority, and processes actions accordingly.
- This setup maintains an efficient O(nlogn) complexity for each game loop iteration by leveraging a heap-based priority queue for sorting entities by their turn order.
- The rest of the game code (rendering, event processing) remains largely unaffected, with the heap providing an organized, priority-driven entity processing structure.


## How the Game Works
- 1. Heap-Based Priority Queue
Chaos Arena uses a max-heap priority queue to process entities based on their action priority, such as speed or health. Each turn, the entities are ordered by their priority, and their actions (like attacking) are processed in the correct order.

Max-Heap: The priority queue is implemented as a max-heap using C++'s <queue> library. The heap ensures that entities with the highest priority (based on their speed or health) act first.
Action Priority: The Entity class includes an actionPriority() function that returns an entity’s priority value, which is used by the heap to order actions.
Efficient Sorting: The priority queue sorts entities in O(n log n) time complexity, ensuring that the turn order remains efficient even with many entities.
- 2. Entity Types
Entities are defined by their type and properties. Each entity can be a Player, Enemy, or Ally, and they can have attributes such as health, attack power, and speed. During each cycle of the game, the entities act based on their priority.

- 3. Arena Simulation
The game takes place in an arena where entities move, attack, and interact. Entities take turns acting based on their priority in the queue, and their actions can include:

Attacking: Entities can attack each other if they are in proximity.
Interactions: When entities collide, they interact according to their defined behavior.
- 4. Game Loop
The main game loop runs continuously, handling:

Events: Player input (if applicable), such as closing the window.
Updates: The game’s logic, where entities’ actions are processed in turn order.
Rendering: The visual update, where entities are drawn on the screen.

## Game Installation
To run Chaos Arena on your machine, follow these steps to install the game:

## Requirements:

C++ Compiler: A C++11-compatible compiler (such as GCC, Clang, or MSVC).
SFML Library: The game uses the SFML library for window management, graphics, and event handling.

## 1. Install SFML
Windows:
Download the SFML library from SFML Downloads.
Follow the installation instructions for your compiler.
Linux:
Use the package manager to install SFML. For Ubuntu/Debian:


sudo apt-get install libsfml-dev
macOS:
You can use Homebrew to install SFML:

brew install sfml

## 2. Clone the Repository
Clone the repository to your local machine using Git:


git clone https://github.com/AnnyaB/chaos-arena.git

## 3. Compile the Game
Navigate to the project directory and compile the game using your preferred C++ compiler.

For example, using g++:


cd chaos-arena
g++ -std=c++11 -o chaos-arena *.cpp -lsfml-graphics -lsfml-window -lsfml-system

## 4. Run the Game
After compilation, run the game executable:


./chaos-arena
The game window should open, and you will be able to play.

## How to Play
Chaos Arena is a turn-based battle arena where different entities fight using their predefined attributes (health, speed, attack power). Here's how to interact with the game:

## Objective
Your goal is to control entities (players, enemies, and allies) and make strategic decisions during each turn based on their priorities. Defeat all enemies and be the last one standing to win.

## Entity Actions
Entities act based on their priority, which is calculated using their speed or health (depending on the game design). The entity with the highest priority will act first.

During each turn, entities will:

Move towards their targets.
Attack enemies in their range.
Perform other actions based on their AI or player input (if controlling the entity).

## Controls
Mouse/Keyboard: You may use the mouse or keyboard to interact with the game window, such as closing it or adjusting settings. In more advanced versions, keyboard controls could be added to let the player directly control certain entities.

Thank you for playing Chaos Arena! I hope you enjoy the unique priority-based gameplay and challenge yourself with strategic decisions in the arena! If you have any questions or want to contribute, feel free to open an issue or pull request on the project’s GitHub repository.



