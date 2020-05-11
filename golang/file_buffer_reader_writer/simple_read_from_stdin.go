package main

import (
	"bufio"
	"fmt"
	"os"
)

/* Note that all methods are usgin r io.Reader for initialization */

func main() {
	/* First Method use fmt.fscanf */
	/// fmt.Printf("%T", os.Stdin) // os.Stdin = os.File ==> File represents an open file descriptor.
	// os.Open(), os.Create() return file pointer
	/*var x string
	n, err := fmt.Fscanf(os.Stdin, "%s", &x)
	fmt.Println(x, n, err)*/

	/* Second Method */
	/*scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		txt := scanner.Text()
		err := scanner.Err()
		fmt.Println(txt, err)
	}*/

	/* Third Method */
	reader := bufio.NewReader(os.Stdin)
	//reader.ReadLine()
	str, err := reader.ReadString('\n')
	fmt.Println("output:", str, "Error:", err)
}
