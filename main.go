package main

import (
	"fmt"
	"os"
	"strings"
)

// invertir texto
func reverse(text string) string {
	runes := []rune(text)
	n := len(runes)
	for i := 0; i < n/2; i++ {
		runes[i], runes[n-1-i] = runes[n-1-i], runes[i]
	}
	return string(runes)
}

// contar vocales y consonantes
func countVowelsConsonants(text string) (map[rune]int, int) {
	vowelMap := map[rune]int{'a': 0, 'e': 0, 'i': 0, 'o': 0, 'u': 0}
	consonants := 0
	spaces := 0

	for _, ch := range strings.ToLower(text) {
		switch ch {
		case 'a', 'e', 'i', 'o', 'u':
			vowelMap[ch]++
		case ' ':
			spaces++
		default:
			consonants++
		}
	}

	return vowelMap, consonants
}

// reemplazar espacios por un caracter
func replaceSpaces(text string, replacement rune) string {
	return strings.ReplaceAll(text, " ", string(replacement))
}

func main() {
	// Verificar que el usuario ingresó un parámetro
	if len(os.Args) != 2 {
		fmt.Println("Insert a text of maximum 100 characters.\nExample: 'Hello world'")
		os.Exit(1)
	}

	text := os.Args[1]
	if len(text) > 100 {
		fmt.Println("Text exceeds 100 characters.")
		os.Exit(1)
	}

	fmt.Println("Original text:", text)

	reversedText := reverse(text)
	fmt.Println("Reversed text:", reversedText)

	vowels, consonants := countVowelsConsonants(text)
	fmt.Printf("Number of Vowels... Total=%d, a=%d, e=%d, i=%d, o=%d, u=%d\n",
		vowels['a']+vowels['e']+vowels['i']+vowels['o']+vowels['u'],
		vowels['a'], vowels['e'], vowels['i'], vowels['o'], vowels['u'])
	fmt.Println("Number of Consonants:", consonants)

	replacedText := replaceSpaces(text, '_')
	fmt.Println("Replaced text:", replacedText)
}
