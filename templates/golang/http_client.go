package main

import "fmt"
import "net/http"

func main() {
	jsonData := map[string]string{"firstname": "Nic", "lastname": "Raboy"}
	jsonValue, _ := json.Marshal(jsonData)
	request, _ := http.NewRequest("POST", "https://httpbin.org/post", bytes.NewBuffer(jsonValue))
	fmt.Println("vim-go")
}
