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

SEXP get_shortest_path_R(SEXP dest_ind_R, SEXP path_list_R)
{
    try {

        std::list<int> opt_path = sp::get_shortest_path(as<int>(dest_ind_R), as< std::vector<int> > (path_list_R));

        return wrap(opt_path);
    } catch( std::exception &ex ) {
        forward_exception_to_r( ex );
    } catch(...) {
        ::Rf_error( "SPR: C++ exception (unknown reason)" );
    }
    return R_NilValue;
}
