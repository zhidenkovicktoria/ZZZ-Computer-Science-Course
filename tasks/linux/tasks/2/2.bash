 Создать файлы формата txt, в которых название - одна каждая буква латинского алфавита:
# Example: a.txt, b.txt... z.txt
for f in {a..z}; do touch ${f}.txt; done
