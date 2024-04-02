def create_sentence():
    num_words = int(input("How many words do you want in the sentence? "))
    words = []

    for i in range(num_words):
        word = input(f"Enter word {i + 1}: ")
        words.append(word)

    sentence = ' '.join(words)
    print("Your sentence is:", sentence)

create_sentence()
