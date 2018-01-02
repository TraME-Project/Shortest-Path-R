/*################################################################################
  ##
  ##   Copyright (C) 2017-2018 Keith O'Hara
  ##
  ##   This file is part of the Shortest Path C++ library (SPLib).
  ##
  ##   SPLib is free software: you can redistribute it and/or modify
  ##   it under the terms of the GNU General Public License as published by
  ##   the Free Software Foundation, either version 2 of the License, or
  ##   (at your option) any later version.
  ##
  ##   SPLib is distributed in the hope that it will be useful,
  ##   but WITHOUT ANY WARRANTY; without even the implied warranty of
  ##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  ##   GNU General Public License for more details.
  ##
  ################################################################################*/

// modified verion of MIT-licensed code here:
// https://rosettacode.org/wiki/Dijkstra%27s_algorithm#C.2B.2B

#include "sp.hpp"

//

void
sp::dijkstra::compute_paths(const int source_ind, const graph_t& node_list, std::vector<double>& min_distance, std::vector<int>& path_list)
{
    int n = node_list.size();

    min_distance.resize(n, max_weight);
    min_distance[source_ind] = 0;

    path_list.resize(n, -1);

    std::set<std::pair<double, int>> vertex_queue;
    vertex_queue.insert(std::make_pair(min_distance[source_ind], source_ind));
 
    while (!vertex_queue.empty())
    {
        double dist = vertex_queue.begin()->first;
        int u = vertex_queue.begin()->second;

        vertex_queue.erase(vertex_queue.begin());

        for (auto &node_iter : node_list[u])
        {
            int v = node_iter.index;

            double distance_through_u = dist + node_iter.weight;

	        if (distance_through_u < min_distance[v]) {
                if (min_distance[v] != max_weight) { // avoid spurious search
                    vertex_queue.erase(std::make_pair(min_distance[v], v));
                }
    
                min_distance[v] = std::move(distance_through_u);
                path_list[v] = u;

                vertex_queue.insert(std::make_pair(min_distance[v], std::move(v)));
            }
        }
    }
}
 
std::list<int>
sp::dijkstra::get_shortest_path(int vertex, const std::vector<int>& path_list, const int min_vertex_val)
{
    std::list<int> path;

    for ( ; vertex != min_vertex_val; vertex = path_list[vertex]) {
        path.push_front(vertex);
    }

    return path;
}
