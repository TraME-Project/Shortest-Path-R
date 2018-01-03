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
sp::bellman_ford::compute_paths(const int source_ind, const graph_t& node_list, std::vector<double>& min_distance, std::vector<int>& path_list)
{
    int n = node_list.size();

    std::vector<std::vector<double>> dist_mat(n + 2, std::vector<double>(n, max_weight));
    std::vector<std::vector<int>> path_mat(n + 2, std::vector<int>(n, -1));

    dist_mat[0][source_ind] = 0;

    for (int i=1; i < n + 2; i++)
    {
        for (int j=0; j < n; j++)
        {
            if (dist_mat[i-1][j] != max_weight) {
                //
                if (dist_mat[i-1][j] < dist_mat[i][j]) {
                    dist_mat[i][j] = dist_mat[i-1][j];
                    path_mat[i][j] = path_mat[i-1][j];
                }

                for (auto &node_iter : node_list[j])
                {
                    if (dist_mat[i-1][j] + node_iter.weight < dist_mat[i][node_iter.index]) {
                        dist_mat[i][node_iter.index] = dist_mat[i-1][j] + node_iter.weight;
                        path_mat[i][node_iter.index] = j;
                    }
                }
                //
            }
        }
    }

    // check for negative-weight cycles

    for (int j=0; j < n; j++)
    {
        if (dist_mat[n+1][j] != dist_mat[n+1][j] ) {
            throw "Graph contains negative weight cycle";
        }
    }

    //

    min_distance = std::move(dist_mat[n]);
    path_list = std::move(path_mat[n]);

}
