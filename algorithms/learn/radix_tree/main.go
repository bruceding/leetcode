package main

import "fmt"

func main() {

	root := NewNode()
	root.Insert("test")
	root.Insert("team")
	root.Insert("toast")
	fmt.Println(root.Search("test"))
	fmt.Println(root.Search("toaster"))
	// root.Insert("slow")
	// root.Insert("water")
	// root.Insert("slower")
	root.Walk()
}
