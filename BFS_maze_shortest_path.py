from pyamaze import maze,agent
from queue import Queue
import math


# def create_maze(start_label, end_label):
#     m = maze(10,10)
#     m.CreateMaze(loopPercent=50)
#     a = agent(m, filled=True, footprints=True)
#
#     maze_map = m.maze_map
#
#     path = BFS(start_label, end_label, maze_map)
#
#     for coordinates in path:
#         a.position = coordinates
#
#     m.run()
#     return m

# 1 -można iść

def go_up(node, maze):

    if node[0] == 1:
        return None
    #print('upper Node')
    #print(upper_node)

    possible_going_up = maze[node]['N']
    if possible_going_up:
        upper_node = (node[0]-1, node[1])
        return upper_node
    else:
        return None


def go_down(node, maze, maze_size):

    if node[0] == maze_size:
        return None

    possible_going_down = maze[node]['S']

    if possible_going_down:
        lower_node = (node[0] +1 , node[1])
        return lower_node
    else:
        return None


def go_left(node, maze):

    if node[1] == 1:
        return None

    possible_going_left = maze[node]['W']

    if possible_going_left:
        left_node = (node[0], node[1]-1)
        return left_node
    else:
        return None


def go_right(node, maze, maze_size):

    if node[1] == maze_size:
        return None

    possible_going_right = maze[node]['E']

    if possible_going_right:
        right_node = (node[0], node[1]+1)
        return right_node
    else:
        return None


def get_adjacent(node, maze, maze_size):

    adj = []

    adj.append(go_up(node, maze))
    adj.append(go_down(node, maze, maze_size))
    adj.append(go_left(node, maze))
    adj.append(go_right(node, maze, maze_size))

    return [a for a in adj if a is not None]


def bfs(start_node, target_node, maze, maze_size):

    parent = dict()
    parent[start_node] = None

    visited = []
    q = Queue()
    q.put(start_node)

    path_found = False

    while q:
        node = q.get()
        visited.append(node)

        if node == target_node:
            path_found = True
            print("Target found")
            break


        adjacent = get_adjacent(node, maze,maze_size)

        for a in adjacent:
            if a not in visited:
                parent[a] = node
                q.put(a)

    path = []

    if path_found:
        path.append(target_node)
        while parent[target_node] is not None:
            path.append(parent[target_node])
            target_node = parent[target_node]
        path.reverse()
    return path


if __name__ == '__main__':

    maze_size = 30

    start_node = (1, 1)
    end_node = (maze_size, maze_size)

    m = maze(maze_size, maze_size)
    m.CreateMaze(loopPercent=50)
    a = agent(m, filled=True, footprints=True)

    maze_map = m.maze_map
    print(m.maze_map)

    path = bfs(start_node, end_node, maze_map, maze_size)
    print(path)

    for coordinates in path:
        a.position = coordinates

    m.run()

