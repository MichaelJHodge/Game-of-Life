# Game-of-Life

I attempted to implement Conway's Game of Life in C, in two different ways. 

// Rules // 


// In the Game of Life, there is a grid that contains cells. In the beginning,
// each cell is either "dead" or "alive." The cells then update their own liveness
// in accordance to 4 rules, producing complex behavior:

// 1. Any live cell with 0 or 1 live neighbors becomes dead due to underpopulation
// 2. Any live cell with 2 or 3 live neighbors stays alive because its neighborhood is suitable
// 3. Any live cell with more than 3 live neighbors becomes dead due to overpopulation
// 4. Any dead cell with exactly 3 live neighbors becomes alive from reproduction
