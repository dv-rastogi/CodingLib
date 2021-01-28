from collections import deque
def reachTheEnd(n, grid, k):
	m = len(grid[0])
	q = deque()
	vis = []
	dep = []
	moves = [[0, 1], [1, 0], [-1, 0], [0, -1]]
	for i in range(n):
		vis.append([False] * m)
		dep.append([1e9] * m)
	vis[0][0] = True
	dep[0][0] = 0
	q.append((0, 0))
	while len(q) != 0:
		u = q.popleft()
		for j in moves:
			if (u[0] + j[0] >= n) or (u[0] + j[0] < 0) or (u[1] + j[1] >= m) or (u[1] + j[1] < 0) or (grid[u[0] + j[0]][u[1] + j[1]] == '#') or vis[u[0] + j[0]][u[1] + j[1]]:
				continue
			q.append((u[0] + j[0], u[1] + j[1]))
			vis[u[0] + j[0]][u[1] + j[1]] = True
			dep[u[0] + j[0]][u[1] + j[1]] = dep[u[0]][u[1]] + 1
	# print(vis)
	if (dep[-1][-1] <= k) and vis[-1][-1]:
		return "Yes"
	else:
		return "No"

n = int(input())
grid = []
for i in range(n):
	grid.append(input())
k = int(input())
print(reachTheEnd(n, grid, k))