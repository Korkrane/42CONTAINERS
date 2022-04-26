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

function pheader () {
printf "\e[0;1;94m\
# ****************************************************************************** #
#                                    MY CONTAINER TESTS                          #
#                based on https://github.com/mli42/containers_test.git	     	 #
# ****************************************************************************** #
\e[0m"
}

compile_exec () {
	# 1=file 2=define used {ft/std} 3=output_file 4=compile_log
	clang++ -Wall -Wextra -Werror -std=c++98 -o "$3" -I./$incl_path -DNAMESPACE=$2 $1 &>$4
	return $?
}

getEmoji () {
	# 1=integer
	emoji='';
	case $1 in
		0) emoji="${GREEN}✅";;
		1) emoji="${RED}❌";;
	esac
	printf "${BOLD}${emoji}${RESET}"
}

printRes () {
	# 1=file 2=result 3=normal fail compilation 4=normal diff 5=ft time 6=std time
	#echo "dans print \$1=$1 \$2=$2 \$3=$3 \$4=$4 \$5=$5 \$6=$6"
	printf "%-30s: [$5] FT <==> STD [$6]%s" \
		"$1" "$(getEmoji $2)"
	if [ $3 -ne 0 ]
	then
		printf " ${DGRAY}=> Normal fail at compilation.${RESET}"
	fi
	if [ $4 -eq 2 ]
	then
		printf " ${DGRAY}=> Normal diff with maxsize() Mac OS/Linux${RESET}"
	fi
	printf "\n"
}

isEq () {
	[ $1 -eq $2 ] && echo 0 || echo 1
}

compare_diff(){

	regex=$(cat <<- EOF
	\d+c\d+
	< max_size: \d+
	---
	> max_size: \d+
	EOF
	)

	cat $1 | grep -v -E "$regex" &>/dev/null
	[ "$?" -eq "0" ] && return 1 || return 2;
}

valid_test()
{
	#$1 = $same_output $2=$same_bin $3=$normal_diff
	if [ $1 -eq 0 ]
	then
		if [ $2 -eq 0 ]
		then
			return 0
		fi
	fi
	if [ $1 -ne 0 ] && [ $3 -eq 2 ]
	then
		return 0
	fi
	return 1
}

test () {
    logdir="logs" logdiff="diffdir" logCompil="logCompil"
    mkdir -p $logdir $logdiff $logCompil
    container=$(echo $1 | cut -d "/" -f 2)
	file=$(echo $1 | cut -d "/" -f 3)
	testname=$(echo $file | cut -d "." -f 1)
	ft_bin="ft.$container.out"; ft_log="$logdir/ft.$testname.$container.log"
	std_bin="std.$container.out"; std_log="$logdir/std.$testname.$container.log"
	std_compile_log="$logCompil/std.$testname.$container.compile.log"
    ft_compile_log="$logCompil/ft."$testname.$container.compile.log

	#compilation with namespace ft & std

	startft=$(ruby -e 'puts Time.now.to_f')
    compile_exec "$1" "ft"  "$ft_bin" $ft_compile_log ;  ft_ret=$?
	endft=$(ruby -e 'puts Time.now.to_f')
	time_ft=$(echo "$endft - $startft" | bc)

	startstd=$(ruby -e 'puts Time.now.to_f')
    compile_exec "$1" "std" "$std_bin" $std_compile_log ; std_ret=$?
	endstd=$(ruby -e 'puts Time.now.to_f')
	time_std=$(echo "$endstd - $startstd" | bc)
	##printf "Test time = $time_std s${RESET}\n"

	if [ $ft_ret  -eq $std_ret ] && [ $std_ret -ne 0 ]
	then
		normal_fail_compil=1	#error expected
	else
		normal_fail_compil=0
	fi

	if [ $ft_ret -eq 0 ]
	then
		rm -f $std_compile_log	// we rm if OK
	fi

	if [ $std_ret -eq 0 ]
	then
		rm -f $ft_compile_log 	// we rm if OK
	fi

    > $ft_log; > $std_log;
    if [ $ft_ret -eq 0 ]; then
		./$ft_bin $ft_log; ft_ret=$?
	fi
	if [ $std_ret -eq 0 ]; then
		./$std_bin $std_log; std_ret=$?
	fi
	same_bin=$(isEq $ft_ret $std_ret)
    diff_file="$logdiff/$testname.$container.diff"
	diff $std_log $ft_log 2>/dev/null 1>"$diff_file";

	if ! [ -s $diff_file ]; then
		same_output=0
		normal_diff=0
	else
		same_output=1
		compare_diff $diff_file
		normal_diff=$?
	fi

	valid_test $same_output $same_bin $normal_diff
	ok=$?

    rm -f $ft_bin $std_bin

  	printRes "$container/$file" $ok $normal_fail_compil $normal_diff $time_ft $time_std
    [ -s "$diff_file" ] || rm -f $diff_file $ft_log $std_log &>/dev/null
    rmdir  $deepdir $logdir &>/dev/null
}

do_test () {
	# 1=container_name
	test_dir="srcs/$1"
	test_files=`ls $test_dir | grep "cpp"`

	for file in ${test_files[@]}; do
		test "$test_dir/$file"
	done
}

pheader
containers=(vector map stack set)
if [ $# -ne 0 ]; then
		containers=($@);
fi
for container in ${containers[@]}; do
		printf "${BOLD}${CYAN}%40s${RESET}\n"  $container
		do_test $container 2>/dev/null
done
