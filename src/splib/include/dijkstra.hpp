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


inline
void
arma_to_graph(const int n_vert, arma::mat& arc_mat, graph_t& node_list)
{
    // const int k = graph_mat.n_cols;

    node_list.clear();
    node_list.resize(n_vert);

    for (int i=0; i < static_cast<int>(arc_mat.n_rows); i++) {
        int src_ind  = std::move(arc_mat(i,0)); // source
        int dest_ind = std::move(arc_mat(i,1)); // destination
        double cost  = std::move(arc_mat(i,2));  // cost

        node_list[src_ind].push_back({std::move(dest_ind), std::move(cost)});
    }
}

namespace dijkstra {

    void arma_to_graph(arma::mat& graph_mat, graph_t& node_list);
    void compute_paths(const int source_ind, const graph_t& node_list, std::vector<double>& min_distance, std::vector<int>& path_list);
    std::list<int> get_shortest_path(int vertex, const std::vector<int>& path_list, const int min_vertex_val = -1);

}
