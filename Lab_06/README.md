# Task: MAL

## Painting the Highway

ASD Laboratory, Lab 6. Available memory: 128 MB. Due date: 08.12.2024, 23:59:59

Professor Makary, in an effort to assist the government of Bajtocja, is voluntarily painting a highway. The highway is 
𝑛 kilometers long and divided into kilometer segments numbered from 1 to 
𝑛. Professor Makary has access to white paint.

Initially, the entire highway is black. Occasionally, when Professor Makary experiences insomnia at night, he goes out to the highway with a bucket of paint and paints a section of it. Unfortunately, sometimes holes appear in the highway, and during the day, a roller comes to lay down new asphalt. The newly paved section naturally becomes black again. Professor Makary wants to keep track of how many kilometers of the highway are painted white at any given time. Help the professor with this important task.

## Input

The first line of input contains an integer 
𝑛 (1 ≤ 
𝑛 ≤ 1,000,000), representing the length of the highway.
The second line contains an integer 
𝑚 (1 ≤ 
𝑚 ≤ 1,000,000), representing the total number of painting nights and paving days.
Each of the following 
𝑚 lines contains two integers 
𝑎 and 
𝑏 (1 ≤ 
𝑎 ≤ 
𝑏 ≤ 
𝑛), defining the endpoints of the segment being modified, and a character 
𝑐. The character 
𝑐 indicates the event: "B" means that Professor Makary painted the highway, and "C" means that the roller paved over it.
## Output

After reading each line, your program should output the number of kilometers painted white.

## Example

For the input:

```
12
4
1 5 C
2 10 B
4 6 B
4 7 C
```
The correct output is:

```
0
9
9
5
```
