/*################################################################################
  ##
  ##   Copyright (C) 2017-2018 Keith O'Hara
  ##
  ##   This file is part of Shortest Path-R (SPR).
  ##
  ##   SPR is free software: you can redistribute it and/or modify
  ##   it under the terms of the GNU General Public License as published by
  ##   the Free Software Foundation, either version 2 of the License, or
  ##   (at your option) any later version.
  ##
  ##   SPR is distributed in the hope that it will be useful,
  ##   but WITHOUT ANY WARRANTY; without even the implied warranty of
  ##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  ##   GNU General Public License for more details.
  ##
  ##   You should have received a copy of the GNU General Public License
  ##   along with SPR. If not, see <http://www.gnu.org/licenses/>.
  ##
  ################################################################################*/

#include "SPR.hpp"
using namespace Rcpp;

SEXP dijkstra_R(SEXP n_R, SEXP source_ind_R, SEXP arcs_R)
{
    try {
        sp::graph_t arc_list;
        arma::mat arcs_mat( REAL(arcs_R), Rf_nrows(arcs_R), Rf_ncols(arcs_R), false, true );

        // arma::mat arcs_mat = as<arma::mat>(arcs_R);
        // arcs_mat.cols(0,1) -= 1; 

        sp::arma_to_graph(as<int>(n_R),arcs_mat,arc_list);

        std::vector<double> min_distance;
        std::vector<int> path_list;

        sp::dijkstra::compute_paths(as<int>(source_ind_R), arc_list, min_distance, path_list);

        //

        for (int i=0; i < path_list.size(); i++) {
            path_list[i]++;
        }

        return Rcpp::List::create(Rcpp::Named("min_dist") = min_distance,Rcpp::Named("path_list") = path_list);
    } catch( std::exception &ex ) {
        forward_exception_to_r( ex );
    } catch(...) {
        ::Rf_error( "SPR: C++ exception (unknown reason)" );
    }
    return R_NilValue;
}
