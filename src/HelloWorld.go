package main

import "C"

//export HelloWorld
func HelloWorld() string {
	return "Hello World!"
}

func main() {
}