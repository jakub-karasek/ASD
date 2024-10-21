# Games (Mecze)
- `mecze.cpp` - solution to Games (Mecze) problem

## Original task description
[original task (in polish)](./Lab_03/mecze.pdf)

## Task:

In a football training session, `n` players participate (where `n` is an even number). In each match, all players play, with `n/2` players in each team. The coach decided to organize the teams in such a way that every two players have a chance to play against each other in at least one match (i.e., they play in opposite teams at least once).

However, in practice, the results are different, as some players, despite the coach's efforts, always play in the same teams in all matches. The largest subset of players who play in the same teams in all matches is called a *clique*.

The coach has already proposed the teams for the next `m` matches. Help him determine how far he is from achieving his goal by finding the size of the largest clique of players.

## Input

- The first line of input contains two integers `n` and `m` (`4 ≤ n ≤ 40,000`, `1 ≤ m ≤ 50`), representing the number of players and the number of scheduled matches, respectively. The players are numbered from 1 to `n`.
- Each of the next `m` lines contains `n` pairwise distinct integers from the range 1 to `n`, describing the team compositions for each match. The first `n/2` numbers in each line are the player numbers for the first team, and the second `n/2` numbers are the player numbers for the second team.

## Output

- Your program should output one integer, the size of the largest clique of players.

## Example
For the input:
```
6 3 
4 6 1 3 5 2 
1 4 5 2 3 6 
1 2 6 4 5 3
```

the correct output is:  1

And for the input:
```
6 3 
4 6 1 3 5 2 
1 4 5 2 3 6 
1 2 3 4 5 6
```

the correct output is:  2

### Explanation of the example:
In the first example, each pair of players plays in opposite teams in one match (e.g., players numbered 1 and 6), in two matches (e.g., players 1 and 2), or even in all three matches (e.g., players 1 and 3). So, the division of players into cliques is: `{1}, {2}, {3}, {4}, {5}, {6}`.

In the second example, players numbered 2 and 3 always play on the same team. So, the division of players into cliques is: `{1}, {2, 3}, {4}, {5}, {6}`.







