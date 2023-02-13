import string

def longest_words():
    with open("text.txt", 'r') as f:
        text = f.read()
        words = text.split()

        longest = sorted(words, key=len, reverse=True)[:2]

        return longest


print(longest_words())
