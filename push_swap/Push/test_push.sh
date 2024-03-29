# ./push_swap 12228888888888 45 2 3 -7  #a gerer

# ./push_swap 1 one 2 3

echo "test 3 :"
ARG=$(ruby -e "puts (-2..0).to_a.shuffle.join(' ')")
echo $ARG | wc -w
RES=$(./push_swap $ARG | wc -l);echo "$RES/3"
./push_swap $ARG | ./checker $ARG

echo "test 5 :"
ARG=$(ruby -e "puts (-4..0).to_a.shuffle.join(' ')")
echo $ARG | wc -w
RES=$(./push_swap $ARG | wc -l);echo "$RES/12"
./push_swap $ARG | ./checker $ARG

echo "test 10 :"
ARG=$(ruby -e "puts (-4..5).to_a.shuffle.join(' ')")
echo $ARG | wc -w
RES=$(./push_swap $ARG | wc -l);echo "$RES/50"
./push_swap $ARG | ./checker $ARG

echo "\ntest 20 :"
ARG=$(ruby -e "puts (-9..10).to_a.shuffle.join(' ')")
echo $ARG | wc -w
RES=$(./push_swap $ARG | wc -l);echo "$RES/200"
./push_swap $ARG | ./checker $ARG


echo "\ntest 50 :"
ARG=$(ruby -e "puts (-24..25).to_a.shuffle.join(' ')")
echo $ARG | wc -w
RES=$(./push_swap $ARG | wc -l);echo "$RES/500"
./push_swap $ARG | ./checker $ARG



echo "\ntest 500 :"
ARG=$(ruby -e "puts (-249..250).to_a.shuffle.join(' ')")
./push_swap $ARG | ./checker $ARG
RES=$(./push_swap $ARG | wc -l); 
echo "$RES/11500"

echo "\ntest 100 :"
ARG=$(ruby -e "puts (-49..50).to_a.shuffle.join(' ')") 
RES=$(./push_swap $ARG | wc -l);echo "$RES/1500" 
./push_swap $ARG  | ./checker $ARG