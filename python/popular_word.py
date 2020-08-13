import re

""" the function get lines number
    return line number
"""
def get_line_count(string):
    try:
        """try cast input value in int"""
        n = int(input(string))

        if(n < 1):
            print("Please enter number grater than 0")
            return get_line_count(string)
    except:
        """when input value is string generate exception and now call get_line_count function"""
        print("Please enter number grater than 0")
        return get_line_count(string)

    return n


def input_lines(n, strings):
    print("Enter text")
    for i in range(0, n):
        """line split space"""
        words = input().split()
        tmp = []
        for j in words:
            tmp.append(j)
        strings.append(tmp)


"""Delete all simboles besides letters and numbers"""
def pars_text(strings):
    for i in range(0, len(strings)):
        for j in range(0, len(strings[i])):
            strings[i][j] = re.sub(r'[\W_]+', '', strings[i][j])


"""if word is popular add set, when line first word popular that word add other set"""
def string_set(strings, all_popular_word, line_first_popular_word):
    for i in range(0, len(strings)):
        print(i, strings[i])
        if(i == 0 and is_popular(strings[i])):
            line_first_popular_word.add(strings[i].upper())
        elif(is_popular(strings[i]) and (not strings[i].upper() in line_first_popular_word)):
            all_popular_word.add(strings[i].upper())


"""
 check word is popular?
 popular word can be all uppercase or first uppercase rest part letters: Asdf ASDF
 popular word cant be ASaa AFF4 aaa2 aaa
"""
def is_popular(string):
    if((not bool(re.search(r'\d', string))) and (string[0].isupper() and string[1:].islower() )):
        return True
    elif(not bool(re.search(r'\d', string)) and string.isupper()):
        return True
    return False


"""counting popular word repeat count """
def count_of_popular_word(popular_word_count, all_popular_words, line_first_popular_words):
    for i in all_popular_words:
        for j in i:
            if(j in popular_word_count) :
                popular_word_count[j] = popular_word_count[j] + 1
            else:
                popular_word_count[j] = 1

    for i in line_first_popular_words:
        for j in i:
            if(j in popular_word_count) :
                popular_word_count[j] = popular_word_count[j] + 1


"""print popular words"""
def print_popular_word(count , popular_word_count):
    print("\nThe Popular words is: \n")
    if(len(popular_word_count) < count):
        for i in popular_word_count:
            print(i, ":", popular_word_count[i])
    else:
        popular_word_count = sorted(popular_word_count.items(), key=lambda x: x[1], reverse=True)
        for i in range(0, count):
            print(popular_word_count[i][0], ":", popular_word_count[i][1])

def main():
    n = get_line_count("Enter Number of lines: ")

    """texts"""
    strings = []
    input_lines(n, strings)

    count = get_line_count("How many popular word du you wont find: ")
    pars_text(strings)

    """popular words"""
    line_first_popular_words = []
    all_popular_words = []
    for i in strings:
        all_popular_word = set('')
        line_first_popular_word = set('')
        string_set(i, all_popular_word, line_first_popular_word)
        line_first_popular_words.append(list(line_first_popular_word))
        all_popular_words.append(list(all_popular_word))

    """conting popular words"""
    popular_word_count = dict()
    count_of_popular_word(popular_word_count, all_popular_words, line_first_popular_words)

    """print popular words"""
    print_popular_word(count, popular_word_count)

if __name__ == "__main__":
    main()