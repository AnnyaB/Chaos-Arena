## Game Overview
- Language used : C++
  
- Part1 provided so far actually does not involve a heap data structure/heap sorting. Instead, it’s primarily focused on:
- Entity Management: Managing entities like players and enemies in a 2D space using classes.
- Rendering and Graphics: Using SFML to render and display sprites, along with basic interactions.
- Basic Collision and Health Mechanics: Entities can "attack" one another based on collision detection, reducing health and displaying a health bar.

## Implementing heap data structure and heap sorting to build the same 

- Using a max-heap structure to sort entities based on priority each turn.
- Heapifying the list of entities so that each entity action in the game loop follows an ordered priority (like speed / remaining health).
- Sorting and processing entities in O(nlogn) time complexity per game loop cycle.
- Part2 is an updated version 







