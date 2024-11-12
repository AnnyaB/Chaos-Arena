1. Define Entity Class:
    - Attributes: health, attackPower, defense, distance, speed, priority, type
    - Methods:
        - calculatePriority(): Adjusts priority based on current attributes
        - attack(target): Deals damage based on attackPower and target's defense
        - heal(target): Heals an ally if entity is of healer type
        - move(targetPosition): Changes position based on speed and updates distance
        - specialAbility(): Uses a unique action, may require multi-turn preparation

2. Define Arena Class:
    - Attributes:
        - entities: Heap (priority queue) storing all entities by priority
        - eventQueue: Queue tracking multi-turn events
        - powerUps: List of active power-ups in the arena
    - Methods:
        - initialize(): Sets up arena, adds entities, and places power-ups

3. Game Loop:
    While game is running:
        
        a. Heapify the entities to ensure top-priority entity is at the top.

        b. Process any multi-turn events in eventQueue:
            - If an event is ready, execute it and apply effects (like a charged attack).

        c. Process action for the top-priority entity:
            - Extract top entity from the heap.
            - Determine action based on entity type and current game state:
                - Warrior: attack target if close; otherwise, move toward target.
                - Healer: heal allies with low health; move closer to allies if none are low.
                - Boss: perform special ability if ready; otherwise, attack nearest high-threat entity.
                
            - Recalculate entity's priority after its action.
            - If entity is still alive, reinsert into the heap.
            - If entity is dead, remove from the game.

        d. Apply power-up effects:
            - If entity collected a power-up, apply its effect temporarily.
            - Track duration of power-ups and remove expired effects.

        e. Check game end conditions:
            - If only one team remains, end game.
            - If alternative victory condition met, end game.

4. End Game:
    - Display results based on final state of entities, score, or objectives.
