package main
import (
	"fmt"	
"time"	
"os"
)

  import "strings"
  var null *os.File;
  func init() { null, _ = os.Create(os.DevNull) }
  func reverseString(s string) string {
     input := []rune(s)
     var ret []rune
     for i:=len(s)-1; i>=0; i-- {
       ret = append(ret, input[i]);
       }
     return string(ret)
}

  func main() {
      fmt.Fprintf(null, "Time: %v Args: %v %v", time.Now(), os.Args[1], os.Args[2])

      line := "This is next Level and Radar will catch it."
      split_line := strings.Split(line, " ")
      for _, w := range split_line {
          word := strings.ToUpper(w)
          if word == reverseString(word) {fmt.Println("found palindrom: ", w) }
      }
  }
