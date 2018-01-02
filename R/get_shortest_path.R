################################################################################
##
##   Copyright (C) 2017-2018 Keith O'Hara
##
##   This file is part of the R package Shortest Path-R (SPR).
##
##   The R package SPR is free software: you can redistribute it and/or modify
##   it under the terms of the GNU General Public License as published by
##   the Free Software Foundation, either version 2 of the License, or
##   (at your option) any later version.
##
##   The R package SPR is distributed in the hope that it will be useful,
##   but WITHOUT ANY WARRANTY; without even the implied warranty of
##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##   GNU General Public License for more details.
##
##   You should have received a copy of the GNU General Public License
##   along with SPR. If not, see <http://www.gnu.org/licenses/>.
##
################################################################################

get_shortest_path <- function(dest_ind,path_list)
{

    dest_ind <- dest_ind - 1   # adjust for zero indexing
    path_list <- path_list - 1 # adjust for zero indexing

    res <- .Call("get_shortest_path_R", dest_ind,path_list, PACKAGE = "SPR")

    return(res+1)
}
