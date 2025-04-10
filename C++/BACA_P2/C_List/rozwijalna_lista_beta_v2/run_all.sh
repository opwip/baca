#!/bin/zsh
if ! [[ -f "main.cpp" ]]; then
    echo "Plik z kodem powinien nazywać się main.cpp"
    exit 1
fi
echo -e "[\033[34mINFO\033[0m]  COMPILING main.cpp"
g++ -std=c++11 -ggdb -Wall -Wextra -Wno-comment -Wshadow -Wformat=2 -pedantic -pedantic-errors -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -o main.elf main.cpp
if [[ $? -ne 0 ]]; then
    exit 1
fi
if ! compgen -G "tests/*.in" > /dev/null; then
    echo "No test files found in tests/*.in"
    exit 1
fi
for test in tests/*.in; do
    ./main.elf < "$test" > tmp.out 2>/dev/null
    if [[ $? -ne 0 ]]; then
        echo -e "[\033[0;31mRTE\033[0m] ! ${test:6:-3}"
    elif diff tmp.out "${test%.in}.out" > /dev/null 2>&1; then
        echo -e "[\033[0;32mOK\033[0m]    ${test:6:-3}"
    else
        echo -e "[\033[0;91mANS\033[0m] ! ${test:6:-3}"
    fi
done
rm -f tmp.out main.elf