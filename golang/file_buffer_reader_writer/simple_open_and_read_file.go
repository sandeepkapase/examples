package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"log"
	"os"
)

func main() {

	/* Method 1 Read while file. Better for small size file */

	data, err := ioutil.ReadFile("/tmp/test.go")
	if err != nil {
		fmt.Println("File reading error", err)
		return
	}
	fmt.Println("Method 1 Contents of file:")
	fmt.Println(string(data))

	/* Method 2 Open file and read chunk of data from file */
	f, err := os.Open("/tmp/test.go")
	if err != nil {
		log.Fatal(err)
	}
	defer func() {
		if err = f.Close(); err != nil {
			log.Fatal(err)
		}
	}()
	r := bufio.NewReader(f)
	b := make([]byte, 4096)
	for {
		n, err := r.Read(b)
		if err != nil {
			fmt.Println("Error reading file:", err)
			break
		}
		fmt.Println("Method 2 Data", string(b[0:n]))
	}
}
