// Concept: Minimum spanning tree using Prim's algorithm
// Figure out minimum cost of length of road touching all towns
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <iomanip>
#include <unordered_map>
using namespace std;

class State {
  size_t _node;
  double _dist;
  public:
    State( size_t aNode, double aDist ) : _node{aNode}, _dist{aDist} {}
    inline size_t node() const { return _node; }
    inline double dist() const { return _dist; }
};

class AdjacencyList {
  vector < vector<State> > _vert;
  AdjacencyList() = delete;
  public:
    AdjacencyList( istream &input );
    inline size_t size() const { return _vert.size(); }
    inline const vector<State>& vert( size_t node ) const {
      return _vert[node];
    }
    void print();
};

inline bool operator<( const State &a, const State &b ) {
  return a.dist() > b.dist();
}

AdjacencyList::AdjacencyList (istream &input) : _vert{} {
  int nodes, edges;
  input >> nodes >> edges;
  _vert.resize(nodes);

  for (int i=0; i<edges; i++) {
    int index;
    size_t dest;
    double dist;
    input >> index >> dest >> dist;
    _vert[index].push_back(State(dest, dist));
    _vert[dest].push_back(State(index, dist));
  }
}

void AdjacencyList::print() {
  int nodes = size();
  for (int i=0; i<nodes; i++) {
    cout << i << " :";
    vector<State> nbrs = vert(i);
    int nbr = _vert[i].size();
    for (int j=0; j<nbr; j++) {
      cout << "[" << nbrs[j].node() << ":" << nbrs[j].dist() << "]";
    }
    cout << endl;
  }
}

double prim( const AdjacencyList &adj ) {
  std::unordered_map<int, bool> visited;
  std::priority_queue<State> pq;
 
  pq.push( State{ 0, 0.0 } );
  double weight = 0.0;
 
  while( visited.size() < adj.size() ) {
    auto top = pq.top(); pq.pop();
 
    if( visited.count( top.node() ) == 0 ) {
      visited[top.node()] = true;
      weight += top.dist();
 
      for( auto vertex : adj.vert(top.node()) ) {
        pq.push( vertex );
      }
    }
  }
 
  return weight;
}

int main () {

  ifstream input("mst.data/mst.1.in");
  ofstream output("answers.out");

  if( input.is_open() ) {
    auto adj = AdjacencyList{ input };
    output << fixed << setprecision( 8 );
    output << prim( adj ) << "\n";
  } else {
    std::cerr << "Could not open input file\n";
    return 1;
  }
  return 0;
}