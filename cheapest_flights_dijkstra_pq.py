# There are n cities connected by some number of flights.
# You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight
# from city fromi to city toi with cost pricei.
#
# You are also given three integers src, dst, and k, return the cheapest price from src to dst. If there is no such route, return -1.

import copy
import heapq as hq


def cheapest_flight(flights, src, dst, k):

    visited = []
    vertex_price_prev = {}

    unvisited = set()
    for flight in flights:
        unvisited.add(flight[0])
        unvisited.add(flight[1])

    for flight in unvisited:
        vertex_price_prev[flight] = [float('inf'), None]

    vertex_price_prev[src] = [0, None]

    pq = [(0, src)]

    while pq:
        # get the root, discard current distance
        curr_price, current_vertex = hq.heappop(pq)
        # if the node is visited, skip
        if current_vertex in visited:
            continue

        if current_vertex == dst:
            return vertex_price_prev[current_vertex][0]

        # set the node to visited
        visited.append(current_vertex)
        prev = copy.deepcopy(current_vertex)

        for flight in flights:
            if flight[0] == current_vertex and flight[1] not in visited:
                curr_price += flight[2]
                if curr_price < vertex_price_prev[flight[1]][0]:
                    vertex_price_prev[flight[1]][0] = curr_price
                    vertex_price_prev[flight[1]][1] = prev
                    hq.heappush(pq, (curr_price, flight[1]))


if __name__ == '__main__':

    n = 4
    flights = [[0, 1, 100], [1, 2, 100], [2, 0, 100], [1, 3, 600], [2, 3, 200]]
    src = 0
    dst = 3
    k = 1

    flight_cost = cheapest_flight(flights, src, dst, k)
    print(flight_cost)



