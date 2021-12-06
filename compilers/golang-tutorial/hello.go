package main

import (
	"fmt"
	"math/cmplx"
)

var c, python, java bool
var i, j int = 1, 2

func main() {
	fmt.Println(Hello())

	exportedNames()

	fmt.Println(add(42, 13))

	a, b := swap("hello", "world")
	fmt.Println(a, b)

	fmt.Println(split(17))

	var i int
	fmt.Println(i, c, python, java)

	var c, python, java = true, false, "no!"
	fmt.Println(i, j, c, python, java)

	// Atribuição implícita
	var l, j int = 1, 2
	k := 3
	f, g, h := true, false, "no!"

	fmt.Println(l, j, k, f, g, h)

	var (
		ToBe   bool       = false
		MaxInt uint64     = 1<<64 - 1
		z      complex128 = cmplx.Sqrt(-5 + 12i)
	)

	fmt.Printf("Type: %T Value: %v\n", ToBe, ToBe)
	fmt.Printf("Type: %T Value: %v\n", MaxInt, MaxInt)
	fmt.Printf("Type: %T Value: %v\n", z, z)
}

// Parametros de função
func add(x, y int) int {
	return x + y
}

func Hello() string {
	return "Hello, world"
}

// Retornando tupla
func swap(x, y string) (string, string) {
	return y, x
}

// Nomeando retorno
func split(sum int) (x, y int) {
	x = sum * 4 / 9
	y = sum - x
	return
}
