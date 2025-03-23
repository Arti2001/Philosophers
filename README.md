# 🏛️ Philosophers  

## Overview  
**Philosophers** is a simulation of the **Dining Philosophers Problem**, a classic synchronization problem in computer science. The goal is to manage multiple philosophers who alternate between **eating, thinking, and sleeping** while sharing limited resources (forks) without causing deadlocks or starvation.  

## Features  
- **Multi-threaded simulation** using `pthread`.  
- **Mutex synchronization** to avoid data races.  
- **Handles different numbers of philosophers dynamically.**  
- **Prevents deadlocks and starvation.**  

## Compilation  
To compile the project, run:  
  make
## Run the program with:
  ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [optional: number_of_meals_to_eat_for_each_philo]

## Problem Explanation
  Philosophers sit in a circle at a table.

  Each philosopher needs two forks to eat.

  A fork can only be used by one philosopher at a time.

  Philosophers alternate between thinking, eating, and sleeping.

## Implementation
  Threads: Each philosopher is a separate thread.

  Mutexes: Forks are protected using mutex locks.

  Time Management: The simulation ensures philosophers follow the timing constraints.
