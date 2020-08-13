""" the function get lines number
    return line number
"""
def get_line_count():
    try:
        """try cast input value in int"""
        n = int(input("Enter Number of lines: "))

        if(n < 1):
            print("Incorrect input: Please try again: enter number grater than 0")
            return get_line_count()
        else:
            return n
    except:
        """when input value is string generate exception"""
        print("Incorrect input: Please try again: enter number grater than 0")
        return get_line_count()


def input_lines(n, texts):
    print("\nEnter the lines as shown in the example: \nExample1: a1 df ki   \nExample2: a24 584 778\n")
    for i in range(0, n):
        print("Enter", i + 1, "th line: ", end = "")
        line = input()
        texts.append(line)

"""check type of line: number or string"""
def type_of_line(line):
    return line[1].isnumeric()


"""texts(all list) strings list division a sublist: numbers list and strings list"""
def sub_lists(texts, numbers, strings):
    for i in texts:
        words = i.split()
        if(type_of_line(words)):
            numbers.append(words)
        else:
            strings.append(words)


"""sort string list
first sort by key: key1 > key2 when
1) length(key1) > length(key2)
2) length(key1) == length(key2) , than compare kay string part asd1 and as12 => ass2 grater than as12
if key1 == key2 sort by 2th column
1) length(col1) > length(col2)
2) length(col1) == length(col2) , than copmare string col1 > col2
if col1 == col2 than sort by 3td column since by sort 2th column
"""
def sort_strings(strings):
    for i in range(0, len(strings)):
        for j in range(0, len(strings) - i - 1):
            if(pars_key(strings[j][0], strings[j + 1][0])):
                string_swap(strings, j , j+1)
            elif(compare_string(strings[j][1], strings[j + 1][1]) and strings[j][0] == strings[j + 1][0]):
                string_swap(strings, j , j + 1)
            elif(compare_string(strings[j][2], strings[j + 1][2]) and strings[j][1] == strings[j + 1][1]):
                string_swap(strings, j , j + 1)


"""swap two string lines"""
def string_swap(strings, i, j):
    tmp = strings[i]
    strings[i] = strings[j]
    strings[j] = tmp

"""sort by key: key1 > key2 when
1) length(key1) > length(key2) retrun True
2) length(key1) == length(key2) , than compare kay string part asd1 and as12 => ass2 grater than as12 return True
3) else: return False
"""
def pars_key(key1, key2):
    if(len(key1) > len(key2)):
        return True
    elif(len(key1) == len(key2) and string_from_key(key1) >  string_from_key(key2)):
        return True

    return False


"""if key1 == key2/(col1 == col2) sort by column
1) length(col1) > length(col2) return True
2) length(col1) == length(col2) , than copmare string col1 > col2 return True
3)else: return False
"""
def compare_string(key1, key2):
    if(len(key1) > len(key2)):
        return True
    elif(len(key1) == len(key2) and key1 > key2):
        return True

    return False


"""retrun only letters: asdf456 return asdf"""
def string_from_key(key):
    str1 = ""
    for i in range(0, len(key)):
        if(not key[i].isdigit()):
            str1 = str1 + key[i]
    return str1


"""sort numbers list
first sort by key
if key1 == key2
sort by 2th column
if 2rt column is equal than
sort bay 3th column
"""
def sort_numbers(numbers):
    for i in range(0, len(numbers)):
        for j in range(0, len(numbers) - i - 1):
            if(pars_key(numbers[j][0], numbers[j + 1][0])):
                number_swap(numbers, j, j + 1)
            elif(compare_number(numbers[j][1], numbers[j + 1][1])):
                number_swap(numbers, j, j + 1)
            elif(compare_number(numbers[j][2], numbers[j + 1][2]) and numbers[j][1] == numbers[j + 1][1]):
                number_swap(numbers, j, j + 1)


"""copare two number, if num1 grater num2 return True else return False"""
def compare_number(num1, num2):
    return int(num1) > int(num2)


"""swap two number lines"""
def number_swap(numbers, i, j):
    tmp = numbers[i]
    numbers[i] = numbers[j]
    numbers[j] = tmp


"""Print Sorting List"""
def printList(strings, numbers):
    print("\n==================Sorting List====================")
    for i in strings:
        for j in i:
            print(j, " ", end = "",)
        print()

    for i in numbers:
        for j in i:
            print(j, " ", end = "")
        print()

def main():
    """Line Number"""
    n = get_line_count()

    """Unsorted Text"""
    texts = []
    input_lines(n, texts)

    numbers = []
    strings = []
    """Seperate strings list and numbers strings"""
    sub_lists(texts, numbers, strings)

    """Sort list of strings"""
    sort_strings(strings)

    """Sort list of numbers"""
    sort_numbers(numbers)

    """Print Sorting List"""
    printList(strings, numbers)


if __name__ == "__main__":
    main()