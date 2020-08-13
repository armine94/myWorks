import argparse
import os
import re

"""adding  arguments expected from the command line"""
"""-path: search in that path"""
"""-search: searching regex"""
"""-dir: search in directories"""
"""-file: search in files"""
"""-include: include regex"""
"""-exclude: exclude regex"""
"""return comand line argument list(args)"""
def add_arguments():
    parser = argparse.ArgumentParser()
    parser.add_argument("-dir", "--dir_name", help="search in directory", action="store_true")
    parser.add_argument("-file", "--file_name", help="search in files", action="store_true")
    parser.add_argument("-include", "--include", help="include file", default="")
    parser.add_argument("-exclude", "--exclude", help="exclude file", default="")
    parser.add_argument("-path", "--path", help="searching path", default="./")
    parser.add_argument("-search", "--search", help="search")
    args = parser.parse_args()

    return args

"""this function in the first checking what need searching(files or directories or both)"""
"""than call searching function for files/directories or both using searching regex"""
"""than resalt parsing using include and exclude regexes"""
"""in the end finally result print in console"""
def search_in_path(args):
    """find all directores on some path"""
    if(args.dir_name):
        result = find(1, args.path)
        result = parse_search(args.search, result)
        result = parse_include_exclude(result, args.include, args.exclude)
        print_all(result, 1, args.path)

    """find all files on some path"""
    if(args.file_name):
        result = find(2, args.path)
        result = parse_search(args.search, result)
        result = parse_include_exclude(result, args.include, args.exclude)
        print_all(result, 2, args.path)

    """find all files and directores on some path"""
    if(not args.file_name and not args.dir_name):
        result1 = find(1, args.path)
        result1 = parse_search(args.search, result1)
        result2 = find(2, args.path)
        result2 = parse_search(args.search, result2)
        result1 =  parse_include_exclude(result1, args.include, args.exclude)
        result2 =  parse_include_exclude(result2, args.include, args.exclude)
        print_all(result1, 1, args.path)
        print_all(result2, 2, args.path)


"""find in some path directories or files"""
"""when index = 1 find directories"""
"""when index == 2 find files"""
def find(index, path):
    try:
        result = []
        for i in os.walk(path):
            if(len(i[index]) > 0):
                result.append(i[index])

        return result
    except:
        print("No such file or directory: ", path)


"""All finding dir/file parse using search regex"""
def parse_search(search, result):
    parse_result = []
    for i in result:
        for j in i:
            if(re.search(search, j)):
                parse_result.append(j)
    return parse_result


"""parse using include and exclude regex, when its exists"""
def parse_include_exclude(res, include, exclude):
    includes = []
    flag = False
    if(include):
        flag = True
        for i in res:
            if(re.search(include, i)):
                includes.append(i)
    finally_result = []
    if(exclude):
        flag = True
        for i in includes:
            if(not re.search(exclude, i)):
                finally_result.append(i)
        include = finally_result

    """if include and exclude regex not exists return old result"""
    if(flag == True):
        return includes
    else:
        return res


def print_all(result, flag, path):
    if(len(result) == 0):
        print("Nothing found:")
        return
    elif(flag == 1):
        print("All finding directores in", path, "path: ")
    elif(flag == 2):
        print("All finding files in", path, "path: ")

    for i in result:
        print(i)


def main():
    args = add_arguments()
    search_in_path(args)


if __name__ == "__main__":
    main()