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

#include "sp.hpp"

//

void
sp::dijkstra::compute_path(const llint_t source_ind, const llint_t dest_ind, const graph_t& node_list, 
                           std::vector<double>& min_distance, std::vector<llint_t>& path_list, 
                           comptime_t* time_spent)
{
    const llint_t n = node_list.size();

    min_distance.resize(n, max_weight);
    min_distance[source_ind] = 0.0;

    path_list.resize(n, -1);

    std::set<std::pair<double, llint_t>> vertex_queue;
    std::vector<bool> unvisited_set(n,true);

    vertex_queue.insert(std::make_pair(0.0, source_ind));

    //

    bool found_dest = false;

    clocktime_t start_time;
    if (time_spent) {
        start_time = tic();
    }
 
    while (!found_dest && !vertex_queue.empty())
    {
        const double dist_u_from_s = vertex_queue.begin()->first;
        const llint_t u = vertex_queue.begin()->second;

        vertex_queue.erase(vertex_queue.begin());

        for (auto &node_iter : node_list[u])
        {
            llint_t v = node_iter.index;

            if (unvisited_set[v] == true) 
            {
                double distance_through_u = dist_u_from_s + node_iter.weight;

                if (distance_through_u < min_distance[v]) 
                {
                    if (min_distance[v] != max_weight) 
                    {   // avoid spurious search
                        vertex_queue.erase(std::make_pair(min_distance[v], v));
                    }
        
                    min_distance[v] = std::move(distance_through_u);
                    path_list[v] = u;

                    vertex_queue.insert(std::make_pair(min_distance[v], std::move(v)));

                    if (v == dest_ind)
                    {
                        found_dest = true;
                    }
                }
            }
        }

        unvisited_set[u] = false;
    }

    if (time_spent) {
        *time_spent = tic() - start_time;
    }
}

void
sp::dijkstra::compute_paths(const llint_t source_ind, const graph_t& node_list, 
                            std::vector<double>& min_distance, std::vector<llint_t>& path_list,
                            comptime_t* time_spent)
{
    const llint_t n = node_list.size();

    min_distance.resize(n, max_weight);
    min_distance[source_ind] = 0.0;

    path_list.resize(n, -1);

    std::set<std::pair<double, llint_t>> vertex_queue;
    std::vector<bool> unvisited_set(n,true);

    vertex_queue.insert(std::make_pair(0.0, source_ind));

    clocktime_t start_time;
    if (time_spent) {
        start_time = tic();
    }
 
    while (!vertex_queue.empty())
    {
        const double dist_u_from_s = vertex_queue.begin()->first;
        const llint_t u = vertex_queue.begin()->second;

        vertex_queue.erase(vertex_queue.begin());

        for (auto &node_iter : node_list[u])
        {
            llint_t v = node_iter.index;

            if (unvisited_set[v] == true) 
            {
                double distance_through_u = dist_u_from_s + node_iter.weight;

                if (distance_through_u < min_distance[v]) 
                {
                    if (min_distance[v] != max_weight) 
                    {   // avoid spurious search
                        vertex_queue.erase(std::make_pair(min_distance[v], v));
                    }
        
                    min_distance[v] = std::move(distance_through_u);
                    path_list[v] = u;

                    vertex_queue.insert(std::make_pair(min_distance[v], std::move(v)));
                }
            }
        }

        unvisited_set[u] = false;
    }

    if (time_spent) {
        *time_spent = tic() - start_time;
    }
}

// robust (to negative weights) version

// modified verion of MIT-licensed code here:
// https://rosettacode.org/wiki/Dijkstra%27s_algorithm#C.2B.2B

void
sp::dijkstra::compute_paths_robust(const llint_t source_ind, const graph_t& node_list, 
                                   std::vector<double>& min_distance, std::vector<llint_t>& path_list)
{
    const llint_t n = node_list.size();

    min_distance.resize(n, max_weight);
    min_distance[source_ind] = 0.0;

    path_list.resize(n, -1);

    std::set<std::pair<double, llint_t>> vertex_queue;
    vertex_queue.insert(std::make_pair(0.0, source_ind));
 
    while (!vertex_queue.empty())
    {
        double dist_u_from_s = vertex_queue.begin()->first;
        llint_t u = vertex_queue.begin()->second;

        vertex_queue.erase(vertex_queue.begin());

        for (auto &node_iter : node_list[u])
        {
            llint_t v = node_iter.index;

            double distance_through_u = dist_u_from_s + node_iter.weight;

            if (distance_through_u < min_distance[v]) 
            {
                if (min_distance[v] != max_weight) 
                {   // avoid spurious search
                    vertex_queue.erase(std::make_pair(min_distance[v], v));
                }
    
                min_distance[v] = std::move(distance_through_u);
                path_list[v] = u;

                vertex_queue.insert(std::make_pair(min_distance[v], std::move(v)));
            }
        }
    }
}

