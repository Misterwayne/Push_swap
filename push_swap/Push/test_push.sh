./push_swap

./push_swap 12222222222222222288888888 45 2 3 -7  #a gerer

./push_swap 4 4 5 6

./push_swap 1 one 2 3



echo "test 10 :"
ARG=$(ruby -e "puts (-4..5).to_a.shuffle.join(' ')")
echo $ARG | wc -w
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG


echo "\ntest 25 :"
ARG=$(ruby -e "puts (-9..10).to_a.shuffle.join(' ')")
echo $ARG | wc -w
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG


echo "\ntest 50 :"
ARG=$(ruby -e "puts (-24..25).to_a.shuffle.join(' ')")
echo $ARG | wc -w
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG

echo "\ntest 100 :"
ARG=$(ruby -e "puts (-49..50).to_a.shuffle.join(' ')")
echo $ARG | wc -w
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG

echo "\ntest 500 :"
ARG=$(ruby -e "puts (-249..250).to_a.shuffle.join(' ')")
echo $ARG | wc -w
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG

