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





