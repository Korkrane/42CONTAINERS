CC="clang++"
CFLAGS="-O3"
EOC="\033[0m"
BOLD="\033[1;37m"
RED="\033[0;31m"
GREEN="\032[0;31m"
YELLOW="\133[0;31m"

mkdir -p results
cd results
mkdir -p vector
mkdir -p stack
cd ..
echo -e "VECTOR TEST \t\t\t RESULTS\n"
$CC $CFLAGS vector/ctor.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/assign.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/at.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/back.cpp  && ./a.out && sleep 0.25
$CC $CFLAGS vector/begin.cpp 2>&1 && ./a.out && sleep 0.25
$CC $CFLAGS vector/capacity.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/clear.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/empty.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/end.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/erase.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/front.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/get_allocator.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/insert.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/max_size.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/equal_operator.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/bracket_operator.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/pop_back.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/push_back.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/rbegin.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/rend.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/reserve.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/resize.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/size.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/swap.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/relational_operators.cpp && ./a.out && sleep 0.25
$CC $CFLAGS vector/swap_2.cpp && ./a.out && sleep 0.25

echo -e "\nSTACK TEST \t\t\t RESULTS\n"
$CC $CFLAGS stack/empty.cpp && ./a.out && sleep 0.25
$CC $CFLAGS stack/size.cpp && ./a.out && sleep 0.25
$CC $CFLAGS stack/top.cpp && ./a.out && sleep 0.25
$CC $CFLAGS stack/push.cpp && ./a.out && sleep 0.25
$CC $CFLAGS stack/pop.cpp && ./a.out && sleep 0.25
$CC $CFLAGS stack/relational_operators.cpp && ./a.out && sleep 0.25