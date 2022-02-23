package main
import "fmt"

func main() {
  var s string = "opa"
  // var s1 string = "opa"
  // var s2 string = "opa"
  var i int = 1
  var k int32 = 2
  var f float64 = 1.5
  var j float32 = 2.5
  // var by byte = 1
  // var bo bool = true
  fmt.Println(i + k)
  
  // fmt.Println(s+s) // String
  // fmt.Println(s+i) // Invalid
  // fmt.Println(s+f) // Invalid
  // fmt.Println(s+by) // Invalid
  // fmt.Println(s+bo) // Invalid
  
  // fmt.Println(i+i) // Int
  // fmt.Println(i+f) // Invalid
  // fmt.Println(i+by) // Invalid
  // fmt.Println(i+bo) // Invalid
  
  // fmt.Println(f+f) // float64
  // fmt.Println(f+by) // Invalid
  // fmt.Println(f+bo) // Invalid
  
  // fmt.Println(by+by) // byte
  // fmt.Println(by+bo) // Invalid
  
  // fmt.Println(bo+bo) // Invalid

  // fmt.Println(i == i) // true
  // fmt.Println(f > i) // Invalid
  // fmt.Println(i == by) // Invalid
  // fmt.Println(s1 == s2) // true
  
  // f = i // Invalid
  fmt.Println(f)
}