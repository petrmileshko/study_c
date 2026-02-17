# Язык Си

## Настройка среды для сборки

 1. Установить редактор VS Code, и расширения C/C++, C/C++ Extension Pack, CMake Tools, Code Runner, EditorConfig, Git History.
 2. Скачать и установить MSYS2 с [официального сайта](https://www.msys2.org/).
 3. Обновить пакетный менеджер и базовые пакеты. После установки запустить терминал MSYS2 и выполнить команду:
            pacman -Su
 4. Установить компилятор. В терминале MSYS2 выполнить команду:
            pacman -S mingw-w64-ucrt-x86_64-gcc
 5. Установить сборщик Make. В терминале MSYS2 выполнить команду:
            pacman -S make
 6. В переменную среды PATH добавить путь к компилятору gcc и сборщику make.
---
## Примеры и задачи

* [Урок 1](https://github.com/petrmileshko/study_c/tree/main/c_1)

* [Урок 2](https://github.com/petrmileshko/study_c/tree/main/с_2)