package main

import (
	"encoding/json"
	"fmt"
)

type Result struct {
	//status int // original line
	Status int `json:status` // FIX
}

/* Fix the output of this program
output should be : result=&{status:0}
*/

func main() {
	var data = []byte(`{"status": 200}`)
	result := &Result{}

	if err := json.Unmarshal(data, result); err != nil {
		fmt.Println("error:", err)
		return
	}

	fmt.Printf("result=%+v", result)
}
