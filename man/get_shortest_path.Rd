\name{get_shortest_path}

\alias{get_shortest_path}

\title{Compute Shortest Path to Destination}

\description{
    Solve the shortest path problem using Dijkstra's algorithm.
}

\usage{
get_shortest_path(dest_ind,path_list)
}

\arguments{
	\item{dest_ind}{
	The destination node index.}
	\item{path_list}{
	The minimum distance path for each node, obtained from a shortest path algorithm.}
}

\details{
    The function returns the steps that correspond to the shortest path from a source index to a destination.
}

\value{
The function returns a vector that contains the minimum distance path.
}

\author{Keith O'Hara}

\seealso{
  \code{\link{dijkstra}}.
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

# set source and destination nodes

s_n <- 1
t_n <- 5

# run solver

sol <- dijkstra(nbNodes,s_n,arcs)

sp <- get_shortest_path(t_n,sol$path_list)
}
}

\keyword{get_shortest_path}
\concept{get_shortest_path}