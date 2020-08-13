## To get you started you can simply clone the repository

`git clone` [https://github.com/Instigate-Training-Center-11/ITC11.git]
than `git checkout Armine_Gevorgyan`
`cd python/23.07.2020`


## About Project
This project recursive `search file or directories or both in some path`
All parametres program getting in command line when run project
All command line arguments is:


## Arguments list
`-path`: search in that path -> default: ./
`-search`: searching regex -> required
`-dir`: search in directories
`-file`: search in files
`-include`: include regex
`-exclude`: exclude regex

All parametres can be absent only `search` parametr
each parametr in command line need write -argument_name::: `example: -dir or -path`
-dir and -file do not value , its only flag
rest arguments need value, value need write in `'' brackets`::: `example: -search='^a' or -include='*aa' -exclude='.txt$'`


## ====================RUN PROJECT=============================
1) python3 search_file_dir.py -file -dir -path='./python' -search='^a' -include='*a*' -exclude='.txt$'
OR
2)python3 search_file_dir.py -search='^a'