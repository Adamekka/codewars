package kata

func ValidBraces(str string) bool {
	var openingBraces []rune

	for _, ch := range str {
		switch ch {
		case '(', '[', '{':
			openingBraces = append(openingBraces, ch)

		case ')', ']', '}':
			if len(openingBraces) == 0 {
				return false
			}

			var last rune = OpeningBraceToClosing(openingBraces[len(openingBraces)-1])
			if ch == last {
				openingBraces = openingBraces[:len(openingBraces)-1]
			} else {
				return false
			}
		}
	}

	return len(openingBraces) == 0
}

func OpeningBraceToClosing(opening rune) rune {
	switch opening {
	case '(':
		return ')'

	case '[':
		return ']'

	case '{':
		return '}'
	}

	return ' '
}
