package main

import (
	"container/list"
	"fmt"
)

// 邻接表, 无向图
type Graph struct {
	adj []*list.List
	v   int
}

func NewGraph(v int) *Graph {
	graph := new(Graph)

	graph.v = v
	graph.adj = make([]*list.List, v)

	for i := range graph.adj {
		graph.adj[i] = list.New()
	}

	return graph
}

// addEdge 无向图一条边存两次
func (self *Graph) addEdge(s int, t int) {
	self.adj[s].PushBack(t)
	self.adj[t].PushBack(s)
}

var isFound bool

func (self *Graph) DFS(s int, t int) {
	// 记录已经访问过的节点
	visited := make([]bool, self.v)
	visited[s] = true

	// 记录遍历路径
	prev := make([]int, self.v)
	for i := range prev {
		prev[i] = -1
	}

	isFound = false

	self.recurDfs(s, t, prev, visited)

	if isFound {
		prevPrint(prev, s, t)
	} else {
		fmt.Printf("no path found from %d to %d", s, t)
	}
}

func (self *Graph) recurDfs(s int, t int, prev []int, visited []bool) {
	if isFound {
		return
	}

	visited[s] = true

	if s == t {
		isFound = true
		return
	}

	for e := self.adj[s].Front(); e != nil; e = e.Next() {
		k := e.Value.(int)
		if !visited[k] {
			prev[k] = s
			self.recurDfs(k, t, prev, visited)
		}
	}
}

func prevPrint(prev []int, s int, t int) {
	if s == t || prev[t] == -1 {
		fmt.Printf("%d ", t)
	} else {
		prevPrint(prev, s, prev[t])
		fmt.Printf("%d ", t)
	}
}

func main() {
	graph := NewGraph(8)

	graph.addEdge(0, 1)
	graph.addEdge(0, 3)
	graph.addEdge(1, 2)
	graph.addEdge(1, 4)
	graph.addEdge(2, 5)
	graph.addEdge(3, 4)
	graph.addEdge(4, 5)
	graph.addEdge(4, 6)
	graph.addEdge(5, 7)
	graph.addEdge(6, 7)

	graph.DFS(0, 7)
	fmt.Println()
	graph.DFS(1, 3)
	fmt.Println()
	graph.DFS(0, 9)
	fmt.Println()
}
