#!/bin/bash

echo "=== Запуск тестов для программы подсчёта символов ==="

# Тест 1: Простой текст
echo -e "Test line one\nTest line two\x18" > test1.in
echo "Тест 1"
echo "Ожидаемый результат:"
echo "3 | 2"
echo "4 | 4"
./bin/c_6 < test1.in
echo "----------------------------------------"

# Тест 2: Два коротких слова
echo -e "As\t2\x18" > test2.in
echo "Тест 2"
echo "Ожидаемый результат:"
echo "1 | 1"
echo "2 | 1"
./bin/c_6 < test2.in
echo "----------------------------------------"

# Тест 3: Длинное слово
echo -e "Aasgjhfbnahfjasnfjhasnfjasnfajkhcasfjnsajskfdncsahv\x18" > test3.in
echo "Тест 3"
echo "Ожидаемый результат:"
echo "50+ | 1"
./bin/c_6 < test3.in
echo "----------------------------------------"

# Тест 4: Длинные и короткие слова
echo -e "Aasgjhfbnahfjasnfjhasnfjasnfajkhcasfjnsajskfdncsahv next\nrow will be cut off\nfdsfsdfdsfsdfsdfsdfsdfsdfsdfsdfsdfdfsdfsdffsdfsdfdsfsd\x18" > test4.in
echo "Тест 4"
echo "Ожидаемый результат:"
echo "  2 | 1"
echo "  3 | 3"
echo "  4 | 2"
echo "50+ | 2"
./bin/c_6 < test4.in
echo "========================================"