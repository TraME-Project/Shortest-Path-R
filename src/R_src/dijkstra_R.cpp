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

        sp::arma_to_graph(as<sp::llint_t>(n_R),arcs_mat,arc_list);

        std::vector<double> min_distance;
        std::vector<sp::llint_t> path_list;
        sp::comptime_t algo_runtime;

        sp::dijkstra::compute_paths(as<sp::llint_t>(source_ind_R), arc_list, min_distance, path_list, &algo_runtime);

        //

        for (sp::llint_t i=0; i < path_list.size(); i++) {
            path_list[i]++;
        }

        double runtime_out = algo_runtime.count();

        return Rcpp::List::create(Rcpp::Named("min_dist") = min_distance,Rcpp::Named("path_list") = path_list,
                                  Rcpp::Named("elapsed_time") = runtime_out);
    } catch( std::exception &ex ) {
        forward_exception_to_r( ex );
    } catch(...) {
        ::Rf_error( "SPR: C++ exception (unknown reason)" );
    }
    return R_NilValue;
}

SEXP dijkstra_simp_R(SEXP n_R, SEXP source_ind_R, SEXP dest_ind_R, SEXP arcs_R)
{
    try {
        sp::graph_t arc_list;
        arma::mat arcs_mat( REAL(arcs_R), Rf_nrows(arcs_R), Rf_ncols(arcs_R), false, true );

        const sp::llint_t dest_ind = as<sp::llint_t>(dest_ind_R);

        sp::arma_to_graph(as<sp::llint_t>(n_R),arcs_mat,arc_list);

        std::vector<double> min_distance;
        std::vector<sp::llint_t> path_list;
        sp::comptime_t algo_runtime;

        sp::dijkstra::compute_path(as<sp::llint_t>(source_ind_R), dest_ind, arc_list, min_distance, path_list, &algo_runtime);
        std::list<sp::llint_t> opt_path = sp::get_shortest_path(dest_ind, path_list);

        double runtime_out = algo_runtime.count();

        return Rcpp::List::create(Rcpp::Named("min_dist") = min_distance[dest_ind],Rcpp::Named("path_list") = opt_path,
                                  Rcpp::Named("elapsed_time") = runtime_out);
    } catch( std::exception &ex ) {
        forward_exception_to_r( ex );
    } catch(...) {
        ::Rf_error( "SPR: C++ exception (unknown reason)" );
    }
    return R_NilValue;
}
