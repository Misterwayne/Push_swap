echo "test 10 :"
ARG=$(ruby -e "puts (-4..5).to_a.shuffle.join(' ')")
echo $ARG | wc -w
./push_swap $ARG | wc -l

echo "\ntest 25 :"
ARG=$(ruby -e "puts (-9..10).to_a.shuffle.join(' ')")
echo $ARG | wc -w
./push_swap $ARG | wc -l

echo "\ntest 50 :"
ARG=$(ruby -e "puts (-24..25).to_a.shuffle.join(' ')")
echo $ARG | wc -w
./push_swap $ARG | wc -l
echo "\ntest 100 :"
ARG=$(ruby -e "puts (-49..50).to_a.shuffle.join(' ')")
echo $ARG | wc -w
./push_swap $ARG | wc -l
echo "\ntest 500 :"
ARG=$(ruby -e "puts (-249..250).to_a.shuffle.join(' ')")
echo $ARG | wc -w
./push_swap $ARG | wc -l
