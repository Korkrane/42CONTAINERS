CC="clang++ -Wall -Wextra -Werror -std=c++98"
CFLAGS="-O3"

RED="\e[91m"
GREEN="\e[92m"
RESET="\e[0m"

mkdir -p results
cd results
mkdir -p vector
mkdir -p stack
mkdir -p map
cd ..
echo -e "VECTOR TEST \t\t\t RESULTS\n"


compile_exec() {
startb=$(date +%s.%N)
$CC $CFLAGS ./$1/$2.cpp -DNAMESPACE="ft" && ./a.out > results/$1/ft.$2
endb=$(date +%s.%N)
runtimeb=$(echo $endb - $startb | bc)

starta=$(date +%s.%N)
$CC $CFLAGS $1/$2.cpp -DNAMESPACE="std" && ./a.out > results/$1/std.$2
enda=$(date +%s.%N)
runtimea=$(echo $enda - $starta | bc)

diff ./results/$1/std.$2 ./results/$1/ft.$2
ret=$?
if [ $ret -ne 0 ];then
         printf "%-30s${RED}[KO]${RESET}  TIME: FT{$($runtimeb)} STD{$runtimea}\n" \ "$2"
else
        printf "%-30s${GREEN}[OK]${RESET} TIME: FT{$runtimeb} STD{$runtimea}\n" \ "$2"
fi
}

#compile_exec "vector" "ctor";
#compile_exec "vector" "assign";
#compile_exec "vector" "at";
#compile_exec "vector" "back";
#compile_exec "vector" "capacity";
#compile_exec "vector" "clear";
#compile_exec "vector" "empty";
#compile_exec "vector" "end";
#compile_exec "vector" "erase";
#compile_exec "vector" "front";
#compile_exec "vector" "get_allocator";
#compile_exec "vector" "insert";
#compile_exec "vector" "max_size";
#compile_exec "vector" "equal_operator";
#compile_exec "vector" "bracket_operator";
#compile_exec "vector" "pop_back";
#compile_exec "vector" "push_back";
#compile_exec "vector" "rbegin";
#compile_exec "vector" "rend";
#compile_exec "vector" "reserve";
#compile_exec "vector" "resize";
#compile_exec "vector" "size";
compile_exec "vector" "ite_comp";
compile_exec "vector" "swap";
compile_exec "vector" "relational_operators";
compile_exec "vector" "swap_2";

echo -e "\nSTACK TEST \t\t\t RESULTS\n"
#compile_exec "stack" "empty";
#compile_exec "stack" "size";
#compile_exec "stack" "top";
#compile_exec "stack" "push";
#compile_exec "stack" "pop";
#compile_exec "stack" "relational_operators";

echo -e "\nMAP TEST \t\t\t RESULTS\n"
compile_exec "map" "crash";
compile_exec "map" "ctor";
compile_exec "map" "begin";
compile_exec "map" "clear";
compile_exec "map" "count";
compile_exec "map" "empty";
compile_exec "map" "end";
compile_exec "map" "equal_range";
compile_exec "map" "erase";
compile_exec "map" "find";
compile_exec "map" "get_allocator";
compile_exec "map" "insert";
compile_exec "map" "key_comp";
compile_exec "map" "lower_bound";
compile_exec "map" "max_size";
compile_exec "map" "equal_operator";
compile_exec "map" "bracket_operator";
compile_exec "map" "rbegin";
compile_exec "map" "rend";
compile_exec "map" "size";
compile_exec "map" "swap";
compile_exec "map" "upper_bound";
compile_exec "map" "value_comp";
compile_exec "map" "relational_operators";
compile_exec "map" "swap_2";

rm a.out