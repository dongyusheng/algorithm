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

func (self *Graph) BFS(s int, t int) {
	if s == t {
		return
	}

	// 记录搜索路径
	prev := make([]int, self.v)
	for i := range prev {
		prev[i] = -1
	}

	// 记录已经访问过的节点
	visited := make([]bool, self.v)
	visited[s] = true

	// 记录已经访问过, 但是相邻节点还没有被访问过的节点
	var queue []int
	queue = append(queue, s)

	var isFound bool
	for len(queue) > 0 && !isFound {
		top := queue[0]
		queue = queue[1:]

		// 遍历邻接链表
		for e := self.adj[top].Front(); e != nil; e = e.Next() {
			k := e.Value.(int)

			// 邻边节点没有被访问过
			if !visited[k] {
				prev[k] = top

				// 是目标节点
				if k == t {
					isFound = true
					break
				}

				// 不是目标节点, 更新信息
				queue = append(queue, k)
				visited[k] = true
			}
		}
	}

	if isFound {
		prevPrint(prev, s, t)
	} else {
		fmt.Printf("no path found from %d to %d", s, t)
	}

	return
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

	graph.BFS(0, 7)
	fmt.Println()
	graph.BFS(1, 3)
	fmt.Println()
	graph.BFS(0, 9)
	fmt.Println()
}
