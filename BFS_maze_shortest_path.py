from pyamaze import maze,agent
from queue import Queue


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


def go_up(node, maze):

    if node[1] == 1:
        return None
    #print('upper Node')
    #print(upper_node)
    #if upper_node in maze: #and maze[node]['N'] == 1:
    possible_directions = maze.get(node)
    possible_going_up = maze[node]['N']
    if possible_going_up:
        upper_node = (node[0], node[1] - 1)
        return upper_node
    else:
        return None


def go_down(node, maze):
    upper_node = (node[0], node[1] + 1)
    if upper_node in maze and maze[node]['S'] == 1:
        return upper_node
    else:
        return None


def go_left(node, maze):
    upper_node = (node[0]-1, node[1])
    if upper_node in maze and maze[node]['W'] == 1:
        return upper_node
    else:
        return None


def go_right(node, maze):
    upper_node = (node[0]+1, node[1])
    if upper_node in maze and maze[node]['E'] == 1:
        return upper_node
    else:
        return None


def get_adjacent(node, maze):

    adj = []

    adj.append(go_up(node, maze))
    adj.append(go_down(node, maze))
    adj.append(go_left(node, maze))
    adj.append(go_right(node, maze))

    return [a for a in adj if a is not None]


def bfs(start_node, target_node, maze):

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


        adjacent = get_adjacent(node, maze)

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

    start_node = (1, 1)
    end_node = (9, 9)

    m = maze(10, 10)
    m.CreateMaze(loopPercent=50)
    a = agent(m, filled=True, footprints=True)

    maze_map = m.maze_map
    #print(m.maze_map)

    #maze_map1 = {(1, 1): {'E': 0, 'W': 0, 'N': 0, 'S': 1}, (2, 1): {'E': 1, 'W': 0, 'N': 1, 'S': 0}, (3, 1): {'E': 1, 'W': 0, 'N': 0, 'S': 1}, (4, 1): {'E': 0, 'W': 0, 'N': 1, 'S': 1}, (5, 1): {'E': 1, 'W': 0, 'N': 1, 'S': 1}, (6, 1): {'E': 1, 'W': 0, 'N': 1, 'S': 0}, (7, 1): {'E': 1, 'W': 0, 'N': 0, 'S': 1}, (8, 1): {'E': 0, 'W': 0, 'N': 1, 'S': 1}, (9, 1): {'E': 0, 'W': 0, 'N': 1, 'S': 1}, (10, 1): {'E': 1, 'W': 0, 'N': 1, 'S': 0},
                # (1, 2): {'E': 1, 'W': 0, 'N': 0, 'S': 1}, (2, 2): {'E': 0, 'W': 1, 'N': 1, 'S': 1}, (3, 2): {'E': 1, 'W': 1, 'N': 1, 'S': 1}, (4, 2): {'E': 1, 'W': 0, 'N': 1, 'S': 1}, (5, 2): {'E': 0, 'W': 1, 'N': 1, 'S': 0}, (6, 2): {'E': 1, 'W': 1, 'N': 0, 'S': 0}, (7, 2): {'E': 1, 'W': 1, 'N': 0, 'S': 1}, (8, 2): {'E': 0, 'W': 0, 'N': 1, 'S': 1}, (9, 2): {'E': 1, 'W': 0, 'N': 1, 'S': 1}, (10, 2): {'E': 1, 'W': 1, 'N': 1, 'S': 0},
                # (1, 3): {'E': 1, 'W': 1, 'N': 0, 'S': 1}, (2, 3): {'E': 0, 'W': 0, 'N': 1, 'S': 1}, (3, 3): {'E': 0, 'W': 1, 'N': 1, 'S': 0}, (4, 3): {'E': 1, 'W': 1, 'N': 0, 'S': 1}, (5, 3): {'E': 1, 'W': 0, 'N': 1, 'S': 0}, (6, 3): {'E': 0, 'W': 1, 'N': 0, 'S': 1}, (7, 3): {'E': 1, 'W': 1, 'N': 1, 'S': 0}, (8, 3): {'E': 1, 'W': 0, 'N': 0, 'S': 1}, (9, 3): {'E': 0, 'W': 1, 'N': 1, 'S': 0}, (10, 3): {'E': 1, 'W': 1, 'N': 0, 'S': 0},
                # (1, 4): {'E': 1, 'W': 1, 'N': 0, 'S': 1}, (2, 4): {'E': 0, 'W': 0, 'N': 1, 'S': 1}, (3, 4): {'E': 0, 'W': 0, 'N': 1, 'S': 1}, (4, 4): {'E': 1, 'W': 1, 'N': 1, 'S': 0}, (5, 4): {'E': 0, 'W': 1, 'N': 0, 'S': 1}, (6, 4): {'E': 1, 'W': 0, 'N': 1, 'S': 1}, (7, 4): {'E': 0, 'W': 1, 'N': 1, 'S': 1}, (8, 4): {'E': 0, 'W': 1, 'N': 1, 'S': 0}, (9, 4): {'E': 1, 'W': 0, 'N': 0, 'S': 1}, (10, 4): {'E': 0, 'W': 1, 'N': 1, 'S': 0},
                # (1, 5): {'E': 1, 'W': 1, 'N': 0, 'S': 1}, (2, 5): {'E': 0, 'W': 0, 'N': 1, 'S': 1}, (3, 5): {'E': 0, 'W': 0, 'N': 1, 'S': 1}, (4, 5): {'E': 1, 'W': 1, 'N': 1, 'S': 0}, (5, 5): {'E': 1, 'W': 0, 'N': 0, 'S': 1}, (6, 5): {'E': 0, 'W': 1, 'N': 1, 'S': 1}, (7, 5): {'E': 1, 'W': 0, 'N': 1, 'S': 0}, (8, 5): {'E': 1, 'W': 0, 'N': 0, 'S': 1}, (9, 5): {'E': 0, 'W': 1, 'N': 1, 'S': 0}, (10, 5): {'E': 1, 'W': 0, 'N': 0, 'S': 0},
                # (1, 6): {'E': 1, 'W': 1, 'N': 0, 'S': 1}, (2, 6): {'E': 1, 'W': 0, 'N': 1, 'S': 0}, (3, 6): {'E': 1, 'W': 0, 'N': 0, 'S': 0}, (4, 6): {'E': 0, 'W': 1, 'N': 0, 'S': 1}, (5, 6): {'E': 1, 'W': 1, 'N': 1, 'S': 1}, (6, 6): {'E': 1, 'W': 0, 'N': 1, 'S': 1}, (7, 6): {'E': 1, 'W': 1, 'N': 1, 'S': 1}, (8, 6): {'E': 0, 'W': 1, 'N': 1, 'S': 1}, (9, 6): {'E': 0, 'W': 0, 'N': 1, 'S': 1}, (10, 6): {'E': 1, 'W': 1, 'N': 1, 'S': 0},
                # (1, 7): {'E': 1, 'W': 1, 'N': 0, 'S': 0}, (2, 7): {'E': 1, 'W': 1, 'N': 0, 'S': 0}, (3, 7): {'E': 0, 'W': 1, 'N': 0, 'S': 1}, (4, 7): {'E': 0, 'W': 0, 'N': 1, 'S': 1}, (5, 7): {'E': 1, 'W': 1, 'N': 1, 'S': 0}, (6, 7): {'E': 1, 'W': 1, 'N': 0, 'S': 0}, (7, 7): {'E': 1, 'W': 1, 'N': 0, 'S': 1}, (8, 7): {'E': 1, 'W': 0, 'N': 1, 'S': 0}, (9, 7): {'E': 1, 'W': 0, 'N': 0, 'S': 1}, (10, 7): {'E': 0, 'W': 1, 'N': 1, 'S': 0},
                # (1, 8): {'E': 1, 'W': 1, 'N': 0, 'S': 1}, (2, 8): {'E': 0, 'W': 1, 'N': 1, 'S': 1}, (3, 8): {'E': 0, 'W': 0, 'N': 1, 'S': 1}, (4, 8): {'E': 1, 'W': 0, 'N': 1, 'S': 1}, (5, 8): {'E': 1, 'W': 1, 'N': 1, 'S': 1}, (6, 8): {'E': 0, 'W': 1, 'N': 1, 'S': 0}, (7, 8): {'E': 1, 'W': 1, 'N': 0, 'S': 0}, (8, 8): {'E': 1, 'W': 1, 'N': 0, 'S': 0}, (9, 8): {'E': 0, 'W': 1, 'N': 0, 'S': 1}, (10, 8): {'E': 1, 'W': 0, 'N': 1, 'S': 0},
                # (1, 9): {'E': 1, 'W': 1, 'N': 0, 'S': 0}, (2, 9): {'E': 1, 'W': 0, 'N': 0, 'S': 0}, (3, 9): {'E': 1, 'W': 0, 'N': 0, 'S': 1}, (4, 9): {'E': 0, 'W': 1, 'N': 1, 'S': 0}, (5, 9): {'E': 0, 'W': 1, 'N': 0, 'S': 1}, (6, 9): {'E': 0, 'W': 0, 'N': 1, 'S': 1}, (7, 9): {'E': 1, 'W': 1, 'N': 1, 'S': 0}, (8, 9): {'E': 1, 'W': 1, 'N': 0, 'S': 1}, (9, 9): {'E': 1, 'W': 0, 'N': 1, 'S': 0}, (10, 9): {'E': 1, 'W': 1, 'N': 0, 'S': 0},
                # (1, 10): {'E': 0, 'W': 1, 'N': 0, 'S': 1}, (2, 10): {'E': 0, 'W': 1, 'N': 1, 'S': 0}, (3, 10): {'E': 0, 'W': 1, 'N': 0, 'S': 1}, (4, 10): {'E': 0, 'W': 0, 'N': 1, 'S': 1}, (5, 10): {'E': 0, 'W': 0, 'N': 1, 'S': 1}, (6, 10): {'E': 0, 'W': 0, 'N': 1, 'S': 1}, (7, 10): {'E': 0, 'W': 1, 'N': 1, 'S': 1}, (8, 10): {'E': 0, 'W': 1, 'N': 1, 'S': 0}, (9, 10): {'E': 0, 'W': 1, 'N': 0, 'S': 1}, (10, 10): {'E': 0, 'W': 1, 'N': 1, 'S': 0}}


    path = bfs(start_node, end_node, maze_map)
    print(path)

    for coordinates in path:
        a.position = coordinates

    m.run()

