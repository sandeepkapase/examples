package main

import "fmt"

func main() {
	var inputArray []int = []int{3, 6, 36, 32, 32, 121, 66, 24, 26, 371, 661, 6, 4, 8}
	//var input int = 0
	var lastProfit int = 0

	/*for true {
		fmt.Scanf("%d", &input)
		if input == -1 {
			break
		}
		inputArray = append(inputArray, input)
	}*/

	size := len(inputArray)
	if size < 2 {
		return
	}

	for i, j := 0, 0; i < size; {
		for j = i; j+1 < size && inputArray[j] <= inputArray[j+1]; j++ {
		}
		if i != j {
			currentProfit := inputArray[j] - inputArray[i]
			if currentProfit > lastProfit {
				lastProfit = currentProfit
			}
		}
		i = j + 1
	}

	//fmt.Println(size)
	//fmt.Println(inputArray)
	fmt.Println(lastProfit)
}
