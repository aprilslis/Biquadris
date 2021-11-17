# Biquadris

Biquadris is a two people Tetris game. Game ends with one person's inability of placing a new block down. 
The game has different 4 levels that have different difficulty levels(different sequence of new blocks popping up, different weight of the block, etc) and different score keeping mechanism.
Player shall also be able to gain special powers by clearing the blocks.

# Available Commands

## Command-line options:
  ``` 
  -text 
  ```
  disables graphic display (player game in text-only mode)
  ```
  -seed xxx
  ```
  sets the random number generator’s seed to xxx
  ```
  -scriptfile1 xxx
  ```
  sets game to use file xxx as the default source of blocks instead of sequence1.txt for player 1
  `
  -scriptfile2 xxx
  `
  sets game to use file xxx as the default source of blocks instead of sequence1.txt for player 2
  `
  startlevel n
  `
  starts game in level n

## In-game commands:
  `
  left`
  
  moves current block left by 1 column
  `
  right
  `
  moves current block right by 1 column
  `
  down
  `
  moves current block down by 1 row
  `
  clockwise
  `
  rotates current block clockwise for 90 degrees
  `
  counterclockwise`
  rotates current block counterclockwise for 90 degrees
  `levelup`
  levels game up by 1 level for the current player
  `leveldown`
  levels game up by 1 level for the current player
  `norandom file`
  sets the block input non-random and use input from file (only effective in level 3 and 4)
  `random`
  sets the block input random (only effective in level 3 and level 4)
  `equence file`
  executes the sequence of commands in file
  `I,J,L,O,S,T,Z`
  replaces current block with a new block with the input type
  `restart`
  restarts the game
  `hint`
  provides a hint/suggestion for the player to clear a row

## Special actions (triggered when the player clears more than 2 rows):
  `heavy`
  makes the opponent’s next block extra heavy(move down by 2 blocks) during 1 action
  `blind`
  blinds the opponent’s board, from columns 3-9, and from rows 3-12 until the current block is dropped
  `force x`
  forces the opponent’s current block to become a new block with type x
