def reverse_letters_in_each_word(text):
    words = text.split() 
    reversed_words = []

    for word in words:
        reversed_word = word[::-1]
        reversed_words.append(reversed_word)

    return " ".join(reversed_words)


def main():
    user_input = input("Enter a string: ")
    output = reverse_letters_in_each_word(user_input)
    print("Reversed output:", output)


if __name__ == "__main__":
    main()
