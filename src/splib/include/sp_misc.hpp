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
arma_to_graph(const llint_t n_vert, arma::mat& arc_mat, graph_t& node_list)
{
    // const int k = graph_mat.n_cols;

    node_list.clear();
    node_list.resize(n_vert);

    for (sp::llint_t i=0; i < static_cast<sp::llint_t>(arc_mat.n_rows); i++) 
    {
        sp::llint_t src_ind  = std::move(arc_mat(i,0)); // source
        sp::llint_t dest_ind = std::move(arc_mat(i,1)); // destination
        double cost  = std::move(arc_mat(i,2));  // cost

        node_list[src_ind].push_back({std::move(dest_ind), std::move(cost)});
    }
}

//

inline
std::list<llint_t>
get_shortest_path(llint_t vertex, const std::vector<sp::llint_t>& path_list, const llint_t min_vertex_val = -1L)
{
    std::list<sp::llint_t> path;

    for ( ; vertex != min_vertex_val; vertex = path_list[vertex]) {
        path.push_front(vertex);
    }

    return path;
}
