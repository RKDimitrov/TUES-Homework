import string

def words7():
    with open("text.txt", 'r') as f:
        text = f.read().translate(str.maketrans('', '', string.punctuation)) #otkradnah go ot google
        words = text.split()
        seven_letter_words = []

        for word in words:
            if len(word) == 7:
                seven_letter_words.append(word)
            

        return seven_letter_words

print(words7())
