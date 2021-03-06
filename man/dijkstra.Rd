\name{dijkstra}

\alias{dijkstra}

\title{Dijkstra's Algorithm}

\description{
    Solve the shortest path problem using Dijkstra's algorithm.
}

\usage{
dijkstra(n_nodes,source_ind,arcs_matrix,dest_ind=NULL)
}

\arguments{
    \item{n_nodes}{
    The number of nodes in the network}
	\item{source_ind}{
	The source node index.}
	\item{arcs_matrix}{
	A K x 3 matrix of arcs for the network.}
    \item{dest_ind}{
	The destination node index (optional).}
}

\details{
    See \url{https://en.wikipedia.org/wiki/Dijkstra\%27s_algorithm}.
}

\value{
The function returns a list of objects. If the destination node is provided,
    \item{min_dist}{
	The minimum distance solution from the source node to the destination node.}
	\item{path_list}{
	The minimum distance path from source_ind to dest_ind.}
    \item{elapsed_time}{
	Runtime of the algorithm.}

If the destination node is not provided,
\item{min_dist}{
	A numeric vector containing the minimum distance from the source node to other nodes in the network.}
	\item{path_list}{
	The minimum distance path for each node.}
    \item{elapsed_time}{
	Runtime of the algorithm.}
}

\author{Keith O'Hara}

\seealso{
  \code{\link{get_shortest_path}}.
}

\examples{
\dontrun{
arcs <- rbind(c(1,2,7),
              c(1,3,9),
              c(1,6,14),
              c(2,3,10),
              c(2,4,15),
              c(3,4,11),
              c(3,6,2),
              c(4,5,6),
              c(6,5,9))

nbNodes = max(max(arcs[,1]),max(arcs[,2]))

# set source node

s_n <- 1

# run solver

sol <- dijkstra(nbNodes,s_n,arcs)
}
}

\keyword{dijkstra}
\concept{dijkstra}