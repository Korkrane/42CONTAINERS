# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    time_tester.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 09:20:38 by clorin            #+#    #+#              #
#    Updated: 2021/12/04 11:54:20 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

RESET="\e[0m"
BOLD="\e[1m"
RED="\e[91m"
GREEN="\e[92m"
YELLOW="\e[93m"
DBLUE="\e[94m"
PURPLE="\e[95m"
CYAN="\e[96m"
DGREY="\e[1;90m"

if [ -z "$1" ]
then
    seed_=42
else
    seed_=$1
fi
#compilation of given main with stl and ft containers
clang++ -Wall -Wextra -Werror -o ft.out srcs/main.cpp -D NAMESPACE=ft
clang++ -Wall -Wextra -Werror -o stl.out srcs/main.cpp

#time for stl containers
printf "${CYAN}"
echo "   _____________ "
echo "  / ___/_  __/ / "
echo "  \__ \ / / / /  "
echo " ___/ // / / /___"
echo "/____//_/ /_____/ container's"
echo "                 "

start=$(ruby -e 'puts Time.now.to_f')
./stl.out $seed_ > stl.log
end=$(ruby -e 'puts Time.now.to_f')
time_stl=$(echo "$end - $start" | bc)

printf "Test time = $time_stl s${RESET}\n"

#time for ft containers
printf "${YELLOW}"
echo "    ____________"
echo "   / ____/_  __/"
echo "  / /_    / /   "
echo " / __/   / /    "
echo "/_/     /_/     container's"
echo "                "
start=$(ruby -e 'puts Time.now.to_f')
./ft.out $seed_ > ft.log
end=$(ruby -e 'puts Time.now.to_f')
time_ft=$(echo "$end - $start" | bc)

printf "Test time = $time_ft s${RESET}\n"

x=$(echo "scale=3; $time_ft / $time_stl" | bc)
x_int=$(echo "scale=0; $time_ft / $time_stl" | bc)
printf "${BOLD}"
if [ $x_int -le "20" ]
then
    printf ${GREEN}
else
    printf ${RED}
fi
diff stl.log ft.log 2>/dev/null 1>diff_file;
printf "\nFactor x = Time_FT / Time_std = $x${RESET}\n"
if ! [ -s diff_file ]; then
    printf "${GREEN}Output OK\n${RESET}"
else
    printf "${RED}Output KO\n${RESET}"
fi
rm -rf ft.out stl.out ft.log stl.log diff_file