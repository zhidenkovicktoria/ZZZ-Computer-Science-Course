 Выведите топ 7 самых тяжёлых файлов в диапазоне от 1 до 100 МВ
 find -maxdepth 1 -size +1M -size -100M -type f -printf "%k %p\n" | sort -rn | head -n 7
