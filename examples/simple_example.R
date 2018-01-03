
rm(list=ls())
library(SPR)

n <- 6
source_ind <- 1
dest_ind <- 5

arcs_mat <- rbind(c(1,2,7),
                  c(1,3,9),
                  c(1,6,14),
                  c(2,3,10),
                  c(2,4,15),
                  c(3,4,11),
                  c(3,6,2),
                  c(4,5,6),
                  c(5,6,9))

# Solve using Dijkstra

sol_D <- dijkstra(n,source_ind,arcs_mat)
sol_D
sol_D$min_dist[dest_ind]

get_shortest_path(dest_ind,sol_D$path_list)

# Solve using Bellman-Ford

sol_BF <- bellman_ford(n,source_ind,arcs_mat)
sol_BF
sol_BF$min_dist[dest_ind]

get_shortest_path(dest_ind,sol_BF$path_list)
