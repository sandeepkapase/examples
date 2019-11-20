package main

import "fmt"
import "net/http"
import "bytes"

type UrlQueryParam struct {
	name string `json:"name" db:"name"`
	id   int    `json:"name" db:"name"`
}

func main() {
	fmt.Printf("\nRest Client")
	client := &http.Client{}
	qParam := UrlQueryParam{name: "sadmin", id: 0x1234}
	jsonStr, _ := json.Marshal(qParam)
	req, err := http.NewRequest("POST", "http://localhost/getAdmin", bytes.NewBuffer(jsonStr))
	client.Do(req)
}
