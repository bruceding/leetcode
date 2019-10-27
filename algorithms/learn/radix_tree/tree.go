package main

import "fmt"

func longcommonprefix(x, y string) int {
	length := len(x)
	if length > len(y) {
		length = len(y)
	}

	i := 0
	for i < length {
		if x[i] == y[i] {
			i++
		} else {
			break
		}
	}

	return i
}

type Edge struct {
	pre   *Node
	next  *Node
	label string
}
type Node struct {
	leaf bool // is leaf node

	edges []*Edge

	parent *Node
}

func NewNode() *Node {
	node := Node{
		leaf:   false,
		edges:  make([]*Edge, 0),
		parent: nil,
	}
	return &node
}

func (n *Node) isLeaf() bool {
	return n.leaf == true
}
func (n *Node) Insert(x string) {
	length := 0
	expectLen := len(x)
	y := x

walk:
	for {
		if length == expectLen {
			n.leaf = true
			return
		}

		// if len(n.edges) == 0 {
		// next := NewNode()
		// next.leaf = true
		// next.parent = n
		// edge := Edge{n, next, y}
		// n.edges = append(n.edges, &edge)
		// length += len(edge.label)
		// goto walk
		// }

		for _, edge := range n.edges {
			comm := longcommonprefix(edge.label, y)
			if comm == 0 {
				continue
			}

			if comm == len(edge.label) {
				n = edge.next
				length += comm
				y = y[length:]
				goto walk
			}
			// comm < len(edge.label)
			left := edge.label[comm:]
			edge.label = edge.label[:comm]
			next := NewNode()
			next.parent = n
			newEdge := Edge{next, edge.next, left}
			edge.next = next
			next.edges = append(next.edges, &newEdge)

			n = next
			y = y[comm:]
			length += comm
			goto walk
		}

		// if not found edge
		next := NewNode()
		next.leaf = true
		next.parent = n
		edge := Edge{n, next, y}
		n.edges = append(n.edges, &edge)
		length += len(edge.label)
		goto walk
	}

}
func (n *Node) Walk() {
	nodes := make([]*Node, 0)
	for _, edge := range n.edges {
		fmt.Print(edge.label + "\t")
		nodes = append(nodes, edge.next)
	}
	fmt.Print("\n")

	for _, node := range nodes {
		node.Walk()
	}
}
func (n *Node) Search(x string) bool {
	elementsFound := 0
	expectLen := len(x)
	y := x
	for n != nil && elementsFound < expectLen {
		var nextEdge *Edge
		for _, edge := range n.edges {
			comm := longcommonprefix(edge.label, y[elementsFound:])
			// if comm == 0 {
			// continue
			// }

			if comm == len(edge.label) {
				nextEdge = edge
			}
		}

		if nextEdge != nil {
			n = nextEdge.next
			elementsFound += len(nextEdge.label)
		} else {
			n = nil
		}
	}
	return n != nil && n.isLeaf()
}
