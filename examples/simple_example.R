
library(SPR)

n <- 6
source_ind <- 1

arcs_mat <- rbind(c(1,2,7),
                  c(1,3,9),
                  c(1,6,14),
                  c(2,3,10),
                  c(2,4,15),
                  c(3,4,11),
                  c(3,6,2),
                  c(4,5,6),
                  c(5,6,9))

dijkstra(n,source_ind,arcs_mat)
