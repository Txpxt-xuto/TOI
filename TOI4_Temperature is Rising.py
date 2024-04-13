"""
TASK: hotel
LANG: Python
AUTHOR: Tapat Toungsakul
CENTER: Home
"""
size = int(input())
x,y = [int(i) for i in input().split()]
grid = [[100 for _ in range(size+2)]] + [[100]+[int(i) for i in input().split()]+[100] for _ in range(size)] + [[100 for _ in range(size+2)]]

cango = []

def solve(x,y):
    global cango
    number = grid[y][x]
    if number == 100:
        return
    cango.append(number)
    if number < grid[y][x+1]:
        solve(x+1,y)
    if number < grid[y][x-1]:
        solve(x-1,y)
    if number < grid[y+1][x]:
        solve(x,y+1)
    if number < grid[y-1][x]:
        solve(x,y-1)
solve(x,y)
print(max(cango))