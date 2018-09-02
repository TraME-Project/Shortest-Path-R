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

namespace dijkstra {

    void compute_path(const llint_t source_ind, const llint_t dest_ind, const graph_t& node_list, 
                      std::vector<double>& min_distance, std::vector<llint_t>& path_list, 
                      comptime_t* time_spent);

    void compute_paths(const llint_t source_ind, const graph_t& node_list, 
                       std::vector<double>& min_distance, std::vector<llint_t>& path_list,
                       comptime_t* time_spent);

    void compute_paths_robust(const llint_t source_ind, const graph_t& node_list, 
                              std::vector<double>& min_distance, std::vector<llint_t>& path_list);

}
